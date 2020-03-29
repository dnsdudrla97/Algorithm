#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}

typedef int (*FP)(int, int);

FP getAdd()
{
    return add;
}

int (*getSub())(int, int) {
    return sub;
}


int main()
{
    FP f = add;
    printf("%d\n", f(10, 20));

    printf("%d\n", getAdd()(10, 20));

    printf("%d\n", getSub()(10, 20));

    return (0);
}