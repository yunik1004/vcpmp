cmake_minimum_required (VERSION 3.9)

# Project settings
project ("vcpmp")
set (VCPMP_APP_TARGET vcpmp)

# CMAKE settings
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_C_STANDARD_COMPUTED_DEFAULT 11)
set (CMAKE_CXX_STANDARD_COMPUTED_DEFAULT 17)

# submodules
set (VCPMP_SUBMODULES_DIR ${PROJECT_SOURCE_DIR}/submodules)

# cxxopts
add_subdirectory(${VCPMP_SUBMODULES_DIR}/cxxopts cxxopts EXCLUDE_FROM_ALL)

# yaml-cpp
add_subdirectory(${VCPMP_SUBMODULES_DIR}/yaml-cpp yaml-cpp EXCLUDE_FROM_ALL)

# Add source to this project's executable.
file (GLOB_RECURSE VCPMP_CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file (GLOB_RECURSE VCPMP_HPP_FILES ${PROJECT_SOURCE_DIR}/src/*.hpp)

add_executable (${VCPMP_APP_TARGET}
    ${VCPMP_CPP_FILES}
    ${VCPMP_HPP_FILES}
)

target_link_libraries(${VCPMP_APP_TARGET}
    cxxopts
    yaml-cpp
)
