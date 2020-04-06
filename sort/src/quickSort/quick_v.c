#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0);

/* 배열의 분할 과정을 출력하는 뮉 정렬 프로그램*/
void quick(int a[], int left, int right)
{
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];

    int i;
    printf("a[%d] ~ a[%d] : {", left, right);
    for (i = left; i < right; i++)
        printf("%d ", a[i]);
    printf("%d}\n", a[right]);

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while(pl <= pr);
    if (left < pr) quick(a, left, pr);
    if (right > pl) quick(a, pl, right);
    
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
    quick(x, 0, nx - 1);
    free(x);
    return (0);
}