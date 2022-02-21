#include <gtest/gtest.h>
#include <string>
#include <type_traits>

#include "stack2.hpp"

TEST(StackTest, construcotTest) {
  Stack<int> stack(234);
  ASSERT_EQ(stack.head(), 234);
}

TEST(StackTest, pushTestRVALUE) {
  Stack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  ASSERT_EQ(stack.head(), 40);
}

static const int firstInt = 10;
static const int secondInt = 20;
static const int thirdInt = 30;
TEST(StackTest, pushTestLVALUE) {
  Stack<int> stack;
  stack.push(firstInt);
  stack.push(secondInt);
  stack.push(thirdInt);
  ASSERT_EQ(stack.head(), 30);
}

TEST(StackTest, popTest) {
  Stack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.pop();
  stack.pop();
  stack.pop();
  ASSERT_EQ(stack.head(), 10);
}

TEST(StackTest, operatorTest) {
  Stack<int> stack = Stack<int>(234);
  ASSERT_EQ(stack.head(), 234);
}

class CustomClass {
 private:
  int f;
  double ft;

 public:
  CustomClass() {
    f = -1;
    ft = -1;
  }

  explicit CustomClass(const int& fi) {
    this->f = fi;
    this->ft = 0;
  }

  CustomClass(int fi, double fth) {
    this->f = fi;
    this->ft = fth;
  }

  bool operator!() const {
    if (this->f != -1) {
      return false;
    }
    if (this->ft != -1) {
      return false;
    }
    return true;
  };

  CustomClass& operator=(CustomClass* right) noexcept {
    f = right->f;
    ft = right->ft;
    return *this;
  }

  CustomClass& operator=(const CustomClass& right) = default;

  void print() const {
    std::cout << f << " " << ft << std::endl;
  }

  std::string getStr() const {
    std::string a = std::to_string(f) + " " + std::to_string(ft);
    return a;
  }
};

TEST(Stack2Test, pushEmplaceTest) {
  Stack2<CustomClass> stack2(CustomClass{11 });
  stack2.head().print();
  stack2.push_emplace(22, 22.0);
  stack2.head().print();
  stack2.push_emplace(33, 33.0);
  ASSERT_EQ(stack2.head().getStr(), "33 33.000000");
}

TEST(Stack2Test, move_and_copy_constructions){
  EXPECT_TRUE(std::is_move_constructible<Stack2<int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack2<int>>::value);
  EXPECT_TRUE(std::is_move_constructible<Stack2<CustomClass>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack2<CustomClass>>::value);
  EXPECT_FALSE(std::is_copy_constructible<Stack2<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack2<int>>::value);
  EXPECT_FALSE(std::is_copy_constructible<Stack2<CustomClass>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack2<CustomClass>>::value);
}

TEST(StackTest, move_and_copy_constructions){
  EXPECT_TRUE(std::is_move_constructible<Stack<int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack<int>>::value);
  EXPECT_TRUE(std::is_move_constructible<Stack<CustomClass>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack<CustomClass>>::value);
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_constructible<Stack<CustomClass>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<CustomClass>>::value);
}