#include <stdio.h>
#include <stdlib.h>


/*
2차원 배열 동적 할당 생성 및 값 입력
*/
int main(void)
{
    int** m = malloc(sizeof(int*) * 3);

    for (int i = 0; i < 3; i++) 
        m[i] = malloc(sizeof(int) * 3);
    
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            m[i][j] = j;
            printf("m[%d][%d] = %d ", i, j, m[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i < 3; i++)    // 세로 크기만큼 반복
    {
        free(m[i]);                // 2차원 배열의 가로 공간 메모리 해제
    }
    
    
    
    return (0);

}