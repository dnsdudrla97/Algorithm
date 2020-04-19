#include <stdio.h>

int bf_match_flow(const char plainText[], const char pattern[])
{
    int pt = 0;
    int pp = 0;
    int k =  -1;
    int count = 0;
    while (plainText[pt] != '\0' && pattern[pp] != '\0') {
        if (k == pt - pp) {
            printf("   ");
        } else {
            printf("%d  ",pt - pp);
            k = pt - pp;
        }
        // printf("%d  %s\n", count, plainText);
        printf("%s\n", plainText);
        // putchar('\n');
        if (plainText[pt] == pattern[pp]) {
            pt++;
            pp++;
            printf("   %*s", count + pp - 1, "");
            printf("%c\n",'+');

            printf("   %*s", count,"");
            printf("%s\n", pattern);
        } else {
            count = pt = pt - pp + 1;
            printf("   %*s", count + pp - 1, "");
            printf("%c\n",'|');
            pp = 0;
            printf("   %*s", count - 1,"");
            printf("%s\n", pattern);
        }
        // putchar('\n');

    }
    if (pattern[pp] == '\0')
        return pt - pp;
    return -1;
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

    bf_match_flow(s1, s2);
    return 0;
}