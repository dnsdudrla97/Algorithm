#include <stdio.h>
#include <stdlib.h>
struct Check
{
    int move;
    int change;
    int* arr;
};
/* shell 1 */
void shell1(int a[], int n, struct Check* c) {
    c->change=0;
    c->move=0;
    int i, j ,h;
    for (h = n / 2; h > 0; h /= 2) {
        c->move++;
        for (i = h; i < n; i++) {
            int tmp = a[i];
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                c->change++;
                a[j + h] = a[j];
            }
            a[j + h] = tmp;
        }
    }

    printf("이동 횟수 : %d\n",c->move);
    printf("교환 횟수 : %d\n",c->change);
}


/* shell 2 */
void shell2(int a[], int n, struct Check* b) {
    b->change=0;
    b->move=0;
    int i, j ,h;

    for (h = 1; h < n / 9; h = h * 3 + 1)
        ; 
    for (; h > 0; h /=3) {
        b->move++;
        for (i = h; i < n; i++) {
            int tmp = a[i];
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                b->change++;
                a[j + h] = a[j];
            }
            a[j + h] = tmp;
        }
    }
    

    printf("이동 횟수 : %d\n",b->move);
    printf("교환 횟수 : %d\n",b->change);
}



int main(void) {
    struct Check c, b;
    int nx;
    
    printf("Numberic :");
    scanf("%d",&nx);

    c.arr = calloc(nx, sizeof(int));
    b.arr = calloc(nx, sizeof(int));
    
    for (int i = 0; i < nx; i++) {
        printf("c[%d] c[%d] ",i, i);
        scanf("%d %d", &c.arr[i], &b.arr[i]);
    }
    
    shell1(c.arr, nx, &c);
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : %d\n",i, c.arr[i]);
    }

    putchar('\n');
    shell2(b.arr, nx, &b);
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : %d\n",i, b.arr[i]);
    }

    free(c.arr);
    free(b.arr);


    return (0);
}