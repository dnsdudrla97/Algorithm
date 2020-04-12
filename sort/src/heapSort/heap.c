/*heapSort*/
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);

/* a[left] ~ a[right] heap change*/
static void downHeap (int* a, int left, int right)
{
    int root = a[left];     /* root */
    int child;
    int parent;
    for (parent = left; parent < (right + 1) / 2; parent = child) {
        int pl = parent * 2 + 1;
        int pr = pl + 1;
        child = (pr <= right && a[pr] > a[pl]) ? pr : pl;

        if (root >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = root;
}

void heapSort(int* a, int n)
{
    int i;
    puts("downHeap\n");
    for (i = (n - 1) / 2; i >= 0; i--)
        downHeap(a, i, n - 1);

    puts("heapSort\n");
    for (i = n - 1; i > 0; i--) {
        swap(int, a[0], a[i]);
        downHeap(a, 0, i - 1);
    } 
}

int main(void)
{
	int i, nx;
	int *x;		

	puts("힙 정렬");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	heapSort(x, nx);	

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
