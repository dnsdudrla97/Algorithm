/*
버블 정렬의 각 패스에서 비교, 교환은 처음(왼쪽)부터 수행해도 된다.
(각 패스에서 가장 큰 값의 요소가 끝으로 옮겨지게 하자)
*/
#include <stdio.h>
#include <stdlib.h>

#define swap2(type, x, y) do {type t = x; x = y; y = t;} while(0);

void bubble2(int* a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n-1; j++)
            if (a[j] > a[j + 1])
                swap2(int, a[j], a[j+1]);
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
    bubble2(x, nx);

    for (int i = 0; i < nx; i++)
        printf("a[%d] : %d\n",i, x[i]);
    putchar('\n');

    free(x);
    return (0);

}
