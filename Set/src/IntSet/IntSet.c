/*int형 집합 intSet soruce*/
#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

int Init(intSet *s, int max)
{
    s->num = 0;
    if ((s->set = calloc(max, sizeof(int))) == NULL)
    {
        s->max = 0; /*배열 생성에 실패*/
        return (-1);
    }
    s->max = max;
    return (0);
}

/*집합 s에 n이 들어 있는지 확인*/
int IsMember(const intSet *s, int n)
{
    int i;
    for (i = 0; i < s->num; i++)
        if (s->set[i] == n)
            return (i);     /*들어 있음 (인덱스를 반환)*/
    return (-1);            /*들어 있지 않음*/
}

/*집합 s에 n을 추가*/
void Add(intSet* s, int n)
{
    if (s->num < s->max && IsMember(s, n) == -1)    /*들어 있지 않으면*/
        s->set[s->num++] = n;
}

/*--- 집합 s에서 n을 삭제 ---*/
void Remove (intSet *s, int n)
{
    int idx;
    if ((idx = IsMember(s, n) != -1)) {
        s->set[idx] = s->set[--s->num];     /*마지막 요소를 삭제 위치로 옮김*/
    }
}

/*집합 s에 넣을 수 있는 최대의 원소 개수를 반환*/
int Capacity (const intSet* s)
{
    return (s->max);
}

/*집합 s의 원소 개수를 반환*/
int Size (const intSet* s)
{
    return s->num;
}

/*집합 s2를 s1에 대입*/
void Assign (intSet* s1, const intSet* s2)
{
    int i;
    int n = (s1->max < s2->num) ? s1->max : s2->num; /*복사하는 원소의 개수*/
    for (i = 0; i < n; i++)
        s1->set[i] = s2->set[i];
    s1->num = n;
}

/*집합 s1과 s2가 같은지 확인*/
int Equal (const intSet* s1, const intSet* s2)
{
    int i, j;
    if (Size(s1) != Size(s2))
        return (0);
    for (i = 0; i < s1->num; i++) {
        for (j = 0; j < s2->num; j++)
            if (s1->set[i] == s2->set[i])
                break;
        if (j == s2->num)
            return (0);    
    }
    return (1);
}

/*집합 s2와 s3의 합집합을 s1에 대입*/
intSet* Union (intSet* s1, const intSet* s2, const intSet* s3)
{
    int i;
    Assign(s1, s2);     /*s2를 s1에 대입*/
    for (i = 0; i < s3->num; i++)
        Add(s1, s3->set[i]);
    return (s1);
}

/*집합 s2와 s3의 교집합을 s1에 대입*/
intSet* Intersection (intSet* s1, const intSet* s2, const intSet* s3)
{
    int i, j;
    s1->num = 0;    /*s1을 공집합으로 만든다.*/

    for (i = 0; i < s2->num; i++)
        for (j = 0; j < s3->num; j++)
            if (s2->set[i] == s3->set[j])
                Add(s1, s2->set[i]);
    return (s1);
}

/*집합 s2에서 s3을 뺸 차집합을 s1에 대입*/
intSet* Difference (intSet* s1, const intSet* s2, const intSet* s3)
{
    int i, j;
    s1->num = 0;        /*s1을 공집합으로 만든다.*/
    for (i = 0; i < s2->num; i++) {
        for (j = 0; j < s3->num; j++)
            if (s2->set[i] == s3->set[j])
                break;
        if (j == s3->num)
            Add(s1, s2->set[i]);
    }
    return (s1);
}


/*집합 s의 모든 원소를 출력*/
void Print (const intSet* s)
{
    int i;

    printf("{ ");
    for (i = 0; i < s->num; i++)
        printf("%d ", s->set[i]);
    printf("}");
}

/*집합 s의 모든 원소를 출력(줄 바꿈 문자 포함) */
void PrintLn (const intSet* s)
{
    Print(s);
    putchar('\n');
}

/*집합 종료*/
void Terminate (intSet* s)
{
    if (s->set != NULL) {
        free(s->set);       /*배열 해제*/
        s->max = s->num = 0;
    }
}

/* add context header source */

/*집합이 가득 찼다면 1, 아니면 0을 반환 */
int IsFull(const intSet* s) {
    return s->num >= s->max;
}

/*집합의 모든 원소를 삭제하는 함수 */
void Clear(intSet(* s)) {
    s->num = 0;
}

/*집합 s2, s3의 대칭 차를 s1에 대입하는 함수*/
intSet* SymmetricDifference(intSet* s1, const intSet* s2, const intSet* s3) {
    s1->num = 0;    /*공집합*/
    int i;
    for (i = 0; i < s2->num; i++)
        if ((IsMember(s3, s2->set[i])) == -1)
            Add(s1, s2->set[i]);

    for (i = 0; i < s3->num; i++)
        if ((IsMember(s2, s3->set[i])) == -1)
            Add(s1, s3->set[i]);

    return (s1);
}

/*집합 s1에 s2의 모든 원소를 추가하는 함수(s1 포인터 반환)*/
intSet* ToUnion(intSet* s1, const intSet* s2) {
    s1->num = 0;
    int i;
    for (i = 0; i < s2->num; i++)
        Add(s1, s2->set[i]);
    return (s1);
}

/*집합 s1에서 s2에 들어 있지 않은 모든 원소를 삭제하는 함수(s1 포인터 반환)*/
intSet* ToIntersection(intSet* s1, const intSet* s2) {
    int i = 0;

    while (i <= s1->num) {
        if ((IsMember(s2, s1->set[i])) == -1)
            Remove(s1, s1->set[i]);
        else i++;
    }
    return (s1);
}

/*집합 s1에서 s2에 들어 있는 모든 원소를 삭제하는 함수(s1 포인터 반환)*/
intSet* ToDifference(intSet* s1, const intSet* s2) {
    int i;
    for (i = 0; i < s2->num; i++)
        Remove(s1, s2->set[i]);
    return (s1);
}

/*집합 s1이 s2의 부분집합이면 1, 아니면 0을 반환*/
int IsSubset(const intSet* s1, const intSet* s2) {
    int i, j;

	for (i = 0; i < s1->num; i++) {
		for (j = 0; j < s2->num; j++)
			if (s1->set[i] == s2->set[j])
				break;
		if (j == s2->num)					
			return 0;
	}
	return (1);
}

/*집합 s1이 s2의 진부분집합이면 1, 아니면 0을 반환*/
int IsProperSubset(const intSet* s1, const intSet* s2) {
    if (s1->num >= s2->num)
        return (0);
    return IsSubset(s1, s2);
}
