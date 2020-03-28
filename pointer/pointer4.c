#include <stdio.h>

int main(void)
{
    int num=10;
    int* ip=NULL;

    ip=&num;

    printf("%x %x %d \n", &*&ip, *&ip, **&ip);
    printf("%x %x %d \n", &ip, ip, *&ip);

    return (0);
}