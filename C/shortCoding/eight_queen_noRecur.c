#include <stdio.h>

/* 
1. 각 열에 하나의 퀸 존재
2. 각 행에 하나의 퀸 존재
3. 퀸 위치에서 대각선 방향에 도 없어야하마

*/

int queenPos[];
void print();


int set(int i)
{
    for (; i < 8; i++)
    {
        for (int j = 0; j < 8; i++)
        {
            queenPos[i] = j;
            if (i == 7) print();
        }
    }
}

int main()
{
    set(0);
    return (0);
}