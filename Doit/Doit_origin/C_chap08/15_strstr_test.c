/* strstr �Լ��� ����� ���α׷� */
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[256], s2[256];
	char *p;
	
	puts("strstr �Լ�");
	printf("�ؽ�Ʈ : ");
	scanf("%s", s1);
	printf("���� : ");
	scanf("%s", s2);

	p = strstr(s1, s2); 		/* ���ڿ� s1���� ���ڿ� s2�� �˻� */

	if (p == NULL)
		printf("�ؽ�Ʈ�� ������ �����ϴ�.\n");
	else {
		int ofs = p - s1;
		printf("\n%s\n", s1);
		printf("%*s|\n", ofs, "");
		printf("%*s%s\n", ofs, "", s2);
	}

	return 0;
}