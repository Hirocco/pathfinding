cmake_minimum_required(VERSION 3.25)
project(cpp_project)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_project main.cpp)

target_link_libraries(cpp_project sfml-graphics sfml-window)