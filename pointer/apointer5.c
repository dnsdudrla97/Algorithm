#include <stdio.h>
int main(void)
{
    int array[3]={10,20,30};
    int* p=NULL;
    p=array;

    printf("%d %d %d \n", array[0], array[1], array[2]);
    printf("%d %d %d \n", *(array+0), *(array+1), *(array+2));
    printf("%d %d %d \n", p[0], p[1], p[2]);
    printf("%d %d %d \n", *(p+0), *(p+1), *(p+2));
    printf("array size: %d pointer size: %d \n", sizeof(array), sizeof(p));
    
    p=array+1; 
    printf("%d %d %d \n", p[-1], p[0], p[1]);
    printf("%d %d %d \n", *(p-1), *(p), *(p+1));
    
    


    return (0);
}