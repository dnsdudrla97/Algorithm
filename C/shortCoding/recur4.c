/* 재귀에 대해 깊이 이해하기 위한 재귀 함수 */
#include <stdio.h>

/* recur 
void recur(int n)
{
    if (n > 0) {
        recur(n - 2);
        printf("%d\n", n);
        recur(n - 1);
    }
}
*/

/* 함수 recur(꼬리 재귀를 제거) */
void recur(int n)
{
    TOP :
        if(n > 0)
        {
            recur(n - 1);
            printf("%d\n", n);
            n = n - 2;
            goto TOP;
        }
}

/*main*/
int main()
{
    int x;
    printf("정수를 입력하세요 : ");
    scanf("%d", &x);
    recur(x);

    return 0;
}