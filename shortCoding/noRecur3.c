#include <stdio.h>
#include "stackIn.h"
/* recur */
// void recur3(int n)
// {
//     if (n > 0)
//     {
//         recur3(n - 1);
//         recur3(n - 2);
//         printf("%d\n", n);
//     }
// }

// int main()
// {
//     printf("정수입력 : ");
//     int n;
//     scanf("%d", &n);
//     recur3(n);

//     return (0);   
// }
/* do recur */

void recur3(int n)
{
    int sw = 0;
    t_stack ssdk, ndsk;

    Init(&ndsk, 100);
    Init(&ssdk, 100);

    while(1)
    {   
        if (n > 0)
        {
            Push(&ndsk, n);
            Push(&ssdk, sw);
            if (sw == 0)
            {
                n = n - 1;
            } else if (sw == 1) {
                n = n - 2;
            }
            continue;
        }
        do {
            Pop(&ssdk, &sw);
            Pop(&ndsk, &n);
            sw++;
            if (sw == 2)
            {
                printf("%d\n", n);
                return;
            }
            
        } while(sw == 2);
    }
    Terminate(&ssdk);
    Terminate(&ndsk);
}

int main()
{
    printf("??? ????? : ");
    int n;
    scanf("%d", &n);
    recur3(n);

    return (0);   
}