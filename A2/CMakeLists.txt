# After modifying this file, make sure you reload the CMake Project (right-click CMakeLists.txt and click Reload CMake Project.)
cmake_minimum_required(VERSION 3.5)
project(A2)

set(CMAKE_CXX_STANDARD 11)

# Do not modify these flags other than changing -ggdb to -O2 and back.
# Debugging build:
set(CMAKE_CXX_FLAGS "-ggdb -std=c++11 -Wall -Werror=uninitialized -Werror=maybe-uninitialized -Winit-self -Wredundant-decls -Werror=return-type")
# Optimization build:
# set(CMAKE_CXX_FLAGS "-O2 -std=c++11 -Wall -Werror=uninitialized -Werror=maybe-uninitialized -Winit-self -Wredundant-decls")

# Compile your class code into object code.
add_library(vNode-obj OBJECT code/vNode.hpp)
# Compile the main code into object code to avoid rebuilding every
# time you update your class code.
add_library(LinkedVector-obj OBJECT code/LinkedVector.hpp)

# Build an executable using the main function and the object code for your class.
add_executable(a2 code/main.cpp $<TARGET_OBJECTS:vNode-obj> $<TARGET_OBJECTS:LinkedVector-obj>)
