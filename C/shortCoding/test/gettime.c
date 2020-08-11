#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

unsigned long fib(int nth) {
    if ((nth == 0) || (nth == 1))
    {
        return (1);
    }
    return fib(nth - 2) + fib(nth - 1);
}

int main(void)
{
    puts("This is a clock tick calcuation program!!\n");
    unsigned long result = 0;
    struct timeval start;
    struct timeval stop;
    struct timeval elapsed;

    gettimeofday(&start, NULL);
    
    result = fib(100);
    gettimeofday(&stop, NULL);

    elapsed.tv_sec = stop.tv_sec - start.tv_sec;
    if (stop.tv_usec < start.tv_usec)
    {
        elapsed.tv_sec--;
        elapsed.tv_usec = ( 1000000 - start.tv_usec ) + stop.tv_usec;
    }
    else
    {
        elapsed.tv_usec = stop.tv_usec - start.tv_usec;
    }

    printf("To calc fib number, it takes %lu secs and %lu usec.\n", elapsed.tv_sec, elapsed.tv_usec);
    printf("The fib value is : %lu\n", result);

    return (EXIT_SUCCESS);
}