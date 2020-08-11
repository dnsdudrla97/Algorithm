#include <stdio.h>
#include "MemberTwo.h"
#include "CloseHash.h"

/*--- 메뉴 ---*/
typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void)
{
	int ch;
	do {
		printf("(1)추가 (2)삭제 (3)검색 (4)모두 삭제 (5)덤프 (0)종료 : ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > DUMP);

	return(Menu)ch;
}

/*--- 메인 ---*/
int main(void)
{
	Menu menu;				/* 메뉴 */
	ClosedHash hash;		/* 해시 테이블 */
	Initialize(&hash, 13);	/* 해시 테이블 초기화 */
	
	do {
		int result;
		Member x;
		Bucket *temp;
		
		switch (menu = SelectMenu()) {
		case ADD: /*--- 데이터 추가 ---*/
			x = ScanMember("추가", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result)
				printf("\a오류 : 추가에 실패했습니다(%s).\n",
				(result == 1) ? "등록 마침" : "메모리 부족");
			break;
		
		case DELETE: /*--- 데이터 삭제 ---*/
			x = ScanMember("삭제", MEMBER_NAME);
			result = Remove(&hash, &x);
			if (result == 1)
				printf("\a오류 : 이 번호의 데이터는 존재하지 않습니다.\n");
			break;
		
		case SEARCH: /*--- 데이터 검색 ---*/
			x = ScanMember("검색", MEMBER_NAME);
			temp = Search(&hash, &x);
			if (temp == NULL)
				printf("\a검색에 실패했습니다.\n");
			else {
				printf("검색에 성공했습니다. : ");
				PrintLnMember(&temp->data);
			}
			break;
		
		case CLEAR: /*--- 모든 데이터 삭제 ---*/
			Clear(&hash);
			break;
		
		case DUMP: /*--- 해시 테이블 덤프 ---*/
			Dump(&hash);
			break;
        default:
            break;
		}
        
	} while (menu != TERMINATE);
	
	Terminate(&hash); /* 해시 테이블 종료 */
	
	return 0;
}