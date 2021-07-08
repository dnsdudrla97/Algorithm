// 레퍼런스 형태일 경우 해당 가상 함수 로직이 수행된다 
#include <iostream>

class A {
 public:
  virtual void show() { std::cout << "Parent !" << std::endl; }
};
class B : public A {
 public:
  void show() override { std::cout << "Child!" << std::endl; }
};

void test(A& a) { a.show(); }
int main() {
  A a;
  B b;
  test(a);
  test(b);

  return 0;
}

// 가상 함수의 구현 원리
/**
 * 
 * C++ 에서 virtual 키워드를 이용해 사용자가 직접 선언한 이유? -> 가상 함수를 사용하면 약간의 오버헤드가 발생
 * 
 * 
*/


