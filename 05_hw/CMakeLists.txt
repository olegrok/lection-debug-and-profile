cmake_minimum_required(VERSION 3.10)
project(stack)

option(ENABLE_ASAN OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if(ENABLE_ASAN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif()

add_library(stack stack.c)

add_executable(main main.c)
target_link_libraries(main stack)

add_executable(tests tests/main.cpp)
target_link_libraries(tests stack gtest_main)