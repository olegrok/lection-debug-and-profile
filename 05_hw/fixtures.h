#pragma once
#include <gtest/gtest.h>

#include "fixtures.h"
#include "stack.h"

class StackTest: public ::testing::Test {
protected:
    void SetUp() override {
        stack = (Stack*)malloc(sizeof(Stack));
        initStack(stack);
    }

    void TearDown() override {
        destroyStack(stack);
        free(stack);
    }

    Stack* stack;
};
