#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define DIV 10
#define CMPDIV 42
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

void set(int *a, int n)
{

    int i, j, k, l;
    for (i = 0; i < n - 1; i++)
    {
        int exchg = 0;

        for (j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                exchg++;
                swap(int, a[j - 1], a[j]);
            }
        }
        if (exchg == 0)
            break;
    }
}

/*filter*/
static void Filter(int *t_array)
{
    int i;
    for (i = 0; i < DIV; i++)
        t_array[i] %= CMPDIV;
}

int Cmp(int *t_array)
{
    int i, j, cnt = 0;

    for (i = 0; i < DIV; i++)
    {
        for (j = i + 1; j < DIV; j++)
        {
            if (t_array[i] == t_array[j])
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int *t = calloc(DIV, sizeof(int));
    int i;
    for (i = 0; i < DIV; i++)
        if ((scanf("%d", &t[i]) == EOF) || (t[i] > 1001 || t[i] < 0))
            return 0;
    set(t, DIV);
    Filter(t);
    printf("%d", DIV - Cmp(t));

    free(t);
    return 0;
}
