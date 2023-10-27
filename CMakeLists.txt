cmake_minimum_required(VERSION 3.25)
project(project_cpp)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(project_cpp main.cpp algorithm/Djikstra.cpp algorithm/Djikstra.h grid/Grid.cpp grid/Grid.h constants.h)

target_link_libraries(project_cpp sfml-graphics sfml-window)
