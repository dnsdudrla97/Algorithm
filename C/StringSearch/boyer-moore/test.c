int bm_match(const char txt[], const char pat[])
{
	int pt;										/* txt 커서 */
	int pp;										/* pat 커서 */
	int txt_len = strlen(txt);					/* txt 문자 개수 */
	int pat_len = strlen(pat);					/* pat 문자 개수 */
	int skip[UCHAR_MAX + 1];					/* 건너뛰기 표 */
	
	for (pt = 0; pt <= UCHAR_MAX; pt++)			/* 건너뛰기 표 만들기 */
		skip[pt] = pat_len;
	
	for (pt = 0; pt < pat_len - 1; pt++)
		skip[pat[pt]] = pat_len - pt - 1;		/* pt == pat_len - 1 */
	
	while (pt < txt_len) {
		pp = pat_len - 1; 			/* pat의 마지막 문자부터 검사합니다. */
		
		while (txt[pt] == pat[pp]) {
			if (pp == 0)
				return pt;
			pp--;
			pt--;
		}
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
	}

	return -1;
}