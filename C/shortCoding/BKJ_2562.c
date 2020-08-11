#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LIM 9
int main(void)
{
    int *N;
    int i, cnt = 0;
    N = calloc(LIM, sizeof(int));

    for (i = 0; i < LIM; i++)
        if (scanf("%d", &N[i]) > 100)
            break;
    int MAX = N[0], c = 0;
    while (c < 9) if (MAX < N[++c]) MAX = N[c];
    while (c--) if (MAX == N[c]) break;
    printf("%d\n%d",MAX,c+1);
    free(N);

    return 0;
}