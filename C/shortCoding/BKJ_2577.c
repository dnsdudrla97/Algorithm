#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LIM 9
#define DIV 10
#define CMPR 997,002,999
#define CMPL 1000000

/*len*/
int Len(int l) {
    int cnt;
    for (cnt = 0; l/10 != 0; cnt++) l /= 10;
    return cnt;
}
/*filter*/
static void Filter(int *t_array, int res, int len)
{
    int i = 0;
    for (i = 0; i <= len; i++) {
        t_array[i] = res % DIV;
        res /= DIV;
    }
}
/*frequecny*/
static void Frequency(int *f_array, int *t_array, int len)
{
    int i;
    for (i = 0; i <= len; i++) f_array[t_array[i]]++;
}
/*print*/
static void Print(int *f_array)
{
    int i;
    for (i = 0; i <= LIM; i++) printf("%d\n", f_array[i]);
}


int main()
{
    int A, B, C, res;
    int *t = calloc(10, sizeof(int));
    int *f = calloc(10, sizeof(int));

    if (scanf("%d %d %d", &A, &B, &C) == EOF) return 0;    
    
    res = A*B*C;
    if (res >= CMPL && res < CMPR) {    
        int len = Len(res);
        Filter(t, res, len);
        Frequency(f, t, len);
        Print(f);
        free(t);
        free(f);
    } else return 0;
}