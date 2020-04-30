#include <stdio.h>
#include "Member.h"

typedef struct __node
{
    Member data;
    struct __node *prev;
    struct __node *next;
} Dnode;

typedef struct {
    Dnode *head;
    Dnode *crnt;
} Dlist;

static Dnode* AllocNode(void)
{
    return calloc(1, sizeof(Dnode));
}

static void SetNode(Dnode *n, const Member *x, Dnode *prev, Dnode *next)
{
    n->data = *x;
    n->next = next;
    n->prev = prev;
}

static int IsEmpty(const Dlist *list)
{
    return list->head->next == list->head;
}

void Init(Dlist *list)
{
    Dnode *dummyNode = AllocNode();
    list->head = list->crnt = dummyNode;
    dummyNode->next = dummyNode->prev = dummyNode;
}

Dnode *Search(Dlist *list, const Member *x, int (*compare)(const Member *x, const Member *y))
{
    Dnode* ptr = list->head->next;
    if (ptr != list->head) {
        while (ptr != list->head) {
            if (compare(&ptr->data, x) == 0) {
                list->crnt = ptr;
                return ptr;
            } 
            ptr = ptr->next;
        }
    }
    return NULL;
}

int Next(Dlist *list)
{
    Dnode *ptr = list->crnt;
    if (IsEmpty(list) || ptr->next == list->head)
        return 0;
    ptr = ptr->next;
    return 1;
}

int Prev(Dlist *list)
{
    if (IsEmpty(list) || list->crnt->prev == list->head)
        return 0;
    list->crnt = list->crnt->prev;
    return 1;
}

/*p 가 가리키는 노드 바로 다음 노드를 삽입*/
static void InsertAfter(Dlist *list, Dnode *p, const Member *x)
{
    Dnode *ptr = AllocNode();
    Dnode *nxt = p->next;
    p->next = p->next->prev = ptr;
    SetNode(ptr, x, p, nxt);
    list->crnt = ptr;
}

void InsertFront(Dlist *list, const Member *x)
{
    InsertAfter(list, list->head, x);
}

void InsertRear(Dlist *list, const Member *x)
{
    InsertAfter(list, list->head->prev, x);
}

void Remove(Dlist *list, Dnode *p)
{
    p->prev->next = p->next;
    list->crnt = p->next->prev = p->prev;
    free(p);
    if (list->crnt == list->head)
        list->crnt = list->crnt->next;    
}

void RemoveFront(Dlist *list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->next);
}

void RemoveRear(Dlist *list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->prev);
}

void RemoveCurrent(Dlist *list)
{
    if (list->crnt != list->head)
        Remove(list, list->crnt);
}

/*Purge
앞의 머리 노드를 비교하면서 같으면 삭제후 비교 대상
없을시 머리 노드 앞으로 증가
*/
void Purge(Dlist *list, int (*comapre)(const Member *x, const Member *y))
{
    Dnode *sptr = list->head;
    Dnode *ptr = list->head;

    while (sptr->next != list->head)
    {
        while (ptr->next != list->head)
        {
            ptr = ptr->next;
            if (comapre(&sptr->next->data, &ptr->next->data) == 0)
            {
                list->crnt = ptr;
                return ptr;
            }
        }
        sptr = sptr->next;
    }
}

/*Reserve?
입력 받은 정수 타입의 값으로 해당 노드의 위치를 알려준다. n = 1 머리 노드
*/