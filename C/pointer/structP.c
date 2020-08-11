#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *allocMemory()
{
    // void *ptr = malloc(100);
    // return ptr;
    return malloc(100);
}

int main()
{
    char* s1 = allocMemory();
    strcpy(s1, "Hello, world~!");
    printf("%s\n", s1);
    free(s1);

    int* numptr1 = allocMemory();
    numptr1[0]=10;
    numptr1[1]=20;
    printf("%d %d\n", numptr1[0], numptr1[1]);
    free(numptr1);

    return (0);
}