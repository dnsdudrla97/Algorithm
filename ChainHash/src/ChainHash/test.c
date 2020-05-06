#include <stdio.h>
#include <stdlib.h>
#include "MemberNew.h"
#include "ChainHash.h"

typedef struct __node
{
    Member data;
    struct __node *next;
} Node;

typedef struct
{
    int size;
    Node **table;
} CHash;

static int hash(int key, int size)
{
    return key % size;
}

static void SetNode(Node *n, const Member *x, Node *next)
{
    n->data = *x;
    n->next = next;
}

int Init(CHash *h, int size)
{
    int i;
    if ((h->table = calloc(size, sizeof(Node *))) == NULL)
    {
        h->size = 0;
        return 0;
    }
    h->size = size;

    for (i = 0; i < size; i++)
        h->table[i] = NULL;
    return 1;
}

Node *Search(CHash *h, Member *x)
{
    int key = hash(x->no, h->size);
    Node *ptr = h->table[key];

    while (ptr != NULL)
    {
        if (ptr->data.no == x->no)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

int Add(CHash *h, Member *x)
{
    int key = hash(x, h->size);
    Node *p = h->table[key];
    Node *temp;

    while (p != NULL)
    {
        if (p->data.no == x->no)
            return -1;
        p = p->next;
    }

    if (temp = calloc(1, sizeof(Node)) == NULL)
        return 2;
    SetNode(temp, x, h->table[key]);
    h->table[key] = temp;
    return 0;
}

int Rmv(CHash *h, Member *x)
{
    int key = hash(x, h->size);
    Node *p = h->table[key];
    Node **pp = &h->table[key];

    while (p != NULL) {
        if (p->data.no == x->no)
        {
           *pp = p->next;
           free(p);
           return 0;
        }
        pp = &p->next;
        p = p->next;
    }
    return -1;

}