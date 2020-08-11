#include <stdio.h>

int main()
{
    int num1=10;
    int* ip1=NULL;
    int** ip2=NULL;
    int*** ip3=NULL;

    ip1=&num1;
    ip2=&ip1;
    ip3=&ip2;

    printf("%d %d %d %d \n", num1, *ip1, **ip2, ***ip3);
    printf("%x %x %x %x \n", &num1, ip1, *ip2, **ip3);
    printf("%x %x %x \n", &ip1, ip2, *ip3);
    printf("%x %x\n", &ip2, ip3);
    printf("%d %d\n", sizeof(int), sizeof(int*));
    printf("%d %d \n", sizeof(int**), sizeof(int***));
    printf("%d %d \n", sizeof(num1), sizeof(ip1));
    printf("%d %d \n", sizeof(ip2), sizeof(ip3));

    return (0);
}