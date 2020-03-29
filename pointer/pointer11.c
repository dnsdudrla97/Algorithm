#include <stdio.h>

int main()
{
    int array[3]={10,20,30};
    int* ip=NULL;
    int** ipp=NULL;

    ip=array;
    ipp=&ip;
    

    printf("%d %d %d\n",array[0], array[1], array[2]);
    printf("%d %d %d\n",*(ip+0), *(ip+1), *(ip+1));
    printf("%d %d %d\n",*(*ipp+0), *(*ipp+1), *(*ipp+1));


    return (0);
}