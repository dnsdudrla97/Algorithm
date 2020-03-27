/* 두 포인터 값을 서로 바꾸는 함수가 있는 프로그램 */
#include <stdio.h>

/*--- 두 포인터를 서로 바꾸는 함수 ---*/
void swap_ptr(char **x, char **y)
{
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(void)
{
	char *s1 = "ABCD";		/* s1은 "ABCD"의 첫 글자 'A'를 가리킵니다. */
	char *s2 = "EFGH";		/* s2는 "EFGH"의 첫 글자 'E'를 가리킵니다. */

	printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
	printf("포인터 s2는 \"%s\"를 가리킵니다.\n", s2);

	swap_ptr(&s1, &s2);

	puts("\n포인터 s1과 s2의 값을 서로 바꾸었습니다.\n");

	printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
	printf("포인터 s2는 \"%s\"를 가리킵니다.\n", s2);

	return 0;
}