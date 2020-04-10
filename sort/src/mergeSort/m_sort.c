#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *buf;

void __mergeSort(char *a, size_t left, size_t right, size_t size,
                 int (*compar)(const void *, const void *))
{
    if (left < right)
    {
        size_t i;
        size_t center = (left + right) / 2;
        size_t bufCurPoint = 0;
        size_t bufConfPoint = 0;
        size_t mergePoint = left;

        __mergeSort(a, left, center, size, compar);
        __mergeSort(a, center + 1, right, size, compar);

        for (i = left; i <= center; i++)
            buf[bufCurPoint++ * size] = a[i * size];

        while (i <= right && bufConfPoint < bufCurPoint)
            a[mergePoint++ * size] = (compar((const void *)&buf[bufConfPoint * size],
                                             (const void *)&a[i * size]) <= 0)
                                         ? buf[bufConfPoint++ * size]
                                         : a[i++ * size];

        while (bufConfPoint < bufCurPoint)
            a[mergePoint++ * size] = buf[bufConfPoint++ * size];
    }
}
void m_sort(void *base, size_t nmeb, size_t size,
            int (*compar)(const void *, const void *))
{
    if (nmeb > 0)
        buf = calloc(nmeb, size);
    __mergeSort(base, 0, nmeb - 1, size, compar);
    free(buf);
}
/* a : buf b : original*/
int mergeConfirm(const int *x, const int *y)
{
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    else
        return 0;
}

int main(void)
{
    int i, nx;
    int *x;

    puts("m_sort 함수로 정렬합니다.");
    printf("요솟수：");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    m_sort(x,                                                /* 배열 */
           nx,                                               /* 요솟수 */
           sizeof(int),                                      /* 요소 하나의 크기 */
           (int (*)(const void *, const void *))mergeConfirm /* 비교 함수 */
    );

    puts("오름차순으로 정렬했습니다.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
