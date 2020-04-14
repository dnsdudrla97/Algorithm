#include <stdio.h>

int f1 (int a, double b)
{
    return (1);
}

int f2 (int a, double b)
{
    return (2);
}

int (*SelectFunc(char ch))(int, double)
{
    if (ch == 'a') return f1;
    else return f2;
}

void main()
{
    int (*fp)(int, double);
    fp = SelectFunc('a');
    printf("returned = %d\n", fp(1, 2.3));
}

char (*func(char **buf, char *(*strf[9])(void), int *pi))(unsigned short,unsigned (**)(const char *));


