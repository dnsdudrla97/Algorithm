#include <stdio.h>

int main(void)
{
    int a=1, b=2, c=3;
    int* pointer[3]={NULL,NULL,NULL};

    pointer[0]=&a;
    pointer[1]=&b;
    pointer[2]=&c;

    printf("%x %x %x \n", &a, &b, &c);
    printf("%x %x %x \n", pointer[0], pointer[1], pointer[2]);
    printf("%x %x %x \n", *(pointer+0), *(pointer+1), *(pointer+2));
    printf("-----------------\n");

    
    printf("%d %d %d \n", *&a, *&b, *&c);
    printf("%d %d %d \n", *pointer[0], *pointer[1], *pointer[2]);
    printf("%d %d %d \n", **(pointer+0), **(pointer+1), **(pointer+2));
    printf("-----------------\n");
    

    return (0);
}