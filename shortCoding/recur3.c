#include <stdio.h>
#include <stdlib.h>
int gcd(int x, int y) {
    if (y == 0) {
        return (x);
    }

    return (gcd(y, x % y));
}

int gcd_array(const int* a, int nx) {
    
    if (nx == 1) return (a[0]);
    else if(nx == 2) return (gcd(a[0], a[1]));
    else return (gcd(a[0], gcd_array(&a[1], nx - 1)));
}


int main()
{
    int nx;
    int* a;
    printf("배열의 요소수를 입력해주세요: ");
    scanf("%d",&nx);
    putchar('\n');

    printf("배열의 해당 값을 입력하세요\n");
    a = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++)
    {
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    printf("최대공약수 : %d\n",gcd_array(a, nx));
    return (0);
}