/* 체인법으로 구현한 해시(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/*--- 해시 함수(key의 해시 값을 반환) ---*/
static int hash(int key, int size)
{
	return key % size;
}

/*--- 노드의 각 멤버에 값을 설정 ----*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
	n->data = *x;				/* 데이터 */
	n->next = next;				/* 다음 노드에 대한 포인터 */
}

/*--- 해시 테이블 초기화 ---*/
int Initialize(ChainHash *h, int size)
{
	int i;
	
	if ((h->table = calloc(size, sizeof(Node *))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (i = 0; i < size; i++)	/* 모든 버킷을 공백(NULL) 상태로 만듭니다. */
		h->table[i] = NULL;
	
	return 1;
}

/*--- 검색 ---*/
Node *Search(const ChainHash *h, const Member *x)
{
	int key = hash(x->no, h->size);		/* 검색하는 데이터의 해시 값 */
	Node *p = h->table[key];			/* 현재 선택한 노드 */
	
	while (p != NULL) {
		if (p->data.no == x->no)		/* 검색 성공 */
			return p;
		p = p->next;					/* 다음 노드를 선택 */
	}

	return NULL; /* 검색 실패 */
}

/*--- 데이터 추가 ---*/
int Add(ChainHash *h, const Member *x)
{
	int key = hash(x->no, h->size);		/* 추가하는 데이터의 해시 값 */
	Node *p = h->table[key];			/* 현재 선택한 노드 */
	Node *temp;
	
	while (p != NULL) {
		if (p->data.no == x->no)		/* 이 키는 이미 등록됨 */
			return 1;					/* 추가 실패 */
		p = p->next;					/* 다음 노드를 선택 */
	}
	
	if ((temp = calloc(1, sizeof(Node))) == NULL)
		return 2;
	
	SetNode(temp, x, h->table[key]);	/* 추가하는 노드에 값을 설정 */
	h->table[key] = temp;
	
	return 0; /* 추가 성공 */
}

/*--- 데이터 삭제 ---*/
int Remove(ChainHash *h, const Member *x)
{
	int key = hash(x->no, h->size);		/* 삭제하는 데이터의 해시 값 */
	Node *p = h->table[key];			/* 현재 선택한 노드 */
	Node **pp = &h->table[key];			/* 현재 선택한 노드에 대한 포인터 */
	
	while (p != NULL) {
		if (p->data.no == x->no) {		/* 찾으면 */
			*pp = p->next;
			free(p);					/* 해제 */
			return 0;					/* 삭제 성공 */
		}
		
		pp = &p->next;
		p = p->next;					/* 다음 노드를 선택 */
	}
	return 1;							/* 삭제 실패(존재하지 않음) */
}

/*--- 해시 테이블 덤프 ---*/
void Dump(const ChainHash *h)
{
	int i;
	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];
		printf("%02d ", i);
		
		while (p != NULL) {
			printf("→ %d :(%s) ", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ChainHash *h)
{
	int i;
	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];			/* 현재 선택한 노드 */
		
		while (p != NULL) {
			Node *next = p->next;
			free(p);					/* 현재 선택한 노드의 메모리 해제 */
			p = next;					/* 다음 노드 선택 */
		}
		h->table[i] = NULL;
	}
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash *h)
{
	Clear(h);						/* 모든 데이터 삭제 */
	free(h->table);					/* 해시 테이블 배열의 메모리 해제 */
	h->size = 0;					/* 해시 테이블 크기를 0으로 초기화(clear) */
}