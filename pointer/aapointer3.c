#include <stdio.h>

int main(void)
{
    int array[2][3]={
        {10, 20, 30},
        {40, 50, 60}
    };
    int (*p1)[3]=NULL;

    p1=array;
    printf("%d %x %d %x %x", *(p1[0]+1), (p1[0]+1), *(*(p1+0) + 1), *(p1+0)+0, p1);


    return (0);
}
