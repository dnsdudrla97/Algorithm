/* 문자열 비교하는 프로그램 (strncmp 함수 사용) */
#include <stdio.h>
#include <string.h>

int main(void)
{
	char st[128];
	puts("\"STRING\"의 처음 3개의 문자와 비교합니다.");
	puts("\"XXXX\"를 입력하면 마칩니다.");

	while (1) {
		printf("문자열 st : ");
		scanf("%s", st);

		if (strncmp("XXXX", st, 3) == 0)
			break;

		printf("strncmp(\"STRING\", st, 3) = %d\n", strncmp("STRING", st, 3));
	}

	return 0;
}