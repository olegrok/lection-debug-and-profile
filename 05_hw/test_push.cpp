#include <gtest/gtest.h>

#include "stack.h"
#include "fixtures.h"


TEST_F(
    StackTest, STACK_TOP_NULL_AFTER_PUSH
) {
    push(stack, 7);
    EXPECT_NE(stack->top, nullptr);
}

TEST_F(
    StackTest, STACK_ELEMENTS_DATA
) {
    push(stack, 7);
    EXPECT_EQ(stack->top->data, 7);
}
