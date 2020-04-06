#include "stdio.h"
#include "stdlib.h"
#include "stackIn.h"
#include "quicknr.h"

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
    puts("오름차순으로 정렬했다.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);
    return (0);
}