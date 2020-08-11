#include <stdio.h>
int main()
{
    int a=0, b=0, c=0;
    int* ip=NULL;

    ip=&a;
    *ip=10;
    printf("%d %d %d %d \n", a, b, c, *ip);

    ip=&b;
    *ip=20;
    printf("%d %d %d %d \n", a, b, c, *ip);

    ip=&c;
    *ip=30;
    printf("%d %d %d %d \n", a, b, c, *ip);

    return (0);
}