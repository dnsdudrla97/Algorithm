#include <stdio.h>
#include <stdlib.h>


#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);

void selection(int* a, int n) {
    int min = 0;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }            
        }
        for (int k = 0; k < n; k++) {
            printf("%c  ", (k == i ? '*' : (k == min ? '+' : ' ')));
        }
        putchar('\n');
        for (int k = 0; k < n; k++) {
            printf("%d  ", a[k]);
        }
        
        putchar('\n');
        swap(int, a[i], a[min]);
    }
}

int main(void) {

    int i, j, n;
    int* x;
    
    printf("요소수: ");
    scanf("%d", &n);

    x = calloc(n, sizeof(int));
    
    for (i = 0; i < n; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    putchar('\n');

    selection(x, n);

    // for (j = 0; j < n; j++) {
    //     printf("x[%d] : %d\n", j, x[j]);
    // }

    free(x);
    return (0);
}