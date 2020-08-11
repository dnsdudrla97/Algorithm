#include <stdio.h>

int main(void)
{
    char array[]={'A', 'B', 'C', 'D'};

    printf("char const value : %c %c %c %c \n", 'A', 'B', 'C', 'D');

    printf("char array value : %c %c %c %c \n", array[0], array[1], array[2], array[3]);

    array[0]='D';
    array[1]='C';
    array[2]='B';
    array[3]='A';

    printf("char array value : %c %c %c %c \n", array[0], array[1], array[2], array[3]);
    printf("char array size : %d \n", sizeof(array));

    char* p = NULL;
    p = array;
    printf("pointer char : %c %c %c \n", *(p+0), *(p+1), p[3]);
    printf("pointer char : %d %d %d \n", *(p+0), *(p+1), p[3]);

    
    return (0);
}