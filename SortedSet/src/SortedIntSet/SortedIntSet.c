/*int형 집합 SortedIntSet soruce*/
#include <stdio.h>
#include <stdlib.h>
#include "SortedIntSet.h"

/*집합 초기화*/
int Initialize(SortedIntSet *s, int max)
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

int _search(const SortedIntSet *s, int n, int *flag)
{
    int pl = 0;
    int pr = s->num - 1;
    int pc;

    *flag = 1;
    if (s->num <= 0)
        return 0;

    do
    {
        pc = (pl + pr) / 2;
        if (s->set[pc] == n)
        {
            *flag = 0;
            // while (pc > pl && s->set[pc - 1] == n) pc--;
            return pc;
        }
        else if (s->set[pc] < n)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);

    return pl;
}

/*--- 집합 s에 n이 들어있는지 확인 ---*/
int IsMember(const SortedIntSet *s, int n)
{
    int flag;
    int idx = _search(s, n, &flag);
    return flag ? -1 : idx;
}

/*--- 집합 s에 n을 추가 ---*/
void Add(SortedIntSet *s, int n)
{
    int i, idx, flag;

    if (s->num < s->max)
    {
        idx = _search(s, n, &flag);
        if (flag == 1)
        {
            s->num++;
            for (i = s->num - 1; i > idx; i--)
                s->set[i] = s->set[i - 1];
            s->set[idx] = n;
        }
    }
}

/*--- 집합 s에서 n을 삭제 ---*/
void Remove(SortedIntSet *s, int n)
{
    int i, idx, flag;

    if (s->num > 0)
    {
        idx = _search(s, n, &flag);
        if (flag == 0)
        {
            --s->num;
            for (i = idx; i < s->num; i++)
                s->set[i] = s->set[i + 1];
        }
    }
}

/*--- 집합 s에 넣을 수 있는 최대 원소 개수를 반환 ---*/
int Capacity(const SortedIntSet *s)
{
    return s->max;
}

/*--- 집합 s의 원소 개수를 반환 ---*/
int Size(const SortedIntSet *s)
{
    return s->num;
}

/*--- 집합 s2를 s1에 대입 ---*/
void Assign(SortedIntSet *s1, const SortedIntSet *s2)
{
    int i;
    int n = (s1->max < s2->num) ? s1->max : s2->num; /* 복사하는 원소의 개수 */
    for (i = 0; i < n; i++)
        s1->set[i] = s2->set[i];
    s1->num = n;
}

/*--- 집합 s1과 s2가 같은지 확인 ---*/
int Equal(const SortedIntSet *s1, const SortedIntSet *s2)
{
    int i;

    if (Size(s1) != Size(s2))
        return 0;
    for (i = 0; i < s1->num; i++)
        if (s1->set[i] != s2->set[i])
            return 0;
    return 1;
}

/*--- 집합 s2와 s3의 합집합을 s1에 대입 ---*/
SortedIntSet *Union(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3)
{
    int k2, k3;

    s1->num = 0;
    k2 = k3 = 0;
    while (k2 < s2->num && k3 < s3->num)
    {
        if (s2->set[k2] < s3->set[k3])
            s1->set[s1->num++] = s2->set[k2++];
        else if (s2->set[k2] > s3->set[k3])
            s1->set[s1->num++] = s3->set[k3++];
        else
        {
            s1->set[s1->num++] = s2->set[k2++];
            k3++;
        }
        if (s1->num == s1->max)
            return s1;
    }
    if (k2 < s2->num)
        while (k2 < s2->num && s1->num < s1->max)
            s1->set[s1->num++] = s2->set[k2++];
    if (k3 < s3->num)
        while (k3 < s3->num && s1->num < s1->max)
            s1->set[s1->num++] = s3->set[k3++];
    return s1;
}

/*--- 집합 s2와 s3의 교집합을 s1에 대입 ---*/
SortedIntSet *Intersection(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3)
{
    int k2, k3;

    s1->num = 0;
    k2 = k3 = 0;
    while (k2 < s2->num && k3 < s3->num)
    {
        if (s2->set[k2] < s3->set[k3])
            k2++;
        else if (s2->set[k2] > s3->set[k3])
            k3++;
        else
        {
            s1->set[s1->num++] = s2->set[k2];
            k3++;
            if (s1->num == s1->max)
                return s1;
        }
    }

    return s1;
}

/*--- 집합 s2에서 s3를 뺀 차집합을 s1에 대입 ---*/
SortedIntSet *Difference(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3)
{
    int k2, k3;

    s1->num = 0;
    k2 = k3 = 0;
    while (k2 < s2->num && k3 < s3->num)
    {
        if (s2->set[k2] < s3->set[k3])
            s1->set[s1->num++] = s2->set[k2++];
        else if (s2->set[k2] > s3->set[k3])
            k3++;
        else
        {
            k2++;
            k3++;
        }
        if (s1->num == s1->max)
            return s1;
    }

    if (k2 < s2->num)
        while (k2 < s2->num && s1->num < s1->max)
            s1->set[s1->num++] = s2->set[k2++];
    return s1;
}

/*--- 집합 s의 모든 원소를 ​​출력 ---*/
void Print(const SortedIntSet *s)
{
    int i;

    printf("{ ");
    for (i = 0; i < s->num; i++)
        printf("%d ", s->set[i]);
    printf("}");
}

/*--- 집합 s의 모든 원소를 출력(줄 바꿈 문자 포함) ---*/
void PrintLn(const SortedIntSet *s)
{
    Print(s);
    putchar('\n');
}

/*--- 집합 종료 ---*/
void Terminate(SortedIntSet *s)
{
    if (s->set != NULL)
    {
        free(s->set); /* 배열 해제 */
        s->max = s->num = 0;
    }
}

/* add context */

/*집합이 가득 찼다면 1, 아니면 0을 반환*/
int IsFull(const SortedIntSet *s)
{
    return s->num >= s->max;
}

/*집합의 모든 원소를 삭제하는 함수*/
void Clear(SortedIntSet *s)
{
    s->num = 0;
}

/*집합 s2, s3이 대칭 차를 s1에 대입하는 함수*/
SortedIntSet *symmetricDifference(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3)
{
    int k2, k3;

    s1->num = 0;
    k2 = k3 = 0;
    while (k2 < s2->num && k3 < s3->num)
    {
        if (s2->set[k2] < s3->set[k3])
            s1->set[s1->num++] = s2->set[k2++];
        else if (s2->set[k2] > s3->set[k3])
            s1->set[s1->num++] = s3->set[k3++];
        else
        {
            k2++;
            k3++;
        }
        if (s1->num == s1->max)
            return s1;
    }

    if (k2 < s2->num)
        while (k2 < s2->num && s1->num < s1->max)
            s1->set[s1->num++] = s2->set[k2++];
    else
        while (k3 < s3->num && s1->num < s1->max)
            s1->set[s1->num++] = s3->set[k3++];
    return s1;
}

/*집합 s1에 s2의 모든 원소를 추가하는 함수(s1 포인터 반환)*/
SortedIntSet *ToUnion(SortedIntSet *s1, const SortedIntSet *s2)
{
    int i;
    for (i = 0; i < s2->num; i++)
        Add(s1, s2->set[i]);

    return s1;
}

/*집합 s1에서 s2에 들어 있지 않은 모든 원소를 삭제하는 함수(s1 포인터 반환)*/
SortedIntSet *ToIntersection(SortedIntSet *s1, const SortedIntSet *s2)
{
    int i = 0;

    while (i < s1->num)
    {
        if (IsMember(s2, s1->set[i]) == -1)
            Remove(s1, s1->set[i]);
        else
            i++;
    }
    return s1;
}

/*집합 s1에서 s2에 들어 있는 모든 원소를 삭제하는 함수(s1 포인터 반환)*/
SortedIntSet *ToDifference(SortedIntSet *s1, const SortedIntSet *s2)
{
    int i = 0;
    for (i = 0; i < s2->num; i++)
        Remove(s1, s2->set[i]);
    return s1;
}

/*집합 s1이 s2의 부분집합이면 1, 아니면 0을 반환*/
int IsSubset(const SortedIntSet *s1, const SortedIntSet *s2)
{
    int i, j;

    for (i = 0; i < s1->num; i++)
    {
        for (j = 0; j < s2->num; j++)
            if (s1->set[i] == s2->set[j])
                break;
        if (j == s2->num)
            return 0;
    }
    return 1;
}

/*집합 s1이 s2의 진부분집합이면 1, 아니면 0을 반환*/
int IsProperSubset(const SortedIntSet *s1, const SortedIntSet *s2)
{
    if (s1->num >= s2->num)
        return 0;
    return IsSubset(s1, s2);
}
