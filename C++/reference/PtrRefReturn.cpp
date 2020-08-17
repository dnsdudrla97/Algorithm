#include <stdio.h>
#include <stdlib.h>

int &func()
{
    int *pt;
    pt = (int *)malloc(sizeof(int));
    *pt = 3;
    return *pt;
}
int main()
{
    int *pi;
    pi = &func();
    printf("%d\n", *pi);
    free(pi);
}