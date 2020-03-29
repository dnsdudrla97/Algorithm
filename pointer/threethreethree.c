/*
3차원 동적 배열 ㄱㄱ
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int z, x, y;
    printf("Z X Y : ");
    scanf("%d %d %d", &z, &x, &y);
    printf("-------------------------\n");
    
    int*** th =  malloc(sizeof(int** ) * z);

    for (int i = 0; i < x; i++) {
        th[i] = malloc(sizeof(int* ) * x);
        for (int j = 0; j < y; j++) {
            th[i][j] = malloc(sizeof(int ) * y);
        }
    }
    
    int ab = 10;
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                th[i][j][k] = ab;
            }
        }
        
    }

    // 
    printf("%d \n",th[1][1][1]);

     for (int i = 0; i < z; i++) {
        for (int j = 0; j < x; j++) {
            free(th[i][j]);
            for (int k = 0; k < y; k++) {
                free(th[k]);
            }
        }
    }

    return (0);

}