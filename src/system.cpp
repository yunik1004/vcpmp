#include "system.hpp"
#include <iostream>

#define ARCH_X86 "x86"
#define ARCH_X64 "x64"
#define ARCH_ARM "arm"
#define ARCH_ARM64 "arm64"

#define OS_WINDOWS "windows"
#define OS_LINUX "linux"
#define OS_DARWIN "osx"

#define LINK_DYNAMIC "dynamic"
#define LINK_STATIC "static"

std::string VCPMP::ToStr(VCPMP::ARCH arch) {
    switch (arch) {
        case VCPMP::ARCH::X86: return ARCH_X86;
        case VCPMP::ARCH::X64: return ARCH_X64;
        case VCPMP::ARCH::ARM: return ARCH_ARM;
        case VCPMP::ARCH::ARM64: return ARCH_ARM64;
    }

    exit(EXIT_FAILURE);
}

std::string VCPMP::ToStr(VCPMP::OS os) {
    switch (os) {
        case VCPMP::OS::WINDOWS: return OS_WINDOWS;
        case VCPMP::OS::LINUX: return OS_LINUX;
        case VCPMP::OS::DARWIN: return OS_DARWIN;
    }

    exit(EXIT_FAILURE);
}

VCPMP::ARCH VCPMP::StrToARCH(std::string str) {
    if (str.compare(ARCH_X86) == 0) {
        return VCPMP::ARCH::X86;
    } else if (str.compare(ARCH_X64) == 0) {
        return VCPMP::ARCH::X64;
    } else if (str.compare(ARCH_ARM) == 0) {
        return VCPMP::ARCH::ARM;
    } else if (str.compare(ARCH_ARM64) == 0) {
        return VCPMP::ARCH::ARM64;
    }

    return VCPMP::ARCH::ERROR;
}

VCPMP::LINK VCPMP::StrToLINK(std::string str) {
    if (str.compare(LINK_DYNAMIC) == 0) {
        return VCPMP::LINK::DYNAMIC;
    } else if (str.compare(LINK_STATIC) == 0) {
        return VCPMP::LINK::STATIC;
    }

    return VCPMP::LINK::ERROR;
}

VCPMP::OS VCPMP::getOS() {
    return VCPMP::OS::WINDOWS;
}

std::string VCPMP::getOS_str() {
    return VCPMP::ToStr(VCPMP::getOS());
}
