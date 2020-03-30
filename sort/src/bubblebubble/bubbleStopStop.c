#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)


void set(int* a, int n)
{   
    int confirm = 0;
    int change = 0;
    int i = 0;
    int last;
    int j, k, l;

    while(i < n - 1) {
        printf("패스%d:\n", i + 1);
        int exchg = 0;

        for (j = n - 1; j > i; j--) {            
            for (k = i; k < n - 1; k++)
                printf("%3d %c", a[k], (k != j - 1) ? ' ' : (a[j - 1] > a[j]) ? '+' : '-');
            printf("%3d\n", a[n - 1]);
            confirm++;

            if (a[j - 1] > a[j]) {
                change++;
                exchg++;
                swap(int, a[j - 1], a[j]);
                last = j;
            }

        }
        i = last;

        for (l = 0; l < n; l++)
            printf("%3d  ", a[l]);
        putchar('\n');
        if (exchg == 0) break;        
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