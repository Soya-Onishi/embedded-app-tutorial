#include "gtest/gtest.h"
#include "stack.h"

class StackTest : public testing::Test {
 protected:
  StackTest() { this->stack = nullptr; }
  ~StackTest() override {}

  void SetUp() override { this->stack = new_stack(16); }

  void TearDown() override { free_stack(this->stack); }

  my_stack_t* stack;
};

TEST(StackFundamental, StackInitialize) {
  my_stack_t* stack = new_stack(16);
  EXPECT_EQ(16, stack_size(stack));
  EXPECT_EQ(0, stack_len(stack));

  // 異なるサイズを与えたとき、そのサイズのスタックができるかの確認
  my_stack_t* stack_another = new_stack(32);
  EXPECT_EQ(32, stack_size(stack_another));
  EXPECT_EQ(0, stack_len(stack_another));

  free_stack(stack);
  free_stack(stack_another);
};

// サイズが0のスタックを作ろうとするとエラーとしてNULLを返す
TEST(StackFundamental, FailStackInitialize) {
  const my_stack_t* stack = new_stack(0);

  EXPECT_EQ(nullptr, stack);
}

// 二重フリーを防止できているかの確認
TEST(StackFundamental, StackPostProcess) {
  my_stack_t* stack = new_stack(16);

  EXPECT_TRUE(free_stack(stack));

  // 二重フリーは失敗する
  EXPECT_FALSE(free_stack(stack));
};

// スタックに要素をプッシュすると要素数が増加する
TEST_F(StackTest, PushElement) {
  stack_push(stack, 10);
  ASSERT_EQ(1, stack_len(stack));

  stack_push(stack, 20);
  ASSERT_EQ(2, stack_len(stack));
};

// スタック容量の限界まで要素をプッシュしたとき、エラーを返す
TEST_F(StackTest, PushToLimit) {
  for (int i = 0; i < stack_size(stack); i++) {
    ASSERT_TRUE(stack_push(stack, i + 1));
  }
  ASSERT_EQ(16, stack_len(stack));

  // 容量MAX時にプッシュすると失敗する。
  EXPECT_FALSE(stack_push(stack, 17));
  EXPECT_EQ(16, stack_len(stack));
};

// スタックから要素をポップすると要素数が減少する
TEST_F(StackTest, PopElement) {
  stack_push(stack, 10);
  stack_push(stack, 20);
  ASSERT_EQ(2, stack_len(stack));

  uint32_t elem;
  stack_pop(stack, &elem);
  EXPECT_EQ(1, stack_len(stack));
  stack_pop(stack, &elem);
  EXPECT_EQ(0, stack_len(stack));
};

// スタックから要素をポップすると要素をプッシュした順に値が出てくる。
TEST_F(StackTest, PopElementOrder) {
  for (int i = 0; i < stack_size(stack); i++) {
    stack_push(stack, i + 1);
  }

  for (int i = 0; i < stack_size(stack); i++) {
    uint32_t elem = 0xDEADBEEF;
    ASSERT_TRUE(stack_pop(stack, &elem));

    // プッシュした順とは逆順で要素がポップされる
    uint32_t expect = stack_size(stack) - i;
    ASSERT_EQ(expect, elem);
  }
};

// スタックが空のときにポップすると失敗する。
TEST_F(StackTest, PopElementEmpty) {
  uint32_t elem = 0xDEADBEEF;

  // 初期状態でポップをしたときはエラーになる
  EXPECT_FALSE(stack_pop(stack, &elem));
  EXPECT_EQ(0xDEADBEEF, elem);
  ASSERT_EQ(0, stack_len(stack));

  // 一度、要素をプッシュした後に空にしたあと、更にポップしてもエラーになる
  stack_push(stack, 10);
  EXPECT_TRUE(stack_pop(stack, &elem));
  EXPECT_FALSE(stack_pop(stack, &elem));
  EXPECT_EQ(10, elem);
  EXPECT_EQ(0, stack_len(stack));
};