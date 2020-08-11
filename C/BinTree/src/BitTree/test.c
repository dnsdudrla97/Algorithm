#include <stdio.h>
#include <stdlib.h>

#include "Member.h"

/*node*/
typedef struct __BinNode {
    Member data;
    struct __BinNode *left;
    struct __BinNode *right;
} BinNode;

static BinNode *AllocNode()
{
    return calloc(1, sizeof(BinNode));
}

static void setNode(BinNode *n, const Member *x, const BinNode *left, const BinNode *right)
{
    n->data = *x;
    n->left = left;
    n->right = right;
}

/*--- 검색 ---*/
BinNode *Search(BinNode *p, const Member *x)
{
    int cond;
    if (p == NULL)
        return NULL;
    else if (cond = MemberNoCmp(&p->data, x) == 0)
        return p;
    else if (cond < 0)
        Search(p->left, x);
    else
        Search(p->right, x);
}

/*--- 노드의 삽입 ---*/
BinNode *Add(BinNode *p, const Member *x)
{
    int cond;
    if (p == NULL) {
        p = AllocNode();
        setNode(p, x, NULL, NULL);
    } else if (cond = MemberNoCmp(&p->data, x) == 0) {
        return NULL;
    } else if (cond < 0) {
        p->left = Add(p->left, x);
    } else {
        p->right = Add(p->right, x);
    }
}

/*--- 노드의 삭제 ---*/
int Remove(BinNode **root, const Member *x)
{
    BinNode *temp, *next;
    BinNode **left;
    BinNode **p = root;
    
    int cond;
    while (1) {
        if (*p == NULL) {
            Perror("error : ");
            return -1;
        } else if (cond = MemberNoCmp(&(*p)->data, x) == 0) {
            break;
        } else if (cond < 0) {
            p = &((*p)->left);
        } else
            p = &((*p)->right);
    }

    if ((*p)->left == NULL)
        next = (*p)->right;
    else
    {
        left = &((*p)->left);       // p = 5, left = 1
        while ((*left)->right != NULL)  // left->right 4()->NULL
            left = &((*left)->right);   // left = 4
        next = *left;   // next <= left = 4
        *left =  (*left)->left;      // left = 3
        next->left = (*p)->left; // next->left = 1
        next->right = (*p)->right; //next->right = 7
    }
    temp = *p;      // temp = 5
    *p = next;      // 5 <- 4
    free(temp);     // free

    return 0;

}

/*--- 모든 노드를 출력 ---*/
void PrintTree(const BinNode *p)
{
    if (p != NULL)
    {
        PrintTree(p->left);
        PrintMember(&p->data);
        PrintTree(p->right);
    }
}

/*--- 모든 노드 삭제 ---*/
void FreeTree(BinNode *p)
{
    if (p != NULL)
    {
        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }   