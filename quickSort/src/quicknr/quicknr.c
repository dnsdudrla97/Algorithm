// #include "stackIn.h"
// #include "quicknr.h"
// #define swap(type, x, y) do {type t = x; x = y; y = t;} while (0);

// /*퀵 정렬 비 재귀*/
// void quick(int a[], int left, int right)
// {
//     t_stack lstack;     /*나눌 첫 요소 인덱스의 스택*/
//     t_stack rstack;     /*나눌 끝 요소 인덱스의 스택*/

//     Init(&lstack, right - left + 1);
//     Init(&rstack, right - left + 1);

//     Push(&lstack, left);
//     Push(&rstack, right);

//     while(!IsEmpty(&lstack)) {
//         int pl = (Pop(&lstack, &left), left);   /*왼쪽 커서*/
//         int pr = (Pop(&rstack, &right), right); /*오른쪽 커서*/
//         int x = a[(left + right) / 2];
        
//         do {
//             while(a[pl] < x) pl++;
//             while(a[pr] > x) pr--;
//             if (pl <= pr) {
//                 swap(int, a[pl], a[pr]);
//                 pl++;
//                 pr--;
//             }
//         } while(pl <= pr);

//         if (left < pr) {
//             Push(&lstack, left);    /*왼쪽 그룹 범위의*/
//             Push(&rstack, pr);      /*인덱스를 푸시*/
//         }
//         if (pl < right) {
//             Push(&lstack, pl);      /*오른쪽 그룹 범위의*/
//             Push(&rstack, right);   /*인덱스를 푸시*/    
//         }
//     }
//     Terminate(&lstack);
//     Terminate(&rstack);
// }
#include <stdio.h>
#include "stackIn.h"
#include "quicknr.h"
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);

// void print(const int x[], int lf, int rt){
//     int i;
//     printf("a[%d] ~ a[%d] : {", lf, rt);
//         for (i = lf; i < rt; i++)
//             printf("%d ", x[i]);
//         printf("%d}\n", x[rt]);
// }

// void quick(int a[], int left, int right)
// {
//     t_stack lstack;
//     t_stack rstack;
//     Init(&lstack, right - left + 1);
//     Init(&rstack, right - left + 1);

//     Push(&lstack, left);
//     Push(&rstack, right);
    
//     // int i;
//     // printf("a[%d] ~ a[%d] : {", left, right);
//     // for (i = left; i < right; i++)
//     //     printf("%d ", a[i]);
//     // printf("%d}\n", a[right]);
    
//     print(a, left, right);
//     while(!IsEmpty(&lstack))
//     {
//         int pl = (Pop(&lstack, &left), left);
//         int pr = (Pop(&rstack, &right), right);
//         int x = a[(pl + pr) / 2];

//         printf("\n-------------Pop chagne---------\n");
//         // printf("a[%d] ~ a[%d] : {", pl, pr);
//         // for (i = pl; i < pr; i++)
//         //     printf("%d ", a[i]);
//         // printf("%d}\n", a[pr]);
//         print(a, pl, pr);

//         do {
//             while (a[pl] < x) pl++;
//             while (a[pr] > x) pr--;
//             if (pl <= pr) {
//                 swap(int, a[pl], a[pr]);
//                 pl++;
//                 pr--;
//             }
//         } while(pl <= pr);

//         if (left < pr) {
//             Push(&lstack, left);
//             Push(&rstack, pr);
//         }
//         printf("\n-------------Push pivot under---------\n");
//         // printf("a[%d] ~ a[%d] : {", left, pr);
//         // for (i = left; i < pr; i++)
//         //     printf("%d ", a[i]);
//         // printf("%d}\n", a[pr]);
//         print(a, left, pr);
//         if (right > pl) {
//             Push(&lstack, pl);
//             Push(&rstack, right);
//         }
//         printf("\n-------------Push pivot under---------\n");
//         // printf("a[%d] ~ a[%d] : {", pl, right);
//         // for (i = pl; i < right; i++)
//         //     printf("%d ", a[i]);
//         // printf("%d}\n", a[right]);
//         print(a, pl, right);



//     }
//     Terminate(&lstack);
//     Terminate(&rstack);
// }

int sortMiddle(int x[], int a, int b, int c)
{
	if (x[b] < x[a])
		swap(int, x[b], x[a]);
	if (x[c] < x[b])
		swap(int, x[c], x[b]);
	if (x[b] < x[a])
		swap(int, x[b], x[a]);
	return b;
}

void insertingSort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int tmp = a[i];
		for (j = i; j >= 0 && a[j - 1] > tmp; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

/*--- 퀵 정렬(비재귀 버전) ---*/
void quick(int a[], int left, int right)
{
	t_stack lstack; /* 분할하는 앞쪽 요소의 인덱스를 저장할 스택 */
	t_stack rstack; /* 분할하는 뒤쪽 요소의 인덱스를 저장할 스택 */

	Init(&lstack, right - left + 1);
	Init(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	printf("a[%d] ~ a[%d]를 스택에 푸시합니다.\n", left, right);
	printf("Lstack:");
	Print(&lstack);
	printf("Rstack:");
	Print(&rstack);

	while (!IsEmpty(&lstack))
	{
		int pl = (Pop(&lstack, &left), left);	/* 왼쪽 커서 */
		int pr = (Pop(&rstack, &right), right); /* 오른쪽 커서 */
		int x;
		if (right - left < 9)
			insertingSort(&a[left], right - left + 1);
		else
		{
			int m = sortMiddle(a, pl, a[(pl + pr) / 2], pr);
			x = a[m];
			swap(int, a[m], a[right - 1]);
			pl++;
			pr -= 2;

			printf("====================================================\n");
			printf("스택에서 꺼낸 배열의 범위는 a[%d] ~ a[%d]입니다.\n", left, right);
			printf("====================================================\n");

			do
			{
				while (a[pl] < x)
					pl++;
				while (a[pr] > x)
					pr--;
				if (pl <= pr)
				{
					swap(int, a[pl], a[pr]);
					pl++;
					pr--;
				}
			} while (pl <= pr);

			if (pr - left < right - pl)
			{
				swap(int, left, pl);
				swap(int, pr, right);
			}

			if (left < pr)
			{
				Push(&lstack, left); /* 왼쪽 그룹의 범위 */
				Push(&rstack, pr);	 /* 인덱스 푸시 */

				printf("a[%d] ~ a[%d]를 스택에 푸시합니다.\n", left, pr);
				printf("Lstack:");
				Print(&lstack);
				printf("Rstack:");
				Print(&rstack);
			}
			if (pl < right)
			{
				Push(&lstack, pl);	  /* 오른쪽 그룹의 범위 */
				Push(&rstack, right); /* 인덱스 푸시 */

				printf("a[%d] ~ a[%d]를 스택에 푸시합니다.\n", pl, right);
				printf("Lstack:");
				Print(&lstack);
				printf("Rstack:");
				Print(&rstack);
			}
		}
	}
}