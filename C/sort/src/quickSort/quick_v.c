#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- 퀵 정렬(요솟수가 작은 그룹을 먼저 분할 : 재귀 버전) ---*/
void quick(int a[], int left, int right)
{
	int pl = left;				
	int pr = right;				
	int x = a[(pl + pr) / 2];	

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (pr - left < right - pl) {
		swap(int, pl, left);
		swap(int, pr, right);
	}
	if (left < pr)  quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}
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

    for (i = 0; i < nx; i++) {
        printf("x[%d] : %d\n", i, x[i]);
    }

    free(x);
    return (0);
}