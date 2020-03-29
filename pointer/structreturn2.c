#include <stdio.h>
#include <stdlib.h>

void allocArray(void** arr, int asize, int bsize)
{
    *arr=malloc(bsize * asize);
}

int main()
{
    long long *numArr1;
    int *numArr2;

    allocArray((void**)&numArr1, 10, sizeof(long long));
    allocArray((void**)&numArr2, 10, sizeof(int));

    

}