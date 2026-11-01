cmake_minimum_required(VERSION 3.16)
project(flappy_bird LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use a system SFML 2.6 if present, otherwise download and build it.
find_package(SFML 2.6 COMPONENTS graphics window system QUIET)
if(NOT SFML_FOUND)
    message(STATUS "SFML 2.6 not found, fetching it with FetchContent")
    include(FetchContent)
    set(BUILD_SHARED_LIBS OFF)
    set(SFML_BUILD_AUDIO OFF)
    set(SFML_BUILD_NETWORK OFF)
    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
        GIT_SHALLOW ON)
    FetchContent_MakeAvailable(SFML)
endif()

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(flappy_bird ${SOURCES})
target_link_libraries(flappy_bird PRIVATE sfml-graphics sfml-window sfml-system)

find_package(Threads REQUIRED)
target_link_libraries(flappy_bird PRIVATE Threads::Threads)

# Copy assets next to the executable so it runs from the build folder.
add_custom_command(TARGET flappy_bird POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:flappy_bird>/assets)

set_property(TARGET flappy_bird PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:flappy_bird>)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT flappy_bird)
