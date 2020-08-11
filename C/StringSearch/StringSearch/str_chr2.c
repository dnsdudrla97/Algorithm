#include <stdio.h>

char *str_chr(const char *s, int c)
{
    while (*s != '\0') {
        c = (char)c;
        if (*s == c) return (char*)s;
        s++;
    }
    return (char*)s;
}

int main()
{
    char tmp[16];
    char origin[16];
    int ch;
    char *find;

    printf("origin string : ");
    scanf("%s", origin);

    printf("\nfind char : ");
    scanf("%s", tmp);
    ch = tmp[0];

    find = str_chr(origin, ch);
    printf("finded : %c\nindex : %d", *find, (find - origin) + 1);

    return 0;
}