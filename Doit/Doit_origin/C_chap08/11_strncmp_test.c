/* ���ڿ� ���ϴ� ���α׷� (strncmp �Լ� ���) */
#include <stdio.h>
#include <string.h>

int main(void)
{
	char st[128];
	puts("\"STRING\"�� ó�� 3���� ���ڿ� ���մϴ�.");
	puts("\"XXXX\"�� �Է��ϸ� ��Ĩ�ϴ�.");

	while (1) {
		printf("���ڿ� st : ");
		scanf("%s", st);

		if (strncmp("XXXX", st, 3) == 0)
			break;

		printf("strncmp(\"STRING\", st, 3) = %d\n", strncmp("STRING", st, 3));
	}

	return 0;
}