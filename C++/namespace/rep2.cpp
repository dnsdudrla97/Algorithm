#include <iostream>

int main() {
    int b = 3;
    int* ptr = &b;
    
    int a = 3;
    int& another_a = a;

    std::cout<<"ptr : " << ptr << std::endl;
    std::cout<<"ptr "<<*ptr<<std::endl;

    another_a = 5;
    std::cout<<"a : " << a << std::endl;
    std::cout<<"another_as: "<<another_a<<std::endl;
    
    *ptr = 10;
    std::cout<<"ptr : " << ptr << std::endl;
    std::cout<<"ptr "<<*ptr<<std::endl;

    return 0;
}