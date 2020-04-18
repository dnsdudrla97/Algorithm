/*char 'F' to search */
#include <stdio.h>

int str_chr(const char *s, int c)
{
    int i = 0;
    c = (char)c;
    while (s[i] != c)
    {
        if (s[i] == '\0') /*Search Failed*/
            return -1;
        i++;
    }
    return i; /*Search Succeed*/
}

int main(void)
{
    char str[64]; /*검색 대상*/
    char tmp[64];
    int ch; /*검색할 문자*/
    int idx;

    printf("문자열 : ");
    scanf("%s", str);

    printf("검색할 문자 : ");
    scanf("%s", tmp); /*먼저 문자열로 검색할 문자를 읽어 들인다.*/
    ch = tmp[0];      /*첫 번째 문자를 검색할 문자로 지정한다.*/

    if ((idx = str_chr(str, ch)) == -1) /*처음 나오는 문자를 검색*/
        printf("문자 '%c'은 문자열에 없다.\n", ch);
    else
        printf("문자 '%c'은 %d번째에 있다.\n", ch, idx + 1);

    return 0;
}