/* ���� �ּҹ����� ������ �ؽ�(���) */
#ifndef ___ClosedHash
#define ___ClosedHash

#include "Member.h"

/*--- ����� ���� ---*/
typedef enum {
	Occupied, Empty, Deleted
} Status;

/*--- ��� ---*/
typedef struct {
	Member data;		/* ������ */
	Status stat;		/* ����� ���� */
} Bucket;

/*--- �ؽ� ���̺� ---*/
typedef struct {
	int size;			/* �ؽ� ���̺��� ũ�� */
	Bucket *table;		/* �ؽ� ���̺��� ù ��° ��ҿ� ���� ������ */
} ClosedHash;

/*--- �ؽ� ���̺� �ʱ�ȭ ---*/
int Initialize(ClosedHash *h, int size);

/*--- �˻� ---*/
Bucket *Search(const ClosedHash *h, const Member *x);

/*--- ������ �߰� ---*/
int Add(ClosedHash *h, const Member *x);

/*--- ������ ���� ---*/
int Remove(ClosedHash *h, const Member *x);

/*--- �ؽ� ���̺� ���� ---*/
void Dump(const ClosedHash *h);

/*--- ��� ������ ���� ---*/
void Clear(ClosedHash *h);

/*--- �ؽ� ���̺� ���� ---*/
void Terminate(ClosedHash *h);
#endif