/* 커서에 의한 선형 리스트(소스부) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- 삽입할 레코드의 인덱스를 구한다. ---*/
static Index GetIndex(List *list)
{
	if (list->deleted == NULL)        /* 삭제할 레코드가 없는 경우 */
		return ++(list->max);
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

/*--- 지정된 레코드를 삭제 리스트에 등록한다. ---*/
static void DeleteIndex(List *list, Index idx)
{
	if (list->deleted == NULL) {       /* 삭제할 레코드가 없는 경우 */
		list->deleted = idx;
		list->n[idx].Dnext = NULL;
	}
	else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

/*--- n이 가리키는 노드의 각 멤버에 값을 설정 ----*/
static void SetNode(Node *n, const Member *x, Index next)
{
	n->data = *x;                  /* 데이터 */
	n->next = next;                /* 뒤쪽노드에 대한 포인터 */
}

/*--- 선형 리스트를 초기화(가장 큰 요소수는 size) ---*/
void Initialize(List *list, int size)
{
	list->n = calloc(size, sizeof(Node));
	list->head = NULL;			/* 머리노드 */
	list->crnt = NULL;			/* 주목노드 */
	list->max = NULL;
	list->deleted = NULL;
}

/*--- 함수 compare 의해 x와 같은 노드를 검색 ---*/
Index search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
	Index ptr = list->head;
	while (ptr != NULL) {
		if (compare(&list->n[ptr].data, x) == 0) {
			list->crnt = ptr;
			return ptr;             /* 검색 성공 */
		}
		ptr = list->n[ptr].next;
	}

	return NULL;                    /* 검색 실패 */
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List *list, const Member *x)
{
	Index ptr = list->head;
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List *list, const Member *x)
{
	if (list->head == NULL)           /* 비어있는 경우 */
		InsertFront(list, x);          /* 머리에 삽입 */
	else {
		Index ptr = list->head;
		while (list->n[ptr].next != NULL)
			ptr = list->n[ptr].next;
		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&list->n[list->n[ptr].next], x, NULL);
	}
}

/*--- 머리노드를 삭제 ---*/
void RemoveFront(List *list)
{
	if (list->head != NULL) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr;
	}
}

/*--- 꼬리노드를 삭제 ---*/
void RemoveRear(List *list)
{
	if (list->head != NULL) {
		if (list->n[list->head].next == NULL)	/* 노드가 하나만 있으면 */
			RemoveFront(list);					/* 머리노드를 삭제 */
		else {
			Index ptr = list->head;
			Index pre;
			while (list->n[ptr].next != NULL) {
				pre = ptr;
				ptr = list->n[ptr].next;
			}
			list->n[pre].next = NULL;
			DeleteIndex(list, ptr);
			list->crnt = pre;
		}
	}
}

/*--- 주목노드를 삭제 ---*/
void RemoveCurrent(List *list)
{
	if (list->head != NULL) {
		if (list->crnt == list->head)			/* 머리노드를 주목하고 있으면 */
			RemoveFront(list);					/* 머리노드를 삭제 */
		else {
			Index ptr = list->head;
			while (list->n[ptr].next != list->crnt)
				ptr = list->n[ptr].next;
			list->n[ptr].next = list->n[list->crnt].next;
			DeleteIndex(list, list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- 모든 노드를 삭제 ---*/
void Clear(List *list)
{
	while (list->head != NULL)				/* 텅 빌 때까지 */
		RemoveFront(list);					/* 머리노드를 삭제 */
	list->crnt = NULL;
}

/*--- 주목노드의 데이터를 출력 ---*/
void PrintCurrent(const List *list)
{
	if (list->crnt == NULL)
		printf("주목노드가 없습니다.");
	else
		PrintMember(&list->n[list->crnt].data);
}

/*--- 주목노드의 데이터를 출력(줄바꿈 문자 붙임) ---*/
void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 모든 노드의 데이터를 출력 ---*/
void Print(const List *list)
{
	if (list->head == NULL)
		puts("노드가 없습니다.");
	else {
		Index ptr = list->head;
		puts("【 모두 보기 】");
		while (ptr != NULL) {
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;              /* 뒤쪽노드 */
		}
	}
}

/*--- 선형 리스트의 뒤처리 ---*/
void Terminate(List *list)
{
	Clear(list); /* 모든 노드를 삭제 */
	free(list->n);
}