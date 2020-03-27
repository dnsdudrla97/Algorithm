#include <stdio.h>
#include "stackIn.h"

// /*--- 원반[1] ~ 원반[no]를 x 기중에서 y기둥으로 옮김 --- */
// void move(int no, int x, int y)
// {
//     if (no > 1)
//         move(no - 1, x, 6 - x - y);     // 그룹을 시작 기중에서 중간 기중으로
//     printf("원반[%d]를(을) %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);  // 바닥 원반을 목표 기둥으로

//     if (no > 1)
//         move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로move(no - 1, 6 - x - y, y);     // 그룹을 중간 기둥에서 목표 기둥으로

// }

void move(int no, int x, int y)
{
    int sw = 0;
    t_stack x1, y1, s1;    

    Init(&s1, 100);
    Init(&x1, 100);
    Init(&y1, 100);

    while (1)
    {
        if (sw == 0 && no > 1)
        {
            Push(&x1, x);
            Push(&y1, y);
            Push(&s1, sw);
            no = no - 1;
            y = 6 - x - y;
            continue;
        }

        printf("원반[%d]를(을) %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);

        if (sw == 1 && no > 1)
        {
            Push(&x1, x);
            Push(&y1, y);
            Push(&s1, sw);
            no = no - 1;
            x = 6 - x - y;
            if (++sw == 2) sw = 0;
            continue;
        }
        do {
            if (IsEmpty(&x1))
                return;
            Pop(&x1, &x);
            Pop(&y1, &y);
            Pop(&s1, &sw);
            sw++;
            no++;
        } while (sw == 2);
    }
    
    Terminate(&y1);
    Terminate(&x1);
    Terminate(&s1);
}
