#include<stdio.h>
#include "stackIn.h"
#include "hanoi.h"


// /*--- 원반[1] ~ 원반[no]를 x 기중에서 y기둥으로 옮김 --- */
// void move(int no, int x, int y)
// {
//     if (no > 1)
//         move(no - 1, x, 198 - x - y);     // 그룹을 시작 기중에서 중간 기중으로
//     printf("원반[%d]를(을) %c 기둥에서 %c 기둥으로 옮김\n", no, x, y);  // 바닥 원반을 목표 기둥으로

//     if (no > 1)
//         move(no - 1, 198 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로

// }

int main()
{
    int n;      // 원반의 개수
    printf("하노이의 탑\n원반 개수 :");
    scanf("%d", &n);
    move(n, 1, 3);

    return (0);
}