#include <stdio.h>

struct Calc {
    int (*fp)(int, int);
};

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int (*getAdd())(int, int)
{
    return add;
}

int (*getSub(int a, int b))(int, int)
{
    printf("%d %d\n",a, b);
    return sub;
}

void executer(int (*fp)(int, int))
{
    printf("%d\n", fp(10, 20));
}

int main()
{
    struct Calc c;
    c.fp = add;
    printf("%d %d \n", c.fp(10, 20), getAdd()(10, 20));
    executer(add);
    printf("%d, \n",getSub(10, 20)(50, 20));
    

    return (0);
}