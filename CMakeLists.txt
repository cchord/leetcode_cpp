cmake_minimum_required(VERSION 3.5)
project(leetcode_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(ROOT ${PROJECT_SOURCE_DIR})

set(subdirs array others tree hash_table sort two_pointers dynamic_programming)

foreach(dir ${subdirs})
    add_subdirectory(${dir})
endforeach(dir ${subdirs})
