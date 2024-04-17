cmake_minimum_required(VERSION 3.10)
project(stack)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest

  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

FetchContent_MakeAvailable(googletest)

add_library(stack stack.c)

add_executable(main main.c)
target_link_libraries(main stack)

add_executable(test_create_node test_create_node.cpp)
target_link_libraries(test_create_node GTest::gtest_main)

add_executable(test_push test_push.cpp)
target_link_libraries(test_push stack GTest::gtest_main)

add_executable(test_traverse_stack test_traverse_stack.cpp)
target_link_libraries(test_traverse_stack stack GTest::gtest_main)

add_executable(test_stack_is_empty test_stack_is_empty.cpp)
target_link_libraries(test_stack_is_empty stack stack GTest::gtest_main)


include(GoogleTest)

gtest_discover_tests(test_push test_stack_is_empty)
gtest_discover_tests(test_stack_is_empty)
