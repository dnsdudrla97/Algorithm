#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);

void bubbleSortRight(int* a, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j++) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
            }
        }
    }
}

void bubbleSortLeft(int* a, int n) {
    int i, j;
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (a[j + 1] < a[j]) {
                swap(int, a[j + 1], a[j]);
            }
        }
    }
}

void bubbleSortStop(int* a, int n) {
    int i, j;
    

    for (i = 0; i < n - 1; i++) {
        int stop = 0;
        for (j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                stop++;
            }
        }
        if (stop == 0) break;
    }
}

int is_sorted(const int a[], int n) {
    int i;
    int check = 0;
    for (i = 0; i < n - 1; i++) {
        if (a[i] < a[i+1]) {
            check++;
        } else return (-1);
    }
    if (check == (n - 1)) return (1);
}

int is_sorted2(int a[], int n)
{
	int i;

	for (i = n - 1; i > 0; i--)
		if (a[i - 1] > a[i])
			return 0;
	return 1;
}

void bubbleSortLast(int* a, int n) {    
    int k = 0;
    while (k < n - 1) {
        int j;
        int last = n - 1;

        for (j = n - 1; j > k; j--) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
        }
        k = last;
    }
}

void bubbleSortShaker(int* a, int n) {
    int left = 0;
    int right = n - 1;
    int last = right;
    int i;
    while (left < right) {
        
        for (i = right; i > left; i--) {
            if (a[i - 1] > a[i]) {
                swap(int, a[i - 1], a[i]);
                last = i;
            }
        }
        left = last;

        for (i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(int, a[i], a[i + 1]);
                last = i;
            }
        }
        right = last;
    }
}
void selectionSort(int* a, int n) {
    int i, j;
    
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++){
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(int, a[i], a[min]);
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

	bubbleSortShaker(x, nx);
    // if (is_sorted(x, nx) == 0) {
    //     puts("error\n");
    // } else puts("Success");			

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
