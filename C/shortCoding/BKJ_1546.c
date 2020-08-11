#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)
#define src 0

void QuickSort(int *s, int left, int right)
{
    int ql = left;
    int qr = right;
    int qc = s[(left + right) / 2];

    do
    {
        while (s[ql] < qc)
            ql++;
        while (s[qr] > qc)
            qr--;
        if (ql <= qr)
        {
            swap(int, s[ql], s[qr]);
            ql++;
            qr--;
        }
    } while (ql <= qr);

    if (qr - left > right - ql)
    {
        swap(int, qr, right);
        swap(int, left, ql);
    }

    if (left < qr)
        QuickSort(s, left, qr);
    if (right > ql)
        QuickSort(s, ql, right);
}

float ModifyAvg(int *s, int n)
{
    int i;
    float res = 0.0;
    int max = s[n - 1];
    for (i = 0; i < n; i++)
        res += ((float)s[i] / max * 100);
    return res /= (float)n;
}

int main()
{
    int *score;
    int num, i;

    if (scanf("%d", &num) == EOF || num > 1001)
        return 0;
    score = calloc(num, sizeof(int));
    for (i = 0; i < num; i++)
        if (scanf("%d", &score[i]) < 0 && score[i] > 101)
            return 0;
    QuickSort(score, src, num - 1);
    printf("%0.2f", ModifyAvg(score, num));
    free(score);
}