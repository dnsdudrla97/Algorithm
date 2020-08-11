#include <stdio.h>
int main(void)
{
    int array[3];
    int* p=NULL;

    p=array;

    *p=10;
    printf("%d %d %d \n", p[0], p[1], p[2]);
    printf("--------------\n");

    *(p+1) = 20;
    printf("%d %d %d \n", p[0], p[1], p[2]);
    printf("--------------\n");

    *(p+2) = 30;
    printf("%d %d %d \n", p[0], p[1], p[2]);
    printf("--------------\n");

    printf("%d %d %d \n", *p, *(p+1), *(p+2));
    printf("%d %d %d \n", p[0], p[1], p[2]);
    printf("--------------\n");
    
    return (0);
}