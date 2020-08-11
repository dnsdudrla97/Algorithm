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

int main()
{
    print_square(1.234);    //'the square of 1.234 is 1.52276'
}

x+y     // 덧셈
+x      // 단항 덧셈
x-y     // 뺄셈
-x      // 단항 뺄셈
x*y     // 곱셈
x/y     // 나눗셈
x%y     // 정수 나머지 연산

x==y    // 같음
x!=y    // 같지 않음
x<y     // ~보다 작음
x>y     // ~보다 큼
x<=y    // ~보다 작거나 같다
x>=y    // ~보다 크거나 같다

x&y     // 비트별 곱
x|y     // 비트별 합
x^y     // 비트별 베타적 합
~x      // 비트별 보수
x&&y    // 논리 곱
x||y    // 논리 합
!x      // 논리 부정

void some_function()
{
    double = 2.2;
    int i = 7;
    d = d+i;
    i = d*i;
}

x+=y    // x = x+y
++x     // 증가 x = x+1
x-=y    // x = x-y
--x     // 감소 x = x-1

