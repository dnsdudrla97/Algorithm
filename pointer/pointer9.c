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

    *ip1=20;
    printf("%d %d %d %d \n", num1, *ip1, **ip2, ***ip3);

    **ip2=30;
    printf("%d %d %d %d \n", num1, *ip1, **ip2, ***ip3);

    ***ip3=40;
    printf("%d %d %d %d \n", num1, *ip1, **ip2, ***ip3);

    return (0);
}