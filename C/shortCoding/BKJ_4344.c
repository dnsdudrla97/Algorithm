#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Nc, i, j, Ns, sum = 0;
    int mavg = 0;

    scanf("%d", &Nc);
    int **HELP = calloc(Nc, sizeof(int *));
    float *avg = calloc(Nc, sizeof(float));
    for (i = 0; i < Nc; i++)
    {
        mavg = 0, sum = 0;
        scanf("%d", &Ns);
        HELP[i] = calloc(Ns, sizeof(int));

        for (j = 0; j < Ns; j++)
        {
            if (scanf("%d", &HELP[i][j]) < 1 || HELP[i][j] > 1001)
            {
                return 0;
            }
            else
            {
                sum += HELP[i][j];
            }
        }
        sum /= Ns;
        for (j = 0; j < Ns; j++)
            if (HELP[i][j] > sum)
                mavg++;
        avg[i] = (float)mavg / Ns * 100;
    }

    for (i = 0; i < Nc; i++)
    {
        printf("%0.3f%%\n", avg[i]);
    }

    for (i = 0; i < Nc; i++)
        free(HELP[i]);

    free(avg);
    free(HELP);
    return 0;
}