#include <gtest/gtest.h>

#include "stack.h"
#include "fixtures.h"


TEST_F(StackTest, STACK_IS_EMPTY) {
    ASSERT_TRUE(isEmpty(stack));
}

TEST_F(StackTest, STACK_NOT_EMPTY) {
    push(stack, 13);
    ASSERT_FALSE(isEmpty(stack));
}
