#include <stdio.h>
// 10 20 30 40 50
void arrInput(int a[], int n);
int main(void)
{
    int array[5]={10, 20, 30, 40, 50};
    //
    void(*pfunc)(int*, int);

    pfunc=arrInput;
    pfunc(array, 5);

    return 0;
}

//
void arrInput(int a[], int n)
{
    int i=0;
    while(i < n)
    {
        printf("%d ",a[i++]);
    } 
    
}