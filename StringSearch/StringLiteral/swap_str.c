#include <stdio.h>
#include <stdlib.h>
void swap_str(char *a, char *b)
{
	char* temp;
	while (*a && *b)
	{
		char t = *a;
		*a++ = *b;
		*b++ = t;
	}

	if (*a)
	{
		temp = a;
		while (*a && 1) *b++ = *a++;
		*temp = *b = '\0';
	}
	else if (*b)
	{
		{
			temp = b;
			while (*b && 1) *a++ = *b++;
			*temp = *a = '\0';
		}
	}
}

int main(void)
{
	char s1[128];
	char s2[128];

	scanf("%s", s1);
	scanf("%s", s2);
	printf("문자열 S1 : %s\n", s1);
	printf("문자열 S2 : %s\n", s2);

	swap_str(s1, s2);

	printf("두 문자열을 교환했습니다.\n");
	printf("문자열 S1 : %s\n", s1);
	printf("문자열 S2 : %s\n", s2);

	return 0;
}