// virtual keyword (virtual function)

#include <iostream>

class Base {

 public:
  Base() { std::cout << "기반 클래스" << std::endl; }

  virtual void what() { std::cout << "기반 클래스의 what()" << std::endl; }
};
class Derived : public Base {

 public:
  Derived() : Base() { std::cout << "파생 클래스" << std::endl; }

  void what() { std::cout << "파생 클래스의 what()" << std::endl; }
};
int main() {
  Base p;
  Derived c;

  Base* p_c = &c;
  Base* p_p = &p;

  std::cout << " == 실제 객체는 Base == " << std::endl;
  p_p->what();

  std::cout << " == 실제 객체는 Derived == " << std::endl;
  p_c->what();

  return 0;
}

/*dynamic binding
이렇게 컴파일 시에 어떤 함수가 실행될 지 정해지지 않고 런타임 시에 정해지는 일을 가리켜서 동적 바인딩(dynamic binding) 이라고 부릅니다. 즉,
*/

/*
p_c->what();
"흠, p_c 는 Base 포인터니까 Base 의 what() 을 실행해야지"
"어 근데 what 이 virtual 이네?"

"잠깐. 이거 실제 Base 객체 맞어? 아니네 Derived 객체네"
"그럼 Derived 의 what 을 실행해야지"


p_p->what();
"흠, p_c 는 Base 포인터니까 Base 의 what() 을 실행해야지"
"어 근데 what 이 virtual 이네?"

"잠깐. 이거 실제 Base 객체 맞어? 어 맞네."
"Base 의 what 을 실행하자"
*/
