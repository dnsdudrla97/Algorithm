#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_2dstr(char *p, int n1, int n2)
{
    qsort(p, n1, n2, (int (*)(const void *, const void *))strcmp);
}

static int pstrcmp(const void *x, const void *y)
{
    return strcmp(*(const char **)x, *(const char **)y);
}

void sort_pvstr(char *p[], int n)
{
    qsort(p, n, sizeof(char *), pstrcmp);
}

int main(void)
{
    int i;
    puts("after sort");
    char a[][7] = {"LISP", "C", "Ada", "Pascal"};
    char *p[] = {"LISP", "C", "Ada", "Pasca"};

    sort_2dstr(&a[0][0], 4, 7);

    sort_pvstr(p, 4);

    puts("오름차순으로 정렬했습니다.");

    for (i = 0; i < 4; i++)
        printf("a[%d] = %s\n", i, a[i]);

    for (i = 0; i < 4; i++)
        printf("p[%d] = %s\n", i, p[i]);

    return 0;

    return (0);
}