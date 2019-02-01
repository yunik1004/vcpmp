#pragma once

#include <string>

namespace VCPMP {
    enum class ARCH {
        X86,
        X64,
        ARM,
        ARM64,
        CURRENT,
        ERROR // Error
    };

    enum class OS {
        WINDOWS,
        LINUX,
        DARWIN
    };

    enum class LINK {
        DYNAMIC,
        STATIC,
        ERROR // Error
    };

    std::string ToStr(ARCH arch);
    std::string ToStr(OS os);
    std::string ToStr(LINK link);

    ARCH StrToARCH(std::string str);
    LINK StrToLINK(std::string str);

    ARCH getArch();

    OS getOS();

    void install_vcpkg_library(const char* vcpkg_root, std::string name, ARCH arch, LINK link);
}
