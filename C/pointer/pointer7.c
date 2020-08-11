#include <stdio.h>

int main(void)
{
    int num1=10;
    int* ip=NULL;
    int** ipp=NULL;

    ip=&num1;
    ipp=&ip;

    printf("%d %x %x \n", num1, ip, ipp);
    printf("%x %x %x \n", &num1, &ip, &ipp);
    printf("%d %x %x \n", *&num1, *&ip, *&ipp);
    printf("%d %d %d \n", num1, *ip, **ipp);
    printf("%x %x %x \n", &num1, ip, *ipp);

    return (0);
}