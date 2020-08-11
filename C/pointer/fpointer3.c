#include <stdio.h>
void add(int num1, int num2);
void subtract(int num1, int num2);

int main(void)
{
    int x, z;
    char c;
    void (*pointer)(int, int);

    printf("add function address : %x \n", add);
    printf("subtract function address : %x \n", subtract);
    printf("input : ");

    scanf("%d %c %d", &x, &c, &z);

    if(c='+') pointer=add;
    else if(c=='-') pointer=subtract;
    else printf("second operator '+' or '-' please input. \n");

    pointer(x, z);
    return (0);
}

void add(int num1, int num2)
{
    int result;
    result=num1+num2;
    printf("%d + %d = %d this. \n", num1, num2, result);
}

void subtract(int num1, int num2)
{
    int result;
    result=num1-num2;
    printf("%d - %d = %d this. \n", num1, num2, result);
}