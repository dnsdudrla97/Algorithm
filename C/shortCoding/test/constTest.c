#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(const unsigned int nth)
{
    unsigned int result = 1;

    for (int i = 1; i <= nth; i++)
    {
        result = result * i;
    }
    return result;
}

int main(void) {
    puts("Factorial Demo");
    unsigned int nth = 10;
    printf("The factorial of %d : %ld", nth, factorial(nth));

    return EXIT_SUCCESS;
}