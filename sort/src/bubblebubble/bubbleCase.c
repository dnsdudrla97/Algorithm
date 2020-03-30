#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0);

typedef struct checkTime
{
    int Changetime;
    int Passtime;
}T_CHECK, *T_PCHECK;

// /* -- Case.1 -- */
// void bubble1(int* a, int n, T_PCHECK t)
// {
//     int i, j;

//     for (i = 0; i < n - 1; i++) {
//         t->Passtime++;
//         for (j = n - 1; j > i; j--) {
//             if (a[j - 1] > a[j]) {
//                 swap(int, a[j - 1], a[j]);
//                 t->Changetime++;
//             }
//         }
//     }
// }

// /* -- Case.2 -- */
// void bubble2(int* a, int n, T_PCHECK t)
// {
//     int i, j;
    
//     for (i = 0; i < n - 1; i++) {
//         int ps = 0;
//         t->Passtime++;
//         for (j = n - 1; j > i; j--) {
//             if (a[j - 1] > a[j]) {
//                 swap(int, a[j - 1], a[j]);
//                 t->Changetime++;
//                 ps++;
//             }
//         }
//         if (ps == 0) break;
//     }
// }

// void bubble3(int* a, int n, T_PCHECK t)
// {
//     int j;
//     int i = 0;
//     int last = 0;
//     int end = n - 1;
//     while (i < end) {
//         t->Passtime++;
//         for (j = end; j > i; j--) {
//             if (a[j - 1] > a[j]) {
//                 swap(int, a[j - 1], a[j]);
//                 t->Changetime++;
//                 last = j;
//             }
//         }
//         i = last;
//     }
// }

int bubble4(int* a, int n, T_PCHECK t)
{
    int left = 0;
    int right = n - 1;
    int last = right;
    

    while (left < right) {
        t->Passtime++;

        for(int i = right; i > left; i--) {
            t->Changetime++;
            if (a[i - 1] > a[i]) {
                swap(int, a[i - 1], a[i]);
                last = i;
            }
        }
        left = last;

        for (int i = left; i < right; i++) {
            t->Changetime++;
            if (a[i + 1] < a[i]) {
                swap(int, a[i + 1], a[i]);
                last = i;
            }
        }
        right = last;
    }
}
int main(void)
{
	int i, nx;
    T_CHECK t = {0, 0};
	int *x;		
	puts("버블 정렬");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

    // bubble1(x, nx, &t);
	// bubble2(x, nx, &t);					
    // bubble3(x, nx, &t);
    bubble4(x, nx, &t);
    
	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
    printf("교환 횟수: %d\n패스 횟수: %d\n",t.Changetime, t.Passtime);



	free(x);	

	return 0;
}