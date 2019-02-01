#pragma once

#include <string>

namespace VCPMP {
    enum class ARCH {
        X86,
        X64,
        ARM,
        ARM64,
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

    ARCH StrToARCH(std::string str);
    LINK StrToLINK(std::string str);

    OS getOS();
    std::string getOS_str();
}
