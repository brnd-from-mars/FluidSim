cmake_minimum_required(VERSION 3.5)
project(FluidSim)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)
endif()

# TODO: Outsource sfml to graphics component
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_subdirectory(Utility)
add_subdirectory(Geometry)
add_subdirectory(Graphics)

add_executable(FluidSim FluidSim.cpp)
target_link_libraries(FluidSim sfml-graphics Utility Geometry Graphics)
