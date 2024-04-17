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

TEST_F(
    StackTest, STACK_SIZE_AFTER_PUSH_NODE
) {
    push(stack, 7);
    EXPECT_EQ(sizeof(stack), sizeof(Stack));
}
