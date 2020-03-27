/* 문자열에서 문자 검색하는 프로그램 */
#include <stdio.h>

/*--- 문자열 s에서 문자 c를 검색하는 함수 ---*/
int str_chr(const char *s, int c)
{
	int i = 0;
	c = (char)c;
	while (s[i] != c) {
		if (s[i] == '\0')		/* 검색 실패 */
			return -1;
		i++;
	}
	return i;			/* 검색 성공 */
}

int main(void)
{
	char str[64];	/* 이 문자열에서 검색*/
	char tmp[64];
	int ch;			/* 검색할 문자 */
	int idx;

	printf("문자열 : ");
	scanf("%s", str);

	printf("검색할 문자 : ");
	scanf("%s", tmp);		/* 먼저 문자열로 검색할 문자를 읽어 들입니다. */
	ch = tmp[0];			/* 첫 번째 문자를 검색할 문자로 지정합니다. */

	if ((idx = str_chr(str, ch)) == -1)		/* 처음 나오는 문자를 검색합니다. */
		printf("문자 '%c'는 문자열에 없습니다.\n", ch);
	else
		printf("문자 '%c'는(은) %d 번째에 있습니다.\n", ch, idx + 1);

	return 0;
}