cmake_minimum_required(VERSION 3.12)

project(CAlgoLibrary C)

set(CMAKE_C_STANDARD 11)

file(GLOB sources "source/*.c")
add_library(calgo STATIC ${sources})
target_include_directories(calgo PUBLIC include)
target_compile_options(calgo PRIVATE -Werror -Wall)

add_subdirectory(tests)
