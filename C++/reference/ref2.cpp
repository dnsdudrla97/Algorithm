#include<stdio.h>
int main()
{
    int i = 3, j = 7;
    int &ri = i;
    printf("i=%d, ri=%d, j=%d\n", i, ri, j);
    ri = j;
    printf("i=%d, ri=%d, j=%d\n", i, ri, j);
}