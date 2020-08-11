#include <stdio.h>
#include <stdlib.h>

int binaryInsertSort(int* a, int n)
{   
    int i, j;
    for (i = 1; i < n; i++) {
        int pl = 0;         /*정렬된 첫 번째 배열*/                                                       
        int pr = i - 1;     /*정렬된 마지막 배열 i - 1 타겟 뒤*/                                                                                              
        int pc;             /*pl, pr의 중간값*/                                
        int pd;             /*pd 삽입 위치*/                                   
        int key = a[i];     /*key 타겟 */                                       

        do {
            pc = (pl + pr) / 2;
            if (a[pc] == key) break;
            else if (a[pc] < key) pl = pc + 1;
            else pr = pc - 1;
        } while (pl <= pr); /*pl 이 pr보다 크면 끝*/
        printf("%d %d %d\n",pl, pr, pc);
        pd = pr + 1;      /*pc + 1 => (pl <= pr) ? (pc + 1) :  */
        printf("%d\n",pd);

        for (j = i; j > pd; j--) {
            a[j] = a[j - 1];
        }
        a[pd] = key;
    }
}

int main(void) {
    int nx, i;
    int* x;

    printf("BinarySearch of Insert numberic : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d",&x[i]);
    }
    putchar('\n');

    binaryInsertSort(x, nx);

    for (i = 0; i < nx; i++) {
        printf("x[%d] : %d\n",i,x[i]);
    }

    free(x);
    return (0);
}