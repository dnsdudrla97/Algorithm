/* 커서에 의한 선형 리스트의 사용 예 */
#include <stdio.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- 메뉴 ---*/
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void)
{
	int i, ch;
	char *mstring[] = {
		"머리에 노드를 삽입",    "말미에 노드를 삽입",    "머리노드를 삭제",
		"꼬리노드를 삭제",       "주목노드를 출력",     "주목노드를 삭제",
		"번호로 검색",           "이름으로 검색",         "모든 노드를 출력",
		"모든 노드를 삭제",
	};

	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18.18s  ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("( 0) 종료 : ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > CLEAR);

	return (Menu)ch;
}

/*--- 메인 ---*/
int main(void)
{
	Menu menu;
	List list;
	
	Initialize(&list, 30);              /* 선형 리스트 초기화 */

	do {
		Member x;
		switch (menu = SelectMenu()) {
		
		/* 머리에 노드를 삽입 */
		case INS_FRONT:
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;
		
		/* 말미에 노드를 삽입 */
		case INS_REAR:
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;
		
		/* 머리노드를 삭제 */
		case RMV_FRONT:
			RemoveFront(&list);
			break;
		
		/* 꼬리노드를 삭제 */
		case RMV_REAR:
			RemoveRear(&list);
			break;
		
		/* 주목노드의 데이터를 출력 */
		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;
		
		/* 주목노드를 삭제 */
		case RMV_CRNT:
			RemoveCurrent(&list);
			break;
		
		/* 번호로 검색 */
		case SRCH_NO:
			x = ScanMember("검색", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 번호의 데이터가 없습니다.");
			break;
		
		/* 이름으로 검색 */
		case SRCH_NAME:
			x = ScanMember("검색", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 이름의 데이터가 없습니다.");
			break;
		
		/* 모든 노드의 데이터를 출력 */
		case PRINT_ALL:
			Print(&list);
			break;
		
		/* 모든 노드를 삭제 */
		case CLEAR:
			Clear(&list);
			break;
		}
	} while (menu != TERMINATE);
	
	Terminate(&list);                /* 선형 리스트의 뒤처리 */
	
	return 0;
}