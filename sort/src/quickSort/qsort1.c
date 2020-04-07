/*qsort 함수를 사용하여 정수 배열을 오름차순으로 정렬*/
#include <stdio.h>
#include <stdlib.h>

/*---int 형 비교 함수(오름차순 정렬에 사용)---*/
int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return -1;
    if (*a > *b)
        return 1;
    else
        return 0;
}

int main(void)
{
    int i, nx;
    int *x;
    printf("qsort of sort\n");
    printf("numberic : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    qsort(x, nx, sizeof(int), (int (*)(const void *, const void *))int_cmp);
    puts("increase number");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return (0);
}