#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm_match(char const txt[], char const pat[])
{
    int pt = 0;
    int pp = 0;
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int skip[UCHAR_MAX + 1];
    int i;

    for (pt; pt <= UCHAR_MAX; pt++)
        skip[pt] = pat_len - 1;
    
    /*n - k - 1*/
    for (pt = 0; pt < pat_len - 1; pt++)
        skip[pat[pt]] = pat_len - pt - 1;

    while (pt < txt_len)
    {
        pp = pat_len - 1;
        while (txt[pt] == pat[pp]) {
            if (pp == 0)
                return pt;
            pt--;
            pp--;
        }
        pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
    }
    return -1;
}




int main(void)
{
    return 0;
}