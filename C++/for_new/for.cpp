#include <iostream>
// g++ -std=c++11 for.cpp -o for

int main() {
    int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (auto number : fibonacci) {// fibonacci 에 포함된 모든 number에 대한
        std::cout << number << ' ';
    }
    
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for (auto& x:v) { // v에 포함된 모든 x에 1을 더함
        ++x;
        std::cout << x << '\n';
    }

    return 0;
}
