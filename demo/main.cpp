#include <stack.hpp>

#include "iostream"
#include "stack2.hpp"

class CustomClass {
 private:
  int f;
  double ft;

 public:
  CustomClass() {
    f = -1;
    ft = -1;
  }

  CustomClass(int fi) {
    f = fi;
    ft = 0;
  }

  CustomClass(int fi, double fth) {
    f = fi;
    ft = fth;
  }

  bool operator!() const {
    if (f != -1) {
      return false;
    }
    if (ft != -1) {
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

int main() {
  //  Stack<int> stack;
  //  const int& left = 50;
  //  stack.push(10);
  //  std::cout << stack.head() << std::endl;
  //
  //  stack.push(20);
  //  std::cout << stack.head() << std::endl;
  //  stack.push(30);
  //  std::cout << stack.head() << std::endl;
  //  stack.push(40);
  //  std::cout << stack.head() << std::endl;
  //  stack.push(left);
  //  std::cout << stack.head() << std::endl;
  //  stack.pop();
  //  std::cout << stack.head() << std::endl;
  //  stack.pop();
  //  std::cout << stack.head() << std::endl;
  //  stack.pop();
  //  std::cout << stack.head() << std::endl;
  //  std::cout << "Stack " << stack.head() << std::endl;
  //  Stack<int> stack1;
  //  stack1.push(333);
  //  std::cout << "Stack1 " << stack1.head() << std::endl;
  //  //   Оператор перемещения.
  //  stack1 = Stack<int>(444);
  //  std::cout << "Stack " << stack.head() << std::endl;
  //  std::cout << "Stack1 " << stack1.head() << std::endl;

//  Stack2<CustomClass> stack2(CustomClass{11 });
//  stack2.head().print();
//  stack2.push_emplace(22, 22.0);
//  stack2.head().print();
//  stack2.push_emplace(33, 33.0);
//  stack2.head().print();
//  stack2.push_emplace(44, 44.0);
//  stack2.head().print();
//  stack2.push_emplace(55);
//  stack2.head().print();
//  stack2 = Stack2<CustomClass>(123);
//  stack2.push_emplace(2223, 2223.0);
//  stack2.push_emplace(3354, 3354.0);
//  stack2.head().print();
//  std::string a = stack2.head().getStr();
//  std::cout << a << std::endl;
}