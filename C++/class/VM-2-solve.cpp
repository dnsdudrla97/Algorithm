#include <iostream>

class Parent
{
public:
    Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
    virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent
{
public:
    Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
    ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};
int main()
{
    std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
    {
        Child c;
    }
    std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
    {
        Parent *p = new Child();
        delete p;
    }
}

/*
Parent *p = new Chold();
delete p; : p -> Parent 객체가 아닌 child 객체이기 때문에 위에서 보통의 child 객체가 소멸되는 것과 같은 순서로 생성자와 소멸자들이 호출되어야 한다.
실제는 child 소멸자가 호출되지 않는다.

소멸자가 호출되지 않는다면 Child 객체에서 메모리를 동적으로 할당했지만 소멸자에서 해제하는데 소멸자가 호출안되면 메모리 릭이 발생

*/