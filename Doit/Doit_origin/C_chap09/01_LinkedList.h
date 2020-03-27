/* 포인터를 사용한 선형 리스트(헤더) */
#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

/*--- 노드 ---*/
typedef struct __node {
	Member data;			/* 데이터 */
	struct __node *next;	/* 뒤쪽 포인터(뒤쪽 노드에 대한 포인터) */
} Node;

/*--- 선형 리스트 ---*/
typedef struct {
	Node *head;			/* 머리 노드에 대한 포인터 */
	Node *crnt;			/* 선택한 노드에 대한 포인터 */
} List;

/*--- 선형 리스트를 초기화 ---*/
void Initialize(List *list);

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y));

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List *list, const Member *x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List *list, const Member *x);

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List *list);

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List *list);

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(List *list);

/*--- 모든 노드를 삭제 ---*/
void Clear(List *list);

/*--- 선택한 노드의 데이터를 출력 ---*/
void PrintCurrent(const List *list);

/*--- 선택한 노드의 데이터를 출력(줄바꿈 문자 포함) ---*/
void PrintLnCurrent(const List *list);

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const List *list);

/*--- 선형 리스트 종료 ---*/
void Terminate(List *list);
#endif