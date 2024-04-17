#include <gtest/gtest.h>
#include "../stack.h"

using namespace std;

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
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}