#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>

/*boyer-Moore법으로 문자열을 검색*/
int bm_match(const char txt[], const char pat[]) {
    int pt;                         /* txt 커서 */
    int pp;                         /* pat 커서 */
    int txt_len = strlen(txt);      /* txt 문자 개수 */
    int pat_len = strlen(pat);      /* pat 문자 개수 */
    int skip[UCHAR_MAX + 1];        /* 건너뛰기 표 */

    /*건너뛰기 표*/
    for (pt = 0; pt <= UCHAR_MAX; pt++)
        skip[pt] = pat_len;

    /*패턴에 들어 있는 문자를 만났을 경우 n - k - 1*/
    for (pt = 0; pt < pat_len - 1; pt++)
        skip[pat[pt]] = pat_len - pt - 1;

             /* pt == pat_len - 1 */
    /*pt, 초기값 = 위 for문 으로 변경된 값*/
    while (pt < txt_len) {
        pp = pat_len - 1;               /*패턴의 마지막 문자 부터 검사*/

        while (txt[pt] == pat[pp]) {
            if (pp == 0)
                return pt;
            pp--;
            pt--;
        }
        /*pt 커서 위치 변경*/
        /*건너뛰기 에 저장된 값 과 패턴 길이 - 현재 패턴 커서 위치 를 비교*/
        /*건너뛰기 값이 큰경우 해당 pt는 원래대로 해당 길이만큼 이동*/
        /*패턴 길이 - 현재 패턴 커서 위치 가 더큰 경우 건너뛰기 가 있는 경우 패턴 길이 - 패턴 을 통해 이동*/
        pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
    }
    return -1;
}

int main(void)
{
    int idx;
    char s1[256] = "ABCXDEZCABACABAC";
    char s2[256] = "ABAC";
    
    idx = bm_match(s1, s2);
    if (idx == -1)
        puts("텍스트에 패턴이 없다.");
    else
        printf("%d번째 문자부터 match 한다.\n", idx + 1);

    return 0;

}