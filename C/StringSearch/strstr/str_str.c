#include <stdio.h>
#include <string.h>
#include <limits.h>

char* bm_match_str(const char* txt, const char* pat) {
    int pt;
    int pp;
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int skip[UCHAR_MAX + 1];

    /*reset is pat_len*/
    for (pt = 0; pt <= UCHAR_MAX; pt++)
        skip[pt] = pat_len;
    
    for (pt = 0; pt < pat_len - 1; pt++)
        skip[pat[pt]] = pat_len - pt - 1;
    
    while (pt < txt_len) {
        pp = pat_len - 1;

        while (pat[pp] == txt[pt]) {
            if (pp == 0)
                return (char*)&txt[pt];
            pp--;
            pt--;
        }

        pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
    }  
    return NULL;
}


int main(void)
{
    char s1[256], s2[256];
    char* p;
    puts("strstr 함수");
    printf("텍스트 : ");
    scanf("%s", s1);
    printf("패턴 : ");
    scanf("%s", s2);
    p = bm_match_str(s1, s2);

    if (p == NULL)
        printf("텍스트에 패턴이 없다.\n");
    else {
        int ofs = p - s1;
        printf("\n%s\n", s1);
        printf("%*s|\n", ofs, "");
        printf("%*s%s\n", ofs, "", s2);
        
    }
}