constexpr double nth(double x, int n) // 0<=n가정
{
    double res = 1;
    int i = 0;
    while (i < n) {     // while 루프 : 조건이 true 동안 반복
        res *= x;
        ++i;
    }
    return res;
}