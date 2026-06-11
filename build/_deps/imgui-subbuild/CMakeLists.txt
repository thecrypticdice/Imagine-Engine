# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 4.3.3)

# Reject any attempt to use a toolchain file. We must not use one because
# we could be downloading it here. If the CMAKE_TOOLCHAIN_FILE environment
# variable is set, the cache variable will have been initialized from it.
unset(CMAKE_TOOLCHAIN_FILE CACHE)
unset(ENV{CMAKE_TOOLCHAIN_FILE})

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(imgui-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[/usr/bin/git]==])
set(Git_VERSION [==[2.54.0]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[/usr/bin/git;2.54.0]==]
)


include(ExternalProject)
ExternalProject_Add(imgui-populate
                     "GIT_REPOSITORY" "https://github.com/ocornut/imgui.git" "GIT_TAG" "v1.92.8-docking" "PATCH_COMMAND" "/usr/bin/patch" "-p1" "<" "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/3rdParty/tracy/cmake/imgui-emscripten.patch" "&&" "/usr/bin/patch" "-p1" "<" "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/3rdParty/tracy/cmake/imgui-loader.patch" "GIT_SHALLOW" "TRUE"
                    SOURCE_DIR          "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/imgui/91accc144fa956b772432ed942ca36d712a0f767"
                    BINARY_DIR          "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


