#include <gtest/gtest.h>

#include "stack.h"
#include "fixtures.h"

TEST_F(StackTest, TEST_TRAVERSE_STACK_WITH_ELEMENTS) {
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    EXPECT_EQ(strcmp(traverseStack(stack), "30 20 10"), 0);
}

TEST_F(StackTest, TEST_TRAVERSE_EMPTY_STACK) {
    EXPECT_EQ(strcmp(traverseStack(stack), ""), 0);
}
