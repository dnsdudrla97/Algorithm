#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void RootKit(int* r, int* pos) {
   bool a = true;
    for (int cnt = 0; cnt < 10000; cnt++) {
        for (int chk = cnt; chk < 10000; chk++) {
            if (cnt == pos[chk]) {
                a = false;
                break;
            }            
        }
        if (a) r[cnt] = cnt;
        else a = true;

    }
}

void Kaprekar(int n, int* pos, int index)
{
    if (n <= 10000) {
        int origin = n;
        int* tmp = calloc(7, sizeof(int));
        int sum = 0, t_index = 0, rst = 0;

        tmp[t_index++] = origin;
        while (1) {
            rst = origin % 10;
            tmp[t_index++] = rst;      
            origin /= 10;
            if (origin == 0) break;
        }

        for (int i = 0; i < t_index; i++)
            sum += tmp[i];

        pos[index++] = sum;

        free(tmp);
        Kaprekar(sum, pos, index);
    }
}

int main()
{
    int* position = calloc(10000, sizeof(int));
    int* root = calloc(10000, sizeof(int));
    Kaprekar(1, position, 0);
    RootKit(root, position);
    
    for (int i = 0; i < 10000; i++) {
        printf("%d\n", root[i]);
    }
    

    return 0;
}