#include <stdio.h>
#include <stdlib.h>
#include "LibFactorial.h"

int main(void)
{
    puts("Factorial Demo");

    printf("The value of %dth factorial is : %lld \n",-1, factorial(-1));
    printf("The value of %dth factorial is : %lld \n",0, factorial(0));
    printf("The value of %dth factorial is : %lld \n",1, factorial(1));
    printf("The value of %dth factorial is : %lld \n",2, factorial(2));
    printf("The value of %dth factorial is : %lld \n",3, factorial(3));
    printf("The value of %dth factorial is : %lld \n",5, factorial(5));
    printf("The value of %dth factorial is : %lld \n",10, factorial(10));

    return EXIT_SUCCESS;
}