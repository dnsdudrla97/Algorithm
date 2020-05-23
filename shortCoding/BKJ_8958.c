#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LIM 80

void Init(int *next, int *rst)
{
    *next = 0, *rst = 0;
}

void Terminate(char **MainQuiz, int N)
{
    int i;
    for (i = 0; i < N; i++)
        free(MainQuiz[i]);
    free(MainQuiz);
}
void Print(int *cnt, int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d\n", cnt[i]);
}

int main()
{
    int N, i, next = 0, rst = 0;
    scanf("%d", &N);

    int *cnt = calloc(N, sizeof(int));
    char **MainQuiz = calloc(N, sizeof(char *));
    char *ptr = NULL;

    for (i = 0; i < N; i++)
    {
        MainQuiz[i] = calloc(LIM, sizeof(char));
        scanf("%s", MainQuiz[i]);
        ptr = *(MainQuiz + i);
        while (1)
        {
            if (*(ptr + next) != '\0')
            {
                if (*(ptr + next) == 'O')
                {
                    rst++;
                    cnt[i] += rst;
                }
                else
                    rst = 0;
                next++;
            }
            else
                break;
        }
        Init(&next, &rst);
    }
    Print(cnt, N);
    Terminate(MainQuiz, N);
    return 0;
}