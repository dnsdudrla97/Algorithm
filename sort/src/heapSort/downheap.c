#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);
/*
Parent = (i-1) / 2
ChildL = (i*2) + 1, 2
ChildR = (i*2) + 1, 2
*/
static void downheap(int a[], int left, int right)
{
    int root = a[left];     /*root*/
    int child;
    int parent;
    
    for (parent = left; parent < (right + 1) / 2; parent = child)
    {
        int cl = parent * 2 + 1;
        int cr = cl + 1;
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;
        if (root >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = root;
}


void heapsort(int a[], int n)
{
    int i;

    puts("배열 -> 힙\n");
    for (i = (n - 1) / 2; i >=0; i--) {
        downheap(a, i, n - 1);
    }

    puts("힙 정렬\n");
    for (i = n - 1; i >= 0; i--) {
        swap(int, a[0], a[i]);
        downheap(a, 0, i - 1);
    }

}

int main(void)
{
    int* x;
    int nx;
    printf("nx : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));
    for (int i = 0; i < nx; i++) {
        printf("x[%d] :", i);
        scanf("%d", &x[i]);
    }
    heapsort(x, nx);
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : %d\n", i, x[i]);
    }
    free(x);

    return (0);
}