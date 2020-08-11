#include <stdio.h>

/*문자열 s의 길이*/
size_t str_len (const char* s)
{
    size_t len = 0;

    while (s[len]) len++;
    return len;
}

size_t str_len2 (const char* s)
{
    size_t len = 0;

    while(*s++) len++;
    return len;
}

size_t str_len3 (const char* s)
{
    const char *p = s;
    while (*s) s++;
    return s - p;
}

int main(void)
{
    char str[256];
    printf("string : ");
    scanf("%s", str);
    printf("string len : %d\n", str_len(str));
    printf("string len2 : %d\n", str_len2(str));
    printf("string len3 : %d\n", str_len3(str));

    return 0;
}