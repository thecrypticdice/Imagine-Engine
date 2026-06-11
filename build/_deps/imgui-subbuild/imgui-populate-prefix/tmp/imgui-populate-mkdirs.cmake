# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/imgui/91accc144fa956b772432ed942ca36d712a0f767")
  file(MAKE_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/imgui/91accc144fa956b772432ed942ca36d712a0f767")
endif()
file(MAKE_DIRECTORY
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-build"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-subbuild/imgui-populate-prefix"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-subbuild/imgui-populate-prefix/src"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
