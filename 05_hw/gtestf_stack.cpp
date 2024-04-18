#include <gtest/gtest.h>
#include "stack.h"

class StackTest : public ::testing::Test {
protected:
    void SetUp() override {
        initStack(&stack);
    }

    void TearDown() override {
        destroyStack(&stack);
    }

    Stack stack;
};

TEST_F(StackTest, PushPop) {
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* current = getTop(&stack);

    EXPECT_TRUE(current != NULL);
    EXPECT_EQ(current->data, 30);

    pop(&stack);
    pop(&stack);
    current = getTop(&stack);
    EXPECT_TRUE(current != NULL);
    EXPECT_EQ(current->data, 10);

    pop(&stack);
    EXPECT_TRUE(getTop(&stack) == NULL);
}

TEST_F(StackTest, IsEmpty) {
    EXPECT_TRUE(isEmpty(&stack));

    push(&stack, 10);
    EXPECT_FALSE(isEmpty(&stack));

    push(&stack, 20);
    pop(&stack);
    EXPECT_FALSE(isEmpty(&stack));

    pop(&stack);
    EXPECT_TRUE(isEmpty(&stack));
}

TEST_F(StackTest, Destroy) {

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    destroyStack(&stack);
    
    EXPECT_TRUE((&stack)->top == NULL);
}

TEST_F(StackTest, SearchByIndex) {
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* retrieved = searchByIndex(&stack, 0);

    EXPECT_FALSE(retrieved == NULL);
    EXPECT_FALSE(retrieved->next == NULL);
    EXPECT_EQ(retrieved->data, 30);

    retrieved = searchByIndex(&stack, 1);
    EXPECT_TRUE(retrieved->next != NULL);
    EXPECT_EQ(retrieved->data, 20);
}

TEST_F(StackTest, SearchByValue) {
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* retrieved = searchByValue(&stack, 20);
    EXPECT_TRUE(retrieved->next != NULL);
    EXPECT_EQ(retrieved->data, 20);
}

TEST_F(StackTest, GetTop) {
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* top = getTop(&stack);
    EXPECT_TRUE(top->next != NULL);
    EXPECT_EQ(top->data, 30);
}

TEST_F(StackTest, PopFromEmpty) {
    EXPECT_NO_THROW(pop(&stack));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
