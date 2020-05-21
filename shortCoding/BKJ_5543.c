#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SET 50
#define NHB 3
#define NDK 2
typedef enum
{
    HBG,
    DRK,
} E_Seq;

int sort(int *x, E_Seq sw)
{
    int j;
    int min = 0;
    switch (sw)
    {
    case HBG:
        min = x[0];
        for (j = 0; j < NHB; j++)
            if (min > x[j])
                min = x[j];
        return min;
        break;

    case DRK:
        return min = (x[0] < x[1]) ? x[0] : x[1];
        break;

    default:
        break;
    }
}

int main()
{
    int *hamburger = calloc(3, sizeof(int));
    int *drink = calloc(2, sizeof(int));
    int i;
    int price;

    for (i = 0; i < NHB; i++)
    {
        if (scanf("%d", &hamburger[i]) == EOF)
            break;
        if (hamburger[i] < 100 && hamburger[i] > 2001)
            break;
    }
    for (i = 0; i < NDK; i++)
    {
        if (scanf("%d", &drink[i]) == EOF)
            break;
        if (drink[i] < 100 && drink[i] > 2000)
            break;
    }
    printf("%d", price = sort(hamburger, HBG) + sort(drink, DRK) - SET);
}