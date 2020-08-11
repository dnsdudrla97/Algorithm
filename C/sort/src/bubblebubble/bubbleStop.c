#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t = x; x = y; y = t;} while(0);

/*
버블 정렬(버전 2)의 아이디어는 배열이 정렬을 마쳤는지를 검사하는 데 응용할 수 있다.
전달 받은 배열 a가 오름차순으로 졍렬을 마쳤는지 검사하는 함수를 작성
이때 오름차순으로 정렬을 마친 상태라면 1, 그렇지 않으면 0을 반환
*/
int is_sorted(const int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i+1]) {
            return (1);
        }                
    }
    return (0);
}

/* 교환 횟수에 따라 정렬 작업을 멈춘다. */
void bubble(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int exchg = 0;  /* 패스에서 시도한 교환 횟수 */
        for (j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                exchg++;
            }
        }
        if (exchg == 0) break;  /* 교환이 수행되지 않았으면 정렬을 멈춘다. */
    }
}

int main()
{
    int nx;
    int* x;
    printf("요소의 개수 : ");
    scanf("%d",&nx);
    x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++)
    {
        printf("a[%d] : ", i);
        scanf("%d",&x[i]);
    }
    bubble(x, nx);
    if (is_sorted(x, nx))
        printf("CORRECT\n");
    else printf("Not Correct\n");

    
    
    // for (int i = 0; i < nx; i++)
    //     printf("a[%d] : %d\n",i, x[i]);
    putchar('\n');

    free(x);
    return (0);

}
