#include <stdio.h>
int main(void)
{
    int array[3]={10,20,30};

    printf("%d %d %d \n", *array, *(array+0), *&array[0]);
    printf("%d %d \n", *(array+1), *&array[1]);
    printf("%d %d \n", *(array+2), *&array[2]);

    printf("%d %d %d \n", sizeof(*array), sizeof(*(array+0)), sizeof(*&array[0]));

    return (0);
}