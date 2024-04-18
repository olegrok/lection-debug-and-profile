#include "stack.h"

#include <gtest/gtest.h>
#include <string>

TEST(StackTestBase, initStackTest) {
    Stack stack;
    initStack(&stack);
    EXPECT_TRUE(getTop(&stack) == NULL);
}

TEST(StackTestBase, isEmptyTest) {
    Stack stack;
    initStack(&stack);
    EXPECT_TRUE(isEmpty(&stack));
}

TEST(StackTestBase, destroyStackSafeTest) {
    Stack stack;
    initStack(&stack);
    EXPECT_NO_THROW(destroyStack(&stack));
}

class StackTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = new Stack();
        initStack(stack);
    }

    void TearDown() override {
        destroyStack(stack);
        delete stack;
    }

    Stack *stack;
};

TEST_F(StackTest, TopAfterPushTest) {
    push(stack, 10);
    EXPECT_FALSE(isEmpty(stack));
    EXPECT_EQ(getTop(stack), stack->top);
}

TEST_F(StackTest, pushTest) {
    push(stack, 10);
    push(stack, 20);
    EXPECT_EQ(getTop(stack)->data, 20);
}

TEST_F(StackTest, popNisEmptyTest) {
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    EXPECT_EQ(getTop(stack)->data, 30);
    pop(stack);
    EXPECT_EQ(getTop(stack)->data, 20);
    pop(stack);
    EXPECT_EQ(getTop(stack)->data, 10);
    pop(stack);
    EXPECT_TRUE(isEmpty(stack));
}

TEST_F(StackTest, popFromEmptyTest) {
    push(stack, 10);
    pop(stack);
    EXPECT_TRUE(isEmpty(stack));
    EXPECT_NO_THROW(pop(stack));
}

TEST_F(StackTest, searchByValueTest) {
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    auto *fnd = searchByValue(stack, 30);
    EXPECT_TRUE(fnd != NULL);
    EXPECT_EQ(fnd->data, 30);

    fnd = searchByValue(stack, 20);
    EXPECT_TRUE(fnd != NULL);
    EXPECT_EQ(fnd->data, 20);

    fnd = searchByValue(stack, 40);
    EXPECT_TRUE(fnd == NULL);
}

TEST_F(StackTest, searchByIndexTest) {
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    auto *fnd = searchByIndex(stack, 0);
    EXPECT_TRUE(fnd != NULL);
    EXPECT_EQ(fnd->data, 30);

    fnd = searchByIndex(stack, 1);
    EXPECT_TRUE(fnd != NULL);
    EXPECT_EQ(fnd->data, 20);

    fnd = searchByIndex(stack, 3);
    EXPECT_TRUE(fnd == NULL);
}

TEST_F(StackTest, traverseStackTest) {
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    testing::internal::CaptureStdout();
    traverseStack(stack);
    std::string out = testing::internal::GetCapturedStdout();
    EXPECT_EQ(out, "Stack elements: 30 20 10 \n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
