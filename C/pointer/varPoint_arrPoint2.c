#include <stdio.h>
int main(void) {
    int num=10;
    int (*p)[3]=NULL;
    int array[2][3]={
      {10, 20, 30},
      {40, 50, 60}
    };
    p=array;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            num *= j;
            (*(*(p+i)+j)) = num;
        }
        
    }
    return (0);
}