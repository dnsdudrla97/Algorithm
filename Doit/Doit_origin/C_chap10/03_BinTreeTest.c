/* �����˻�Ʈ���� ����ϴ� ���α׷� */
#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

/*--- �޴� ---*/
typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

/*--- �޴� ���� ---*/
Menu SelectMenu(void)
{
	int ch;
	do {
		printf("(1) ���� (2) ���� (3) �˻� (4) ��� (0) ���� : ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > PRINT);
	return (Menu)ch;
}

/*--- ���� �Լ� ---*/
int main(void)
{
	Menu menu;
	BinNode *root = NULL;	/* �����˻�Ʈ���� �Ѹ� ��� ������ */
	do {
		Member x;
		BinNode *temp;
		switch (menu = SelectMenu()) {
		
		/*--- ��带 ���� ---*/
		case ADD:
			x = ScanMember("����", MEMBER_NO | MEMBER_NAME);
			root = Add(root, &x);
			break;
		
		/*--- ��带 ���� ---*/
		case REMOVE:
			x = ScanMember("����", MEMBER_NO);
			Remove(&root, &x);
			break;
		
		/*--- ��带 �˻� ---*/
		case SEARCH:
			x = ScanMember("�˻�", MEMBER_NO);
			if ((temp = Search(root, &x)) != NULL)
				PrintLnMember(&temp->data);
			break;
		
		/*--- ��� ��带 ��� ---*/
		case PRINT:
			puts("�� ��� ��� ��� ��");
			PrintTree(root);
			break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);
	
	return 0;
}