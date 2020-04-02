#include <stdio.h>
#include <stdlib.h>

void insertSort(int* a, int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        int tmp = a[i];
        for (j = i; j > 0 && a[j-1] > tmp; j--) {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

void insertSortSerial(int* a, int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        tmp = a[0] = a[i];
        for (j = i; a[j - 1] > tmp; j--) {
            a[j] = a[j - 1];
        }
        if (j) a[j] = tmp;

    }
}

void insertSortBin(int* a, int n) {
    int i,j;
    int key;
    int pl, pr, pd, pc;
    
    for (i = 1; i < n - 1; i++) {
        key = a[i];
        
        do {
            pl = 0;
            pr = i - 1;
            pc = (pl + pr) / 2;

            if (a[pc] == key) break;
            else if(a[pc] > key) pr = pc - 1;
            else pl = pc + 1;
        } while(pl <= pr);
        pd = (pl <= pr) ? (pc + 1) : (pr + 1);

        for (j = i; j > pd; j--) {
            a[j] = a[j - 1];
        }
        a[pd] = key;
    }

}

int main(void)
{
	int i, nx;
	int *x;		

	puts("TEST");
	printf("NUMBERIC : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertSort(x, nx);
  			

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
