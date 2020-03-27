/* 문자열 길이를 구하는 프로그램 */
#include <stdio.h>

/*--- 문자열 s의 길이를 구하는 함수(버전 1) ---*/
int str_len(const char *s)
{
	int len = 0;

	while (s[len]) 
		len++;

	return len;
}

int main(void)
{
	char str[256];

	printf("문자열 : ");
	scanf("%s", str);

	printf("이 문자열의 길이는 %d입니다.\n", str_len(str));

	return 0;
}