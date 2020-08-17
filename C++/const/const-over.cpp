#include <stdio.h>

int strlength(char *s)
{
    puts("char *");
    return 0;
}

int strlength(const char *s)
{
    puts("const char *");
    return 0;
}
/*

int strlength(char * const s)

{

     puts("const char *");

     return 0;

}

//*/
void main()
{
    char str1[] = "1234";
    const char *str2 = "가나다라";
    char *const str3 = "abcd";

    strlength(str1);

    strlength(str2);

    strlength(str3);
}