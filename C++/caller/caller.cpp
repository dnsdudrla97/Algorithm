#include <iostream>     // 입출력 스트림 라이브러의 선언을 포함(불러온다.)

using namespace std;    // std:: 를 지정하지 않고도 std이름을 볼 수 있다.

double square(double x) // 배정도 부동소수점 수를 제곱
{
    return x*x;
}

void print_square(double x)
{
    cout << "the square of" << x << " is " << square(x) << "\n";
}

void print_test(double x)
{
    double z1 {1.2};
    cout << "TestInit" << x << "the" << z1 << square(x) << "\n";
}


int main()
{
    print_square(1.234);    //'the square of 1.234 is 1.52276'
    print_test(2.3);
}
