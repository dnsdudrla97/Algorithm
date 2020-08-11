#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_OF_FIBONACCI 10

long SFV[MAX_SIZE_OF_FIBONACCI + 1] = { 0 };

long fib(long nth)
{
    if ((nth == 0) || (nth == 1))
    {
        SFV[nth] = 1;
        return SFV[nth];
    }

    if ((SFV[nth - 1] != 0) && (SFV[nth - 2] != 0))
    {
        SFV[nth] = SFV[nth - 1] + SFV[nth - 2];
    }

    else
    {
        SFV[nth] = fib(nth - 1) + fib(nth - 2);
    }
    return SFV[nth];
}

int main(void)
{
    int i;
    long nth = 10;

    puts("This is Fibonacci Number Generation Project!!!\n");
    printf("The %ldth Fibonacci Number is : %ld\n", nth, fib(nth));

    for (i = 0; i < MAX_SIZE_OF_FIBONACCI; i++)
    {
        printf("%ld ", SFV[i]);
    }
    puts("\n");

    return EXIT_SUCCESS;
}