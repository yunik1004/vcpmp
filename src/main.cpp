#include <iostream>
#include <string>
#include <cxxopts.hpp>
#include <yaml-cpp/yaml.h>
#include "system.hpp"

#define VCPKG_ROOT "VCPKG_ROOT"
#define VCPKG_CONFIG_FILE "vcpkg.config.yaml"

cxxopts::ParseResult parse_opts(int argc, char* argv[]) {
    try {
        cxxopts::Options options(argv[0], " - Command line options");
        options
            .positional_help("[optional args]")
            .show_positional_help();
        options.add_options()
            ("h,help", "Print help and exit.")
            ("i,install", "Install vcpkg libraries.")
            ;
        auto result = options.parse(argc, argv);

        if (result.count("h")) {
            std::cout << options.help() << std::endl;
            exit(EXIT_SUCCESS);
        }

        return result;
    } catch (const cxxopts::OptionException& e) {
        std::cerr << "Error parsing options: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void parse_yaml (const char* vcpkg_root) {
    try {
        const YAML::Node& config = YAML::LoadFile(VCPKG_CONFIG_FILE);

        VCPMP::ARCH arch_default;
        VCPMP::LINK link_default;

        if (config["default"]) {
            if (config["default"]["arch"]) { // "x86", "x64", "arm", or "arm64"
                arch_default = VCPMP::StrToARCH(config["default"]["arch"].as<std::string>());
                if (arch_default == VCPMP::ARCH::ERROR) {
                    std::cerr << "Error parsing " << VCPKG_CONFIG_FILE << ": wrong default architecture" << std::endl;
                    exit(EXIT_FAILURE);
                }
            } else {
                switch (VCPMP::getOS()) {
                    case VCPMP::OS::WINDOWS:
                        arch_default = VCPMP::ARCH::X86;
                        break;
                    default:
                        arch_default = VCPMP::ARCH::X64;
                        break;
                }
            }

            if (config["default"]["link"]) { // "static" or "dynamic"
                link_default = VCPMP::StrToLINK(config["default"]["link"].as<std::string>());
                if (link_default == VCPMP::LINK::ERROR) {
                    std::cerr << "Error parsing " << VCPKG_CONFIG_FILE << ": wrong default link configuration" << std::endl;
                    exit(EXIT_FAILURE);
                }
            } else {
                link_default = VCPMP::LINK::DYNAMIC;
            }
        }

        const YAML::Node& libraries = config["library"];
        for(YAML::const_iterator it = libraries.begin(); it != libraries.end(); ++it) {
            std::string lib_name = it->first.as<std::string>();

            VCPMP::ARCH lib_arch;
            VCPMP::LINK lib_link;

            if (it->second["arch"]) {
                lib_arch = VCPMP::StrToARCH(it->second["arch"].as<std::string>());
                if (lib_arch == VCPMP::ARCH::ERROR) {
                    std::cerr << "Error parsing " << VCPKG_CONFIG_FILE << ": wrong architecture" << std::endl;
                    exit(EXIT_FAILURE);
                }
            } else {
                lib_arch = arch_default;
            }

            if (it->second["link"]) {
                lib_link = VCPMP::StrToLINK(it->second["link"].as<std::string>());
                if (lib_link == VCPMP::LINK::ERROR) {
                    std::cerr << "Error parsing " << VCPKG_CONFIG_FILE << ": wrong link configuration" << std::endl;
                    exit(EXIT_FAILURE);
                }
            } else {
                lib_link = link_default;
            }

            VCPMP::install_vcpkg_library(vcpkg_root, lib_arch, lib_link);
        }
    } catch (const YAML::BadFile& e) {
        std::cerr << "Error loading " << VCPKG_CONFIG_FILE << ": " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    } catch (const YAML::ParserException& e) {
        std::cerr << "Error parsing " << VCPKG_CONFIG_FILE << ": wrong structured file" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    auto result = parse_opts(argc, argv);

    const char* vcpkg_root = getenv(VCPKG_ROOT);
    if (vcpkg_root == nullptr) {
        std::cerr << "Error: you need to set '" << VCPKG_ROOT << "' environment variable" << std::endl;
        return EXIT_FAILURE;
    }

    if (result.count("i")) {
        parse_yaml(vcpkg_root);
    }

    return EXIT_SUCCESS;
}
