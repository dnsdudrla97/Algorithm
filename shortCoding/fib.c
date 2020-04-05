#include <stdio.h>
#include <stdlib.h>

unsigned long long fib(int nth)
{
    int i;

    unsigned long long first = 1;
    unsigned long long second = 1;
    unsigned long long fibValue = 0;

    if (nth < 0)
    {
        return 0;
    }

    if ((nth == 0) || (nth == 1))
    {
        return 1;
    }

    for (i = 2; i < nth; i++)
    {
        fibValue = first + second;
        first = second;
        second = fibValue;
    }
    
    return fibValue;
}

int main(void)
{
    int i;
    int nth = 100;
    puts("New Fib");
    for (i = 0; i <= nth; i++)
    {
        printf("The fib value of %dth is %llu.\n", i, fib(i));
    }
    return EXIT_SUCCESS;
}
