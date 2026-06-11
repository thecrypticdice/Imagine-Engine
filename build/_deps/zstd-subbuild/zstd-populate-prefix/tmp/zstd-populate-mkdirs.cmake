# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/zstd/dfd2e0b6e613dcf44911302708e636a8aee527d2")
  file(MAKE_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/zstd/dfd2e0b6e613dcf44911302708e636a8aee527d2")
endif()
file(MAKE_DIRECTORY
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-build"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/tmp"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src"
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
