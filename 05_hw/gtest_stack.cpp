#include <gtest/gtest.h>
#include "stack.h"

TEST(StackTest, StackInit) {
    Stack stack;
    EXPECT_NO_THROW(getTop(&stack));

    initStack(&stack);
    EXPECT_TRUE(getTop(&stack) == NULL);
}

TEST(StackTest, PushPop) {
    Stack stack;
    initStack(&stack);

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

TEST(StackTest, IsEmpty) {
    Stack stack;
    initStack(&stack);
    EXPECT_TRUE(isEmpty(&stack));

    push(&stack, 10);
    EXPECT_FALSE(isEmpty(&stack));

    push(&stack, 20);
    pop(&stack);
    EXPECT_FALSE(isEmpty(&stack));

    pop(&stack);
    EXPECT_TRUE(isEmpty(&stack));
}

TEST(StackTest, Destroy) {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    destroyStack(&stack);
    EXPECT_TRUE(isEmpty(&stack));
}

TEST(StackTest, SearchByIndex) {
    Stack stack;
    initStack(&stack);

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

    destroyStack(&stack);
}

TEST(StackTest, SearchByValue) {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* retrieved = searchByValue(&stack, 20);
    EXPECT_TRUE(retrieved->next != NULL);
    EXPECT_EQ(retrieved->data, 20);

    destroyStack(&stack);
}

TEST(StackTest, GetTop) {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* top = getTop(&stack);
    EXPECT_TRUE(top->next != NULL);
    EXPECT_EQ(top->data, 30);

    destroyStack(&stack);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
