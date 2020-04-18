#include <stdio.h>
#include <string.h>

char* str_rchr(const char* s, int c)
{
    const char* p = NULL;
    while (1)
    {
        if (*s == c) p = s;
        else if (*s == '\0') break;
        s++;
    }
    return (char*)p;
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

    find = str_rchr(origin, ch);
    printf("finded : %c\nindex : %d", *find, (find - origin) + 1);

    return 0;
}