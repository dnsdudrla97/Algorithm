#ifndef ___ChainHash
#define ___ChainHash

#include "MemberNew.h"

/*버킷 노드*/
typedef struct __node
{
    Member data;         /*data*/
    struct __node *next; /*next node*/
} Node;

/*HashTable*/
typedef struct
{
    int size;     /*해시 테이블의 사이즈*/
    Node **table; /*해시 테이블의 첫 번째 요소에 대한 포인터*/
} ChainHash;

/*해시 테이블 초기화*/
int Init(ChainHash *h, int size);

/*검색*/
Node *Search(const ChainHash *h, const Member *x);

/*데이터 추가*/
int Add(ChainHash *h, const Member *x);

/*데이터 삭제*/
int Remove(ChainHash *h, const Member *x);

/*해시 테이블 덤프(dump)*/
void Dump(const ChainHash *h);

/*모든 데이터 삭제*/
void Clear(ChainHash *h);

/*해시 테이블 종료*/
void Terminate(ChainHash *h);
#endif