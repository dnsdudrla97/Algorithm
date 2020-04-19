#include <stdio.h>

int str_ncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && *s2)
    {
        if (*s1 != *s2)
            return (unsigned char)*s1 - (unsigned char)*s2;
        s1++;
        s2++;
        n--;
    }
    if (!n) return 0;        /*n이 끝나고 문자열이 아직 남아있는 상태 즉, 두 문자열이 n길이에 동일한 상태 임으로 0을 반환*/
    if (*s1) return 1;       /* *s1이 남아 있는 상태에서는 해당 반환값 1*/
    return -1;              /* *s2이 남아 있는 상태에서는 해당 반환값 -1*/
}

int main(void)
{
    char st[128];

    puts("\"STRING\"의 처음 세 문자와 비교합니다.");
    puts("\"XXXX\"이면 종료합니다.");

    while (1)
    {
        printf("문자열：");
        scanf("%s", st);

        if (str_ncmp("XXXX", st, 3) == 0)
            break;
        printf("str_ncmp(\"STRING\", st, 3) = %d\n", str_ncmp("STRING", st, 3));
    }

    return 0;
}
