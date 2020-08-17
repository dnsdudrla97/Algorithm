#include <stdio.h>

int ar[5] = {100, 101, 102, 103, 104};

void func(int a)
{

    printf("%d\n", a);
}

void main()
{

    void (&rf)(int) = func; // 함수 레퍼런스

    int(&rar)[5] = ar; // 배열 레퍼런스

    rf(rar[0]);
}