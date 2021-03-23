#include <iostream>

class A {
  int x;

 public:
  A(int c) : x(c) {}
  A(const A& a) {
    x = a.x;
    std::cout << "복사 생성" << std::endl;
  }
};

class B {
  A a;

 public:
  B(int c) : a(c) {}
  B(const B& b) : a(b.a) {}
  A get_A() {
    A temp(a);
    return temp;
  }
};

int main() {
  B b(10);

  std::cout << "---------" << std::endl;
  A a1 = b.get_A();
}
/**
 * get_A() 함수에서 temp(a) 생성시 (a->temp)
 * return temp 에서 b.get_A()의 값이 리턴될 때 임시 객체를 생성하면서 한번 (temp->임시객체)
 * A a1 = 임시객체, 에서 한 번 (임시객체 -> a1)
 * 
 * **/
