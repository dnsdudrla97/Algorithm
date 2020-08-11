#include <stdio.h>
#include <stdlib.h>
#include "MemberData.h"
#include "CircDblLinkedList.h"

/*1 개의 노드를 동적으로 생성*/
static Dnode *AllocDNode(void)
{
    return calloc(1, sizeof(Dnode));
}

/*노드의 각 멤버 값을 설정*/
static void SetNode(Dnode *n, const Member *x, Dnode *prev, Dnode *next)
{
    n->data = *x;   /*데이터*/
    n->next = next; /*다음 노드에 대한 포인터*/
    n->prev = prev; /*앞쪽 노드에 대한 포인터*/
}

/*리스트가 비어 있는지 검사*/
static int IsEmpty(const Dlist *list)
{
    return list->head->next == list->head;
}

/*리스트를 초기화*/
void Init(Dlist *list)
{
    Dnode *dummyNode = AllocDNode(); /*더미 노드 생성*/
    list->head = list->crnt = dummyNode;
    dummyNode->prev = dummyNode->next = dummyNode;
}

/*선택한 노드의 데이터를 출력*/
void PrintCurrent(const Dlist *list)
{
    if (IsEmpty(list))
        printf("선택한 노드가 없다.");
    else
        PrintMember(&list->crnt->data);
}

/*선택한 노드의 데이터를 출력(줄 바꿈 문자 추가)*/
void PrintLnCurrent(const Dlist *list)
{
    PrintCurrent(list);
    putchar('\n');
}

/*Compare 함수와 X와 일치하는 노드를 검색*/
Dnode *Search(Dlist *list, const Member *x, int (*comapre)(const Member *x, const Member *y))
{
    Dnode *ptr = list->head->next;
    while (ptr != list->head)
    {
        if (comapre(&ptr->data, x) == 0)
        {
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

/*모든 노드의 데이터를 리스트 순서대로 출력*/
void Print(const Dlist *list)
{
    if (IsEmpty(list))
        puts("노드가 없다.");
    else
    {
        Dnode *ptr = list->head->next;
        puts("[모두 보기]");
        while (ptr != list->head)
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->next; /*다음 노드 선택*/
        }
    }
}

/*모든 노드의 데이터를 리스트 순서의 역순으로 출력*/
void PrintReverse(const Dlist *list)
{
    if (IsEmpty(list))
        puts("노드가 없다.");
    else
    {
        Dnode *ptr = list->head->prev;
        puts("[모두 보기]");
        while (ptr != list->head)
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->prev; /*앞쪽 노드 선택*/
        }
    }
}

/*선택한 노드를 다음으로 진행*/
int Next(Dlist *list)
{
    if (IsEmpty(list) || list->crnt->next == list->head)
        return 0; /*진행 불가*/
    list->crnt = list->crnt->next;
    return 1;
}

/*선택한 노드를 앞쪽으로 진행*/
int Prev(Dlist *list)
{
    if (IsEmpty(list) || list->crnt->prev == list->head)
        return 0; /*진행 불가*/
    list->crnt = list->crnt->prev;
    return 1;
}

/*p 가 가리키는 노드 바로 다음 노드를 삽입*/
void InsertAfter(Dlist *list, Dnode *p, const Member *x)
{
    Dnode *ptr = AllocDNode();
    Dnode *nxt = p->next;
    p->next = p->next->prev = ptr;
    SetNode(ptr, x, p, nxt);
    list->crnt = ptr; /*삽입한 노드를 선택*/
}

/*머리 에 노드를 삽입*/
void InsertFront(Dlist *list, const Member *x)
{
    InsertAfter(list, list->head, x);
}

/*꼬리에 노드를 삽입*/
void InsertRear(Dlist *list, const Member *x)
{
    InsertAfter(list, list->head->prev, x);
}

/*p 가 가리키는 노드를 삭제*/
void Remove(Dlist *list, Dnode *p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    list->crnt = p->prev; /*삭제한 노드의 앞쪽 노드를 선택*/
    free(p);
    if (list->crnt == list->head)
        list->crnt = list->head->next;
}

/*머리 노드를 삭제*/
void RemoveFront(Dlist *list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->next);
}

/*꼬리 노드를 삭제*/
void RemoveRear(Dlist *list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->prev);
}

/*선택한 노드를 삭제*/
void RemoveCurrent(Dlist *list)
{
    if (list->crnt != list->head)
        Remove(list, list->crnt);
}

/*모든 노드를 삭제*/
void Clear(Dlist *list)
{
    while (!IsEmpty(list)) /*텅 빌 때까지*/
        RemoveFront(list); /*머리 노드를 삭제*/
}

/*원형 이중 연결 리스트 종료*/
void Terminate(Dlist *list)
{
    Clear(list);      /*모든 노드를 삭제*/
    free(list->head); /*더미 노드를 삭제*/
}

void Purge(Dlist *list, int (*comapre)(const Member *x, const Member *y))
{
    Dnode *sptr = list->head->next;
    Dnode *ptr = list->head->next;

    while (sptr != list->head)
    {
        while (ptr != list->head)
        {
            if (comapre(&sptr->data, &ptr->data) == 0)
                Remove(list, ptr);       
            ptr = ptr->next;
        }
        sptr = sptr->next;
    }
}

Dnode *Retrieve(Dlist *list, int n)
{
    Dnode *ptr = list->head->next;
    if (IsEmpty(list))
        return NULL;
    else {
        while (n) {
            ptr = ptr->next;
            n--;
        }
        list->crnt = ptr;
        return ptr;
    }
}