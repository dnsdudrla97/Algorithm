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
    n->next = next; /*뒤쪽 포인터*/
}
/*연결 리스트를 초기화*/
void Init(List *list)
{
    list->head = NULL; /*머리 노드*/
    list->crnt = NULL; /*선택한 노드*/
}

/*compare 함수를 사용해서 x를 검색한다.*/
Node* search(List* list, const Member* x, int comapre(const Member* x, const Member *y)) {
    Node* ptr = list->head;
    while (ptr != NULL) {
        if (comapre(&ptr->data, x) == 0) {  /*키 값이 같은 경우*/
            list->crnt = ptr;
            return ptr;         /*검색 성공*/
        }
        ptr = ptr->next;        /*다음 노드를 선택*/
    }
    return NULL;
}