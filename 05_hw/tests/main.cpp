#include <gtest/gtest.h>
#include <string>
#include "../stack.h"

class StackTest : public ::testing::Test {
protected:
  Stack stack;

  void SetUp() override {
    initStack(&stack);
  }

  void TearDown() override {
    destroyStack(&stack);
  }
};

TEST_F(StackTest, TestCreation) {
  EXPECT_EQ(getTop(&stack), nullptr);
  EXPECT_EQ(isEmpty(&stack), true);
}

TEST_F(StackTest, TestPush) {
  push(&stack, 10);
  EXPECT_NE(getTop(&stack), nullptr);
  EXPECT_EQ(getTop(&stack)->data, 10);
  EXPECT_EQ(isEmpty(&stack), false);
  
  push(&stack, INT32_MAX);
  EXPECT_NE(getTop(&stack), nullptr);
  EXPECT_EQ(getTop(&stack)->data, INT32_MAX);
}

TEST_F(StackTest, TestPop) {
  push(&stack, 324);
  EXPECT_NE(getTop(&stack), nullptr);
  EXPECT_EQ(getTop(&stack)->data, 324);

  pop(&stack);
  EXPECT_EQ(getTop(&stack), nullptr);
  EXPECT_EQ(isEmpty(&stack), true);

  ASSERT_EXIT(pop(&stack), ::testing::ExitedWithCode(1), "");
}

TEST_F(StackTest, TestValueSearch) {
  EXPECT_EQ(searchByValue(&stack, 10), nullptr);
  push(&stack, -324);
  push(&stack, 12);

  Node* res = searchByValue(&stack, 12); 
  ASSERT_TRUE(res != nullptr);
  EXPECT_EQ(res->data, 12);

  res = searchByValue(&stack, -324); 
  ASSERT_TRUE(res != nullptr);
  EXPECT_EQ(res->data, -324);

  pop(&stack);
  res = searchByValue(&stack, 12); 
  ASSERT_TRUE(res == nullptr);
}

TEST_F(StackTest, TestIndexSearch) {
  EXPECT_EQ(searchByIndex(&stack, 324), nullptr);

  push(&stack, 10);
  push(&stack, 10213);
  push(&stack, -21);
  push(&stack, 10);
  EXPECT_EQ(searchByIndex(&stack, -10), nullptr);
  EXPECT_EQ(searchByIndex(&stack, 4), nullptr);

  Node* res = searchByIndex(&stack, 0);
  ASSERT_TRUE(res != nullptr);
  EXPECT_EQ(res->data, 10);
  pop(&stack);

  res = searchByIndex(&stack, 0);
  ASSERT_TRUE(res != nullptr);
  EXPECT_EQ(res->data, -21);

  res = searchByIndex(&stack, 1);
  ASSERT_TRUE(res != nullptr);
  EXPECT_EQ(res->data, 10213);

  res = searchByIndex(&stack, 2);
  ASSERT_TRUE(res != nullptr);
  EXPECT_EQ(res->data, 10);
}

TEST_F(StackTest, TestTraverse) {
  testing::internal::CaptureStdout();
  traverseStack(&stack);
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "Stack elements: \n");

  push(&stack, 102);
  push(&stack, 1);
  push(&stack, 0);
  push(&stack, 10000);
  push(&stack, -123);

  testing::internal::CaptureStdout();
  traverseStack(&stack);
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "Stack elements: -123 10000 0 1 102 \n");

  pop(&stack);
  testing::internal::CaptureStdout();
  traverseStack(&stack);
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "Stack elements: 10000 0 1 102 \n");

  push(&stack, 303);
  testing::internal::CaptureStdout();
  traverseStack(&stack);
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "Stack elements: 303 10000 0 1 102 \n");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}