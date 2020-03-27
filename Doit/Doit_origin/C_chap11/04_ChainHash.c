/* ü�ι����� ������ �ؽ�(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/*--- �ؽ� �Լ�(key�� �ؽ� ���� ��ȯ) ---*/
static int hash(int key, int size)
{
	return key % size;
}

/*--- ����� �� ����� ���� ���� ----*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
	n->data = *x;				/* ������ */
	n->next = next;				/* ���� ��忡 ���� ������ */
}

/*--- �ؽ� ���̺� �ʱ�ȭ ---*/
int Initialize(ChainHash *h, int size)
{
	int i;
	
	if ((h->table = calloc(size, sizeof(Node *))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (i = 0; i < size; i++)	/* ��� ��Ŷ�� ����(NULL) ���·� ����ϴ�. */
		h->table[i] = NULL;
	
	return 1;
}

/*--- �˻� ---*/
Node *Search(const ChainHash *h, const Member *x)
{
	int key = hash(x->no, h->size);		/* �˻��ϴ� �������� �ؽ� �� */
	Node *p = h->table[key];			/* ���� ������ ��� */
	
	while (p != NULL) {
		if (p->data.no == x->no)		/* �˻� ���� */
			return p;
		p = p->next;					/* ���� ��带 ���� */
	}

	return NULL; /* �˻� ���� */
}

/*--- ������ �߰� ---*/
int Add(ChainHash *h, const Member *x)
{
	int key = hash(x->no, h->size);		/* �߰��ϴ� �������� �ؽ� �� */
	Node *p = h->table[key];			/* ���� ������ ��� */
	Node *temp;
	
	while (p != NULL) {
		if (p->data.no == x->no)		/* �� Ű�� �̹� ��ϵ� */
			return 1;					/* �߰� ���� */
		p = p->next;					/* ���� ��带 ���� */
	}
	
	if ((temp = calloc(1, sizeof(Node))) == NULL)
		return 2;
	
	SetNode(temp, x, h->table[key]);	/* �߰��ϴ� ��忡 ���� ���� */
	h->table[key] = temp;
	
	return 0; /* �߰� ���� */
}

/*--- ������ ���� ---*/
int Remove(ChainHash *h, const Member *x)
{
	int key = hash(x->no, h->size);		/* �����ϴ� �������� �ؽ� �� */
	Node *p = h->table[key];			/* ���� ������ ��� */
	Node **pp = &h->table[key];			/* ���� ������ ��忡 ���� ������ */
	
	while (p != NULL) {
		if (p->data.no == x->no) {		/* ã���� */
			*pp = p->next;
			free(p);					/* ���� */
			return 0;					/* ���� ���� */
		}
		
		pp = &p->next;
		p = p->next;					/* ���� ��带 ���� */
	}
	return 1;							/* ���� ����(�������� ����) */
}

/*--- �ؽ� ���̺� ���� ---*/
void Dump(const ChainHash *h)
{
	int i;
	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];
		printf("%02d ", i);
		
		while (p != NULL) {
			printf("�� %d :(%s) ", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

/*--- ��� ������ ���� ---*/
void Clear(ChainHash *h)
{
	int i;
	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];			/* ���� ������ ��� */
		
		while (p != NULL) {
			Node *next = p->next;
			free(p);					/* ���� ������ ����� �޸� ���� */
			p = next;					/* ���� ��� ���� */
		}
		h->table[i] = NULL;
	}
}

/*--- �ؽ� ���̺� ���� ---*/
void Terminate(ChainHash *h)
{
	Clear(h);						/* ��� ������ ���� */
	free(h->table);					/* �ؽ� ���̺� �迭�� �޸� ���� */
	h->size = 0;					/* �ؽ� ���̺� ũ�⸦ 0���� �ʱ�ȭ(clear) */
}