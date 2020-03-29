#include <stdio.h>

typedef int (*FP)(int, int);

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

struct Calc {
    FP fp;
};

void executer(FP fp) {
    printf("%d\n", fp(70, 20));
}

FP (getAdd(int a, int b))
{
    printf("%d %d\n", a, b);
    return add;
}
int main()
{
    struct Calc c;
    c.fp=add;
    printf("%d", c.fp(10, 20));

    FP fp[2] = {add, sub};
    printf("%d\n", fp[0](20, 30));

    FP f1;
    f1 = add;
    printf("%d\n", f1(10, 20));

    executer(add);

    printf("%d", getAdd(10 , 20)(10, 20));

    return (0);
}