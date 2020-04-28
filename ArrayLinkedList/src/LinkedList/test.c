#include <stdio.h>
#include <stdlib.h>
#include "Member.h"

typedef struct __node
{
    Member data;
    struct __node *next;
} Node;

typedef struct
{
    Node *head;
    Node *crnt;
} List;

static Node *allocNode(void)
{
    return calloc(1, sizeof(Node));
}

static void setNode(Node *n, const Member *x, Node *next)
{
    n->data = *x;
    n->next = next;
}

void Init(List *list)
{
    list->head = NULL;
    list->crnt = NULL;
}

void insertFront(List *list, const Member *x)
{
    Node *ptr = list->head;
    list->head = list->crnt = allocNode();
    setNode(list->head, x, ptr);
}

void insertRear(List *list, const Member *x)
{
    if (list->head == NULL)
        insertFront(list, x);
    else
    {
        Node *ptr = list->head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = list->crnt = allocNode();
        setNode(ptr->next, x, NULL);
    }
}

void removeFront(List *list)
{
    if (list->head != NULL)
    {
        Node *ptr = list->head->next;
        free(list->head);
        list->head = list->crnt = ptr;
    }
}

void removeRear(List *list)
{
    if (list->head != NULL)
    {
        if (list->head->next == NULL)
            removeFront(list);
        else
        {
            Node *ptr = list->head;
            Node *pre;
            while (ptr->next != NULL)
            {
                pre = ptr;
                ptr = ptr->next;
            }
            pre->next = NULL;
            free(ptr);
            list->crnt = pre;
        }
    }
}

Node *Search(List *list, const Member *x, int (*comapre)(const Member *x, Member *y))
{
    if (list->head != NULL)
    {
        Node *ptr = list->head;
        while (ptr->next != NULL)
        {
            if (!comapre(&ptr->data, x))
            {
                list->crnt = ptr;
                return ptr;
            }
            ptr = ptr->next;
        }
    }
    return NULL;
}

void removeCurrent(List *list)
{
    if (list->crnt == list->head)
    {
        removeFront(list);
    }
    else
    {
        Node *ptr = list->head;
        while (ptr->next != list->crnt)
        {
            ptr = ptr->next;
        }
        ptr->next = list->crnt->next;
        free(list->crnt);
        list->crnt = ptr;
    }
}

int main(void)
{
    return 0;
}


