#include <stdio.h>

int ar[] = {1, 2, 3, 4, 5};

int &GetAr(int i)
{
    return ar[i];
}

void main()
{
    GetAr(3) = 6;
    printf("ar[3]=%d\n", ar[3]);
}