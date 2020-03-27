#include <stdio.h>
#include <stdlib.h>

int fib(int nth)
{
    if ((nth == 0) || (nth == 1))
    {
        return (1);
    }
    return fib(nth-1) + fib(nth-2);
}

int main(void)
{
    int nth = 50;

    puts("This is Fib Number Generation Project!!\n");
    printf("The %dth Fib Number is : %d\n", nth, fib(nth));

    return EXIT_SUCCESS;
}