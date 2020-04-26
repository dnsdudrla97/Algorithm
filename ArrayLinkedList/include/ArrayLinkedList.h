/*커서로 만든 연결 리스트 (헤더)*/
#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList

#include "Member.h"

#define Null -1 /*empty cursor*/

typedef int Index; /*Datatype of curosr*/

/*Node*/
typedef struct
{
    Member data; /*data*/
    Index next;  /*next Node*/
    Index Dnext; /*next Node of free list*/
} Node;

/*LinekdList*/
typedef struct
{
    Node *n;       /*list main(array)*/
    Index head;    /*head node*/
    Index max;     /*usefull tail Node*/
    Index deleted; /*head node of free list*/
    Index crnt;    /*Selection Node*/
} List;

/*Linkedlist reset(bigger numberic size)*/
void Init(List *list, int size);

/*function compare same x and Node*/
Index Search(List *list, const Member *x, int comapre(const Member *x, const Member *y));

/*Insert a node in the head*/
void InsertFront(List *list, const Member *x);

/*Insert a node in the tail*/
void InsertRear(List *list, const Member *x);

/*Delete a node in the head*/
void RemoveFront(List *list);

/*Delete a node in the tail*/
void RemoveRear(List *list);

/*Delete selected node*/
void RemoveCurrent(List *list);

/*All delete*/
void Clear(List *list);

/*Output the data of the selected node*/
void PrintCurrent(const List *list);

/*Output the data of the selected node (\n)*/
void PrintLnCurrent(const List *list);

/*Output the data of the all node*/
void Print(const List *list);

/*end*/
void Terminate(List *list);

/*------- Test func --------*/
void Purge(List *list, int (*compare)(const Member *x, const Member *y));

Index Retrieve(List *list, int n);
#endif