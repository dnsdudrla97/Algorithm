/* Ŀ���� ���� ���� ����Ʈ(�ҽ���) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- ������ ���ڵ��� �ε����� ���Ѵ�. ---*/
static Index GetIndex(List *list)
{
	if (list->deleted == NULL)        /* ������ ���ڵ尡 ���� ��� */
		return ++(list->max);
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

/*--- ������ ���ڵ带 ���� ����Ʈ�� ����Ѵ�. ---*/
static void DeleteIndex(List *list, Index idx)
{
	if (list->deleted == NULL) {       /* ������ ���ڵ尡 ���� ��� */
		list->deleted = idx;
		list->n[idx].Dnext = NULL;
	}
	else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

/*--- n�� ����Ű�� ����� �� ����� ���� ���� ----*/
static void SetNode(Node *n, const Member *x, Index next)
{
	n->data = *x;                  /* ������ */
	n->next = next;                /* ���ʳ�忡 ���� ������ */
}

/*--- ���� ����Ʈ�� �ʱ�ȭ(���� ū ��Ҽ��� size) ---*/
void Initialize(List *list, int size)
{
	list->n = calloc(size, sizeof(Node));
	list->head = NULL;			/* �Ӹ���� */
	list->crnt = NULL;			/* �ָ��� */
	list->max = NULL;
	list->deleted = NULL;
}

/*--- �Լ� compare ���� x�� ���� ��带 �˻� ---*/
Index search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
	Index ptr = list->head;
	while (ptr != NULL) {
		if (compare(&list->n[ptr].data, x) == 0) {
			list->crnt = ptr;
			return ptr;             /* �˻� ���� */
		}
		ptr = list->n[ptr].next;
	}

	return NULL;                    /* �˻� ���� */
}

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(List *list, const Member *x)
{
	Index ptr = list->head;
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr);
}

/*--- ������ ��带 ���� ---*/
void InsertRear(List *list, const Member *x)
{
	if (list->head == NULL)           /* ����ִ� ��� */
		InsertFront(list, x);          /* �Ӹ��� ���� */
	else {
		Index ptr = list->head;
		while (list->n[ptr].next != NULL)
			ptr = list->n[ptr].next;
		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&list->n[list->n[ptr].next], x, NULL);
	}
}

/*--- �Ӹ���带 ���� ---*/
void RemoveFront(List *list)
{
	if (list->head != NULL) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr;
	}
}

/*--- ������带 ���� ---*/
void RemoveRear(List *list)
{
	if (list->head != NULL) {
		if (list->n[list->head].next == NULL)	/* ��尡 �ϳ��� ������ */
			RemoveFront(list);					/* �Ӹ���带 ���� */
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

/*--- �ָ��带 ���� ---*/
void RemoveCurrent(List *list)
{
	if (list->head != NULL) {
		if (list->crnt == list->head)			/* �Ӹ���带 �ָ��ϰ� ������ */
			RemoveFront(list);					/* �Ӹ���带 ���� */
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

/*--- ��� ��带 ���� ---*/
void Clear(List *list)
{
	while (list->head != NULL)				/* �� �� ������ */
		RemoveFront(list);					/* �Ӹ���带 ���� */
	list->crnt = NULL;
}

/*--- �ָ����� �����͸� ��� ---*/
void PrintCurrent(const List *list)
{
	if (list->crnt == NULL)
		printf("�ָ��尡 �����ϴ�.");
	else
		PrintMember(&list->n[list->crnt].data);
}

/*--- �ָ����� �����͸� ���(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- ��� ����� �����͸� ��� ---*/
void Print(const List *list)
{
	if (list->head == NULL)
		puts("��尡 �����ϴ�.");
	else {
		Index ptr = list->head;
		puts("�� ��� ���� ��");
		while (ptr != NULL) {
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;              /* ���ʳ�� */
		}
	}
}

/*--- ���� ����Ʈ�� ��ó�� ---*/
void Terminate(List *list)
{
	Clear(list); /* ��� ��带 ���� */
	free(list->n);
}