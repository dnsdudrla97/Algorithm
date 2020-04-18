/* 두 포인터 값을 서로 교환하는 함수가 있는 프로그램 */
#include <stdio.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);
void swap_ptr (char **x, char **y)
{
    char *tmp = *x;
    *x = *y;
    *y = tmp;
}


int main(void)
{
    char *s1 = "ABCD";
    char *s2 = "EFGH";

    printf("s1 : %s\n",s1);
    printf("s2 : %s\n",s2);

    swap_ptr(&s1, &s2);
    swap(char*, s1, s2);
    

    puts("\ns1, s2 change\n");

    printf("s1 : %s\n",s1);
    printf("s2 : %s\n",s2);

    return 0;
}