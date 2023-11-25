cmake_minimum_required(VERSION 3.12o)
project(Collision-Simulation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cc src/Point.cc)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(simulation ${SOURCE_FILES})

target_link_libraries(simulation PRIVATE sfml-graphics sfml-window sfml-system)


