/* 병합 정렬 프로그램*/
#include <stdio.h>
#include <stdlib.h>

static int* buf; /* work */

/* merge array (main) */
void __mergesort(int* a, int left, int right)
{
    if (left < right)
    {
        int i;
        int center = (left + right) / 2;
        int bufCurPoint = 0;
        int confPoint = 0;
        int mergePoint = left;
        __mergesort(a, left, center);      /*앞부분 병합 정렬*/
        __mergesort(a, center + 1, right); /*뒷부분 병합 정렬*/
        for (i = left; i <= center; i++) {
            buf[bufCurPoint++] = a[i];
        }
        while ( i <= right && confPoint < bufCurPoint) {
            a[mergePoint++] = (buf[confPoint] < a[i]) ? buf[confPoint++] : a[i++];
        }

        while (confPoint < bufCurPoint) {
            a[mergePoint++] = buf[confPoint++];
        }

    }
}
/*merge array func*/
int mergesort(int* a, int n)
{
    /* 일시적으로 저장할 작업용 배열 buff 선언*/
    if ((buf = calloc(n, sizeof(int))) == NULL)
        return -1;
    /* 배열 전체를 병합 정렬, 실제로 정렬 작업을 수행할 __mergesort 호출*/
    __mergesort(a, 0, n - 1);
    free(buf);
}



int main(void)
{
    int i, nx;
    int *x;
    puts("merge array");
    printf("numberic : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] :  ", i);
        scanf("%d", &x[i]);
    }
    if (mergesort(x, nx) == -1)
        puts("error");

    puts("increase sort");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return 0;
}