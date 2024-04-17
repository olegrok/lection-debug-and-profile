cmake_minimum_required(VERSION 3.10)
project(stack)

option(ENABLE_ASAN OFF)
option(BUILD_BENCHMARKS ON)

include(FetchContent)

FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG main)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark
        GIT_TAG main)

FetchContent_MakeAvailable(googletest googlebenchmark)

if(ENABLE_ASAN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif()

add_library(stack stack.c)
if(ENABLE_GCOV)
  target_compile_options(stack PRIVATE "--coverage")
  target_link_libraries(stack gcov)
endif()

add_executable(main main.c)
target_link_libraries(main stack)

add_executable(tests tests/main.cpp)
if(ENABLE_GCOV)
    target_compile_options(tests PRIVATE "--coverage")
    target_link_options(tests PRIVATE "--coverage")
endif()
target_link_libraries(tests stack gtest_main)

if(BUILD_BENCHMARKS)
  add_executable(benchmarks benchmarks/main.cpp)
  target_link_libraries(benchmarks stack benchmark::benchmark)
  target_compile_options(benchmarks PRIVATE "-pg")
  target_link_options(benchmarks PRIVATE "-pg")
endif()
