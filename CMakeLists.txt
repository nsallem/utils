cmake_minimum_required(VERSION 3.22)

project(utils)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PCL REQUIRED COMPONENTS io console)

add_definitions(${PCL_DEFINITIONS})

include_directories(${PCL_INCLUDE_DIRS})

add_executable(generate_plane generate_plane.cc)
target_link_libraries(generate_plane ${PCL_LIBRARIES})
