#include <gtest/gtest.h>
#include "stack.h"

class StackTest: public ::testing::Test {
protected:
    void SetUp() override {
        stack = (Stack*)malloc(sizeof(Stack));
    }

    void TearDown() override {
        destroyStack(stack);
        free(stack);
    }

    Stack* stack;
};

TEST_F(StackTest, STACK_IS_EMPTY) {
    ASSERT_TRUE(isEmpty(stack));
}

TEST_F(StackTest, STACK_NOT_EMPTY) {
    push(stack, 13);
    ASSERT_FALSE(isEmpty(stack));
}