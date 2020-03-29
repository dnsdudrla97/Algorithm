#include <stdio.h>
void add(double num1, double num2);

int main()
{
    double x=3.1, y=5.1;
    void (*pointer)(double,double);

    printf("add function address : %x \n", add);
    printf("function pointer address : %x \n", &pointer);

    /*add function is start address not &*/
    pointer=add;
    printf("function pointer from add function address : %x \n", pointer);
    pointer(x, y);

    return (0);
}

void add(double num1, double num2)
{
    double result;
    result=num1+num2;
    printf("%lf + %lf = %lf this.\n",num1, num2, result);
}