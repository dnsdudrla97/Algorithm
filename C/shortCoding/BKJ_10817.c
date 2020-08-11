#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//40 1 10
int mid(int *a, int *b, int *c)
{
    int MIN = *a;
    int tmp = 0;

    if (*a < *b)
    {
        if (*a < *c)
        {
            if (*b < *c)
            {
                return *b;
            }
            else
                return *c;
        }
        else
            return *a;
    }
    else
    {
        if (*a < *c)
        {
            return *a;
        }
        else
        {
            if (*b > *c)
            {
                return *b;
            }
            else
                return *c;
        }
    }
}

int main(void)
{
    int A, B, C;
    if (scanf("%d %d %d", &A, &B, &C) == EOF)
        return 0;
    if ((1 > A || A > 101) || (1 > B || B > 101) || (1 > C || C > 101))
        return 0;
    printf("%d", mid(&A, &B, &C));
    return 0;
}