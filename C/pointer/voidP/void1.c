#include <stdio.h>
int main(void)
{
    char c=3;
    double d=3.1;

    void* vx=NULL;

    vx=&c;
    printf("vx의 주소 값 : %x \n", vx);
    printf("vx의 주소 값 : %d \n", *(char*)vx); 

    vx=&d;
    printf("vx의 주소 값 : %x \n", vx);
    printf("vx의 주소 값 : %lf \n", *(double*)vx); 

    *(double*)vx = 10.1;
    printf("vx의 주소 값 : %x \n", vx);
    printf("vx의 주소 값 : %lf \n", *(double*)vx); 


    return (0);
}