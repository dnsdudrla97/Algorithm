#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int* a, const int* b)
{
    return *a > *b ? 1 : *a < *b ? -1 : 0;
}

void mem_swap(void* x, void* y, size_t n)
{
    unsigned char* a = (unsigned char*)x;
    unsigned char* b = (unsigned char*)y;

    for (; n--; a++, b++)
    {
        unsigned c = *a;
        *a = *b;
        *b = c;
    }
}

void q_sort(void* base, size_t nemb, size_t size, int (*compare)(const void*, const void*))
{
    if (nemb > 0)
    {
        int pl = 0;
        int pr = nemb - 1;
        int pv = nemb;
        int pt = (pl+pr)/2;
        char* v = (char*)base;
        char* x;

        do {
            if (pt != pv) x = &v[(pv = pt) * size];

            while ((compare(&v[pl  * size], x) < 0)) pl++;
            while ((compare(&v[pr  * size], x) > 0)) pr--;

            if (pl <= pr) {
                mem_swap(&v[pl * size], &v[pr * size], size);
                pl++;
                if (pr == 0)
                    goto err;
                pr--;
            }
        } while(pl <= pr);

        if (pr > 0) q_sort(&v[0], pr + 1, size, compare);
    err:
        if (pl < nemb - 1) q_sort(&v[pl], nemb - pl, size, compare);
    }
}


int main(void)
{
    int i, nx;
    int *x;

    printf("q_sort 함수로 정렬합니다.\n");
    printf("요솟수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    q_sort(x,                                           /* 배열 */
           nx,                                          /* 요솟수 */
           sizeof(int),                                 /* 요소 하나의 크기 */
           (int (*)(const void *, const void *))int_cmp /* 비교 함수 */
    );

    puts("오름차순으로 정렬했습니다.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
