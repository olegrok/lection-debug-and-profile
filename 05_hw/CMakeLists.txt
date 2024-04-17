cmake_minimum_required(VERSION 3.10)
project(stack)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(stack stack.c)

add_executable(main main.c)
target_link_libraries(main stack)

add_executable(tests tests/main.cpp)
target_link_libraries(tests stack gtest_main)