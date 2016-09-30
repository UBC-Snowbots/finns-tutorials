cmake_minimum_required(VERSION 3.4)

project(testing CXX)

# define a library foo with a simple function to test
add_library(foo foo.cpp)
target_include_directories(foo PUBLIC .)

# important - doesn't work without this
enable_testing()

# tests are just like other executables really...
add_executable(tests tests.cpp)
target_link_libraries(tests foo)

# COMMAND can be any command,
#  you can pass options and arguments as needed.
add_test(NAME tests COMMAND tests)
