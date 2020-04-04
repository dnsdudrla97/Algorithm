/* 셸 정렬(h = ..., 13, 4, 1) */
#include <stdio.h>
#include <stdlib.h>

/* 셸 정렬 함수(h = ..., 13, 4, 1) */
void shell(int a[], int n) {
    int i, j, h;
    for (h = 1; h < n / 9; h = h * 3 + 1)
        ;
    for (; h > 0; h /= 3)
        for (i = h; i < n; i++) {
            int tmp = a[i];
            for (j = i - h; j >=0 && a[j] > tmp; j -= h)
                a[j + h] = a[j];
            a[j + h] = tmp;
        }
}


int main(void) {
    int i, nx;
    int *x;
    puts("셸 정렬");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    shell(x, nx);
    puts("오름 차순으로 정렬했다.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return (0);
}