#include <stdio.h>
#include <stdlib.h>


void insert(int* a, int n)
{
    int i, j, k, tmp;
    for (i = 1; i < n; i++) {
        tmp = a[i];

        for (k = 0; k < n; k++) {
            printf("%d  ",a[k]);
        }
        putchar('\n');
        
        for (j = i; j > 0 && a[j - 1] > tmp; j--) {
            a[j] = a[j - 1];
        }
        
        for (k = 0; k < n; k++) {
            printf("%c  ",(k == i ? '+' : k == j ? '^' : ' '));
            
        }
        
        putchar('\n');
        a[j] = tmp;
    }
}
int main(void) {

    int i, j, nx;
    int* x;
    
    printf("요소수: ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));
    
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    putchar('\n');

    insert(x, nx);

    // for (j = 0; j < nx; j++) {
    //     printf("x[%d] : %d\n", j, x[j]);
    // }

    free(x);
    return (0);
}