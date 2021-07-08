#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);

void rawPart(int32_t *arr) {
    int32_t pl = 0;
    int32_t pr = 9;
    int32_t pv = arr[5];

    do {
        while (pv > arr[pl]) pl++;
        while (pv < arr[pr]) pr--;

        if (pl <= pr) {
            swap(int32_t, arr[pl], arr[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    printf("피벗의 값은 %d이다.\n", pv);

    printf("피벗 이하의 그룹\n");        /*피벗 이하의 그룹*/
    for (int32_t i = 0; i <= pl - 1; i++)       /*a[0] ~ a[pl - 1]*/
        printf("%d ", arr[i]);
    putchar('\n');

    if (pl > pr + 1) {
        printf("피벗과 일치하는 그룹\n");        /*피벗과 같은 그룹*/
        for (int32_t i = pr + 1; i <= pl - 1; i++)        /*arr[pr + 1] ~ arr[pl - 1]*/
            printf("%d ", arr[i]);
        putchar('\n');
    }

    printf("피벗 이상의 그룹\n");        /*피벗 이상의 그룹*/
    for (int32_t i = pr + 1; i < 10; i++)        /*arr[pr + 1] ~ arr[n - 1]*/
        printf("%d ", arr[i]);
    putchar('\n');


}


int main(void) {
    int32_t *arr;
    arr = malloc(sizeof(int32_t)*10);

    srand(time(0));
    for (int32_t idx = 0; idx < 10; idx++) 
        arr[idx] = rand();
    // raw Part
    rawPart(arr);


    return;

}