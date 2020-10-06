# Copyright (c) 2020 Egor Kupaev
# This work is distributed under the Apache-2.0 License
# See the accompanying LICENSE file or http://www.apache.org/licenses/

cmake_minimum_required(VERSION 3.12)

project(CalgoTests CXX)

set(CMAKE_CXX_STANDARD 20)

# Fetch GoogleTest framework
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0
)
FetchContent_MakeAvailable(googletest)

file(GLOB sources "source/*.cpp")
add_executable(tests ${sources})
target_link_libraries(tests calgo gtest gtest_main)
target_compile_options(tests PRIVATE -Werror -Wall)

enable_testing()
add_test(NAME tests COMMAND tests)