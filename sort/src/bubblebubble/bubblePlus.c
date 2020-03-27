/*
1. 비교 교환 과정을 자세히 출력
2. 버블 정렬하는 프로그램 작성,
3. 비교하는 두 요소 사이에 교환을 수행하면 '+'
4. 비교하는 두 요소 사이에 교환을 수행하지 않으면 '-'
5. 정렬을 마치변 비교 횟수와 교환 횟수를 출력
*/
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void set(int* a, int n)
{
    
    int confirm = 0;
    int change = 0;
    int i, j, k, l;
    for (i = 0; i < n - 1; i++) {
        printf("패스%d:\n", i + 1);
        for (j = n - 1; j > i; j--) {            
            for (k = 0; k < n - 1; k++)
                printf("%3d %c", a[k], (k != j - 1) ? ' ' : 
                (a[j - 1] > a[j]) ? '+' : '-');
            printf("%3d\n", a[n - 1]);

            confirm++;
            if (a[j - 1] > a[j]) {
                change++;
                swap(int, a[j - 1], a[j]);
            }
        }
        for (l = 0; l < n - 1; l++)
            printf("%3d  ", a[l]);
        putchar('\n');        
    }
    printf("비교를 %d회했습니다.\n", confirm);
    printf("교환을 %d회했습니다.\n", change);
}

int main(void)
{
    int* x;
    int nx;
    printf("요솟수: ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    set(x, nx);
    
    // for (int i = 0; i < nx; i++) {
    //     printf("x[%d] : %d\n", i, x[i]);
    // }

    free(x);
    return (0);
}