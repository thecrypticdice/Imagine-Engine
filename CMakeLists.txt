cmake_minimum_required(VERSION 3.10)

project(imagine_engine)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(./3rdParty/raylib)
option(TRACY_BUILD_SERVER "Build the Tracy Profiler GUI" ON)
if(TRACY_BUILD_SERVER)
    # This subdirectory has its own CMakeLists.txt that builds the UI
    add_subdirectory(./3rdParty/tracy/profiler)
endif()
option(TRACY_ENABLE "Enable Tracy Profiling" ON)
add_compile_definitions(TRACY_ENABLE)
add_subdirectory(./3rdParty/tracy)

file(Engine SOURCES "engine/*.cpp")
file(editor SOURCES "editor/*.cpp")
file(runtime SOURCES "runtime/*.cpp")

add_library(Imagine_Engine ${Engine})
target_include_directories(Imagine_Engine PUBLIC ./Engine/)
target_include_directories(Imagine_Engine PUBLIC ./3rdParty/raygui/src/raygui.h)
target_include_directories(Imagine_Engine PUBLIC ./3rdParty/tracy/public/)
target_link_libraries(Imagine_Engine  raylib)
target_link_libraries(Imagine_Engine  TracyClient)

add_executable(imagine_engine_editor ${editor})
target_include_directories(imagine_engine_editor PUBLIC ./editor/)
target_link_libraries(imagine_engine_editor Imagine_Engine)

add_executable(imagine_engine_runtime ${runtime})
target_include_directories(imagine_engine_runtime PUBLIC ./runtime/)
target_link_libraries(imagine_engine_runtime Imagine_Engine)
