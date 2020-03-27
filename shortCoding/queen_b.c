/* 각 열에 1개의 퀸을 배치하는 조합을 재귀적으로 나열한다. */
#include <stdio.h>

int pos[8];     /* 각 열에서 퀸의 위치 */

/* 각 열의 퀸의 위치를 출력 */
void print(void)
{
    int i;
    for (i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

/* i열에 퀸을 배치 */
void set(int i)     /*i : 열*/
{
    int j;      /*j : 행*/
    for (j = 0; j < 8; j++)
    {
        pos[i] = j;
        if (i == 7)
            print();
        else
            set(i + 1);
    }
}

int main()
{
    set(0);
    return (0);
}