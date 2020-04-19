#include <stdio.h>

int bf_matchr(const char plainText[], const char pattern[])
{
    int pt = 0;
    int pp = 0;
    int tmp = 0;

    while (plainText[pt] != '\0' && pattern[pp] != '\0')
    {
        if (plainText[pt] == pattern[pp])
        {
            pt++;
            pp++;
        } else {
            pt = pt - pp + 1;
            pp = 0;
        
        }
        if (pattern[pp] == '\0') {
            tmp = pt - pp;
            pp = 0;
        }
    }
    return tmp;
}

int main(void)
{
    int idx;
    char s1[256];
    char s2[256];
    puts("bruteforce");
    printf("text : ");
    scanf("%s", s1);
    printf("pattern : ");
    scanf("%s", s2);

    printf("PlainText : %s\npattern : %s\nlocated : %d\n",s1, s2, bf_matchr(s1, s2));
    return 0;
}