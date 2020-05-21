#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LEFT 0
#define LIM 9
#define swap(type ,x ,y) do {type t = x; x = y; y = t;} while(0);
int CheckPath(const int *a, int *c)
{
    int i;
    int cnt = 1;
    for (i = 0; i < LIM; i++) {
        printf("a[%d]:%d //%d\n",i,a[i]);
        if (a[i] == *c) break; 
    }
    return i;
}

void QuickSort(int* a, int lft, int rgt)
{
    int i;
    int ql = lft;
    int qr = rgt;
    int x = a[(ql + qr) / 2];
    do {
        while (a[ql] < x) ql++;
        while (a[qr] > x) qr--;
        if (ql <= qr) {
            swap(int, a[ql], a[qr]);
            ql++;
            qr--;
        }
    } while (ql <= qr);
    if (qr - lft > rgt - ql)
    {
        swap(int, ql, lft);
        swap(int, qr, rgt);
    }
    if (lft < qr) QuickSort(a, lft, qr);
    if (rgt > ql) QuickSort(a, ql, rgt);
}

int main()
{
    int* N;
    int i;
    N = calloc(LIM, sizeof(int));

    for (i = 0; i < LIM; i++)
        if (scanf("%d", &N[i]) > 100)
            break;

    QuickSort(N, LEFT, LIM-1);
    printf("%d\n%d", N[LIM-1], CheckPath(N, &N[LIM-1]));
    return 0;
}
