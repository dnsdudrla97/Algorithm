#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*버킷 노드*/
typedef struct __node
{
    char *data;          /*data*/
    struct __node *next; /*next node*/
} Node;

/*HashTable*/
typedef struct
{
    int size;     /*해시 테이블의 사이즈*/
    Node **table; /*해시 테이블의 첫 번째 요소에 대한 포인터*/
} ChainHash;

/*해시 함수(key의 해시 값을 반환)*/
static int hash(char *key, int size)
{
    // return key % size;
    return (int)*key % size;
}

/*노드의 각 멤버에 값을 설정*/
static void SetNode(Node *n, char *x, Node *next)
{
    n->data = x;
    n->next = next;
}


static int NameCmp(char *x, char *y)
{
    return strcmp(x, y);
}

/*해시 테이블 초기화*/
int Init(ChainHash *h, int size)
{
    int i;
    if ((h->table = calloc(size, sizeof(Node *))) == NULL)
    {
        h->size = 0;
        return 0;
    }
    h->size = size;
    for (i = 0; i < size; i++) /*모든 버킷을 공백(NULL) 상태로 만든다.*/
        h->table[i] = NULL;
    return 1;
}

/*데이터 추가*/
int Add(ChainHash *h, char *x)
{
    int key = hash(x, h->size); /*추가하는 데이터의 해시 값*/
    Node *p = h->table[key];    /*현재 선택한 노드*/
    Node *temp;

    while (p != NULL)
    {
        if (NameCmp(p->data, x) == 0) /*이 키는 이미 등록된상태*/
            return 1;
        p = p->next;
    }
    if ((temp = calloc(1, sizeof(Node))) == NULL)
        return 2;
    SetNode(temp, x, h->table[key]); /*추가하는 노드에 값을 설정*/
    h->table[key] = temp;
    return 0; /*추가 설정*/
}

/*데이터 삭제*/
int Remove(ChainHash *h, char *x)
{
    int key = hash(x, h->size); /*삭제하는 데이터의 해시 값*/
    Node *p = h->table[key];    /*현재 선택한 노드 */
    Node **pp = &h->table[key]; /*현재 선택한 노드에 대한 포인터*/
    while (p != NULL)
    {
        if (NameCmp(p->data, x) == 0)
        {
            *pp = p->next;
            free(p);
            return 0;
        }
        pp = &p->next;
        p = p->next;
    }
    return 1;
}

int main(void)
{
    ChainHash hash;

    char *test[6] = {"apple", "banna", "cable", "apalo", "bad", "cow"};
    Init(&hash, 13);
    Add(&hash, test[0]);
    Add(&hash, test[1]);
    Add(&hash, test[2]);
    Add(&hash, test[3]);
    Add(&hash, test[4]);
    Add(&hash, test[5]);    
    
    
    return 0;
}