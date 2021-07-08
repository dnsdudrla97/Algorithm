#include<iostream>
#include<string.h>

class A{
    protected:
        unsigned int num;
        std::string flag = "FK{FEOKROEKROKEROKER}";
    public:
        A(){std::cout << "A Class (PARENT)" << std::endl;}
        A(unsigned int num, std::string flag) : num(num), flag(flag) {}

        virtual void getFlag() {
            std::cout << flag+"TOTAL" << std::endl;
        }    
};

class B : public A{
    std::string cacnel = "***{CANSEL}***";

    public:
        B() : A() {std::cout << "B Class(child)" << std::endl;}
        void getFlag() override {
            std::cout << cacnel << std::endl;
        }
};

int main() {
    A a;
    B b;
    a.getFlag();
    b.getFlag();

    A *a_a = &a;
    A *a_b = &b;

    a_a->getFlag();
    a_b->getFlag();
    return 0;
    
}