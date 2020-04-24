#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

/*노드를 동적으로 생성*/
static Node *AllocNode(void)
{
    return calloc(1, sizeof(Node));
}

/*n이 가리키는 노드의 각 멤버에 값을 설정*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
    n->data = *x;   /*data*/
    n->next = (Node*)next; /*뒤쪽 포인터*/
}
/*연결 리스트를 초기화*/
void Init(List *list)
{
    list->head = NULL; /*머리 노드*/
    list->crnt = NULL; /*선택한 노드*/
}

/*compare 함수를 사용해서 x를 검색한다.*/
Node *search(List *list, const Member *x, int comapre(const Member *x, const Member *y))
{
    Node *ptr = list->head;
    while (ptr != NULL)
    {
        if (comapre(&ptr->data, x) == 0)
        { /*키 값이 같은 경우*/
            list->crnt = ptr;
            return ptr; /*검색 성공*/
        }
        ptr = ptr->next; /*다음 노드를 선택*/
    }
    return NULL;
}

/*머리에 노드를 삽입하는 함수*/
void InsertFront(List *list, const Member *x)
{
    Node *ptr = list->head;               // 1
    list->head = list->crnt = AllocNode(); // 2
    SetNode(list->head, x, ptr);           // 3
}

/*꼬리에 노드를 삽입하는 함수*/
void InsertRear(List *list, const Member *x)
{
    if (list->head == NULL)   /*비어 있는 경우*/
        InsertFront(list, x); /*머리에 삽입*/
    else
    {
        Node *ptr = list->head;
        while (ptr->next != NULL) /*while문 종료시 ptr은 꼬리 노드를 가리킨다.*/
            ptr = ptr->next;      /*반복을 통해서 ptr을 다음 노드로 업데이트*/
        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next, x, NULL);
    }
}

/*머리 노드 삭제*/
void RemoveFront(List *list)
{
    if (list->head != NULL)
    {
        Node *ptr = list->head->next;  /*두 번째 노드에 대한 포인터*/
        free(list->head);              /*머리 노드를 해제*/
        list->head = list->crnt = ptr; /*새로운 머리 노드*/
    }
}

/*꼬리 노드를 삭제*/
void RemoveRear(List *list)
{
    if (list->head != NULL)
    {
        if ((list->head)->next == NULL) /*노드가 1개만 있는 경우*/
            RemoveFront(list);          /*머리 노드 삭제*/
        else
        {
            Node *ptr = list->head;
            Node *pre; /*앞에 있는 노드를 가리킨다.*/
            /*while 종료시 ptr은 꼬리 노드를 가리키고, 
            pre는 꼬리 노드로부터 두번째 노드를 가리킨다.*/
            while (ptr->next != NULL)
            {
                pre = ptr;
                ptr = ptr->next;
            }
            pre->next = NULL; /*pre는 꼬리 노드로부터 두 번째 노드*/
            free(ptr);        /*ptr은 꼬리 노드*/
            list->crnt = pre; /*while(end) : pre->E(node), ptr->F(node)*/
        }
    }
}

/*선택한 노드를 삭제하는 함수*/
void RemoveCurrent(List *list)
{
    if (list->head != NULL)
    {
        if (list->crnt == list->head) /*머리 노드를 선택한 상황?*/
            RemoveFront(list);
        else
        {
            //1
            Node *ptr = list->head;
            while (ptr->next != list->crnt)
                ptr = ptr->next;
            //1
            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;
        }
    }
}

/*모든 노드 삭제*/
void Clear(List *list)
{
    while (list->head != NULL) /*텅 빌 때까지*/
        RemoveFront(list);     /*머리 노드를 삭제*/
    list->crnt = NULL;
}

/*선택한 노드의 데이터를 출력*/
void PrintCurrent(const List *list)
{
    if (list->crnt == NULL)
        printf("선택한 노드가 없다.");
    else
        PrintMember(&list->crnt->data);
}

/*선택한 노드의 데이터를 출력(줄 바꿈 문자 포함)*/
void PrintLnCurrent(const List *list)
{
    PrintCurrent(list);
    putchar('\n');
}

/*모든 노드의 데이터를 리스트 순으로 출력하는 함수*/
void Print(const List *list)
{
    if (list->head == NULL)
        puts("노드가 없다.");
    else
    {
        Node *ptr = list->head;
        puts("[모두 보기]");
        while (ptr != NULL)
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->next; /*다음 노드 선택*/
        }
    }
}

/*연결 리스트 종료*/
void Terminate(List *list)
{
    Clear(list); /*모든 노드를 삭제*/
}