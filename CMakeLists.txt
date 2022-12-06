cmake_minimum_required(VERSION 3.14)

project("some assignment")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # generate compile_commands.json for IDEs
set(CMAKE_CXX_STANDARD 17)

# Setting -ggdb3 gets line numbers in Valgrind output
# -Og is the recommended level of optimization from the GCC docs for "the standard edit-compile-debug" cycle
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 -Og")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake) # make sure we know where to find the doctest header

find_package(Doctest REQUIRED)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)
include(cmake/Valgrind.cmake)

# Use include(CTest) rather than enable_testing() to get Valgrind working
include(CTest)
