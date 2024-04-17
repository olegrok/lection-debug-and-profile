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

TEST_F(StackTest, TEST_TRAVERSE) {
    
}