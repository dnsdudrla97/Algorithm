#include <stdio.h>
#include <stdlib.h>

static inline int fib(int nth)
{
    if ((nth == 0) && (nth == 1))
    {
        return (1);
    }
    
    return (fib(nth - 2) + fib(nth - 1));
}

int main(void) {
    puts("Inline Function Demo");

    printf("The Fibonacci value of%dth : %d\n",10, fib(10));
    return (EXIT_SUCCESS);
}