#include <stdio.h>

unsigned long fibonnachifi(int nth) {

    if ((nth == 0) || (nth == 1))
    {
        return (1);
    }
    return fibonnachifi(nth - 2) + fibonnachifi(nth - 1);
}

int main(void)
{
    printf("%ld", fibonnachifi(10));
    return (0);
}