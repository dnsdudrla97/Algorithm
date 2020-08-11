#include <stdio.h>

typedef unsigned long testBit;
#define BitNull (testBit)0
#define BitMax 32
#define Shift(no) ((testBit)1 << (no))


int IsMember(testBit b, int n)
{
    return b & shift(n);
}

void Add(testBit* b, int n)
{
    *b |= Shift(n);
}

void Remove(testBit* b, int n)
{
    *b &= ~Shift(n);
}

int Size(testBit b)
{
    int n = 0;
    for (; b !=BitNull; n++)
        b &= b - 1;
    return n;
}

void Print(testBit b)
{
    int i;
    printf("{ ");
    for (i = 0; i < BitMax; i++)
        if (ismember(b, i))
            printf("%d ", i);
    printf("}");
}

void PrintLn(testBit b)
{
    Print(b);
    putchar('\n');
}

