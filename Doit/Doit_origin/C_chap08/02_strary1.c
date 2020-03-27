/* 저장한 문자열을 출력합니다. */
#include <stdio.h>

int main(void)
{
	char st[10];

	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\0';
	
	printf("문자열 st에는 \"%s\"가 들어있습니다.\n", st);

	return 0;
}