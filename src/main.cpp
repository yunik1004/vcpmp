#include <iostream>
#include <cxxopts.hpp>

cxxopts::ParseResult parse(int argc, char* argv[]) {
    try {
        cxxopts::Options options(argv[0], " - Command line options");
        options
            .positional_help("[optional args]")
            .show_positional_help();
        options.add_options()
            ("h,help", "Print help and exit.")
            ;
        auto result = options.parse(argc, argv);

        if (result.count("h")) {
            std::cout << options.help() << std::endl;
            exit(EXIT_SUCCESS);
        }

        return result;
    } catch (const cxxopts::OptionException& e) {
        std::cout << "Error parsing options: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    auto result = parse(argc, argv);
    auto arguments = result.arguments();

    return EXIT_SUCCESS;
}
