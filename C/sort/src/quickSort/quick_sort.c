#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0);

void quick(int a[], int left, int right)
{
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];
    
    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
        if (left < pr) quick(a, left, pr);
        if (pl < right) quick(a, pl, right);
    } while(pl <= pr);
}

void quick_sort(int a[], int n)
{
    quick(a, 0, n - 1);
}

int main(void)
{
    int i, nx;
    int* x;
    puts("퀵 정렬");
    printf("요소 개수 :");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    quick_sort(x, nx);

    puts("오름차순으로 정렬했다.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);
    return (0);
}