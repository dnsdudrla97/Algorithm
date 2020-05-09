/* 오픈 주소법으로 구현한 해시(헤더) */
#ifndef ___CloseHash
#define ___CloseHash

#include "MemberTwo.h"

/*--- 요소의 상태 ---*/
typedef enum {
	Occupied, Empty, Deleted
} Status;

/*--- 요소 ---*/
typedef struct {
	Member data;		/* 데이터 */
	Status stat;		/* 요소의 상태 */
} Bucket;

/*--- 해시 테이블 ---*/
typedef struct {
	int size;			/* 해시 테이블의 크기 */
	Bucket *table;		/* 해시 테이블의 첫 번째 요소에 대한 포인터 */
} ClosedHash;

/*--- 해시 테이블 초기화 ---*/
int Initialize(ClosedHash *h, int size);

/*--- 검색 ---*/
Bucket *Search(const ClosedHash *h, const Member *x);

/*--- 데이터 추가 ---*/
int Add(ClosedHash *h, const Member *x);

/*--- 데이터 삭제 ---*/
int Remove(ClosedHash *h, const Member *x);

/*--- 해시 테이블 덤프 ---*/
void Dump(const ClosedHash *h);

/*--- 모든 데이터 삭제 ---*/
void Clear(ClosedHash *h);

/*--- 해시 테이블 종료 ---*/
void Terminate(ClosedHash *h);
#endif