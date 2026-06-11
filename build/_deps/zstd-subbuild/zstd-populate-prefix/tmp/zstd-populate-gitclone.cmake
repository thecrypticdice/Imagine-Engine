# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

if(EXISTS "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/zstd-populate-gitclone-lastrun.txt" AND EXISTS "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/zstd-populate-gitinfo.txt" AND
  "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/zstd-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/zstd-populate-gitinfo.txt")
  message(VERBOSE
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/zstd-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

# Even at VERBOSE level, we don't want to see the commands executed, but
# enabling them to be shown for DEBUG may be useful to help diagnose problems.
cmake_language(GET_MESSAGE_LOG_LEVEL active_log_level)
if(active_log_level MATCHES "DEBUG|TRACE")
  set(maybe_show_command COMMAND_ECHO STDOUT)
else()
  set(maybe_show_command "")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/zstd/dfd2e0b6e613dcf44911302708e636a8aee527d2"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/zstd/dfd2e0b6e613dcf44911302708e636a8aee527d2'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"
            clone --no-checkout --depth 1 --no-single-branch --config "advice.detachedHead=false" "https://github.com/facebook/zstd.git" "dfd2e0b6e613dcf44911302708e636a8aee527d2"
    WORKING_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/zstd"
    RESULT_VARIABLE error_code
    ${maybe_show_command}
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(NOTICE "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/facebook/zstd.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"
          checkout "v1.5.7" --
  WORKING_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/zstd/dfd2e0b6e613dcf44911302708e636a8aee527d2"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v1.5.7'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/zstd/dfd2e0b6e613dcf44911302708e636a8aee527d2"
    RESULT_VARIABLE error_code
    ${maybe_show_command}
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/3rdParty/tracy/profiler/.cpm-cache/zstd/dfd2e0b6e613dcf44911302708e636a8aee527d2'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/zstd-populate-gitinfo.txt" "/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/zstd-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/build/_deps/zstd-subbuild/zstd-populate-prefix/src/zstd-populate-stamp/zstd-populate-gitclone-lastrun.txt'")
endif()
