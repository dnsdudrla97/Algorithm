#include <stdio.h>
#include <stdlib.h>
#include "stackIn.h"

int Init(t_stack* t, int max)
{
    t->ptr = 0;
    t->num = 0;
    if ((t->stk = calloc(max, sizeof(int))) == NULL)
    {
        t->num = 0;
        t->max = 0;
        return -1;
    }
    t->max = max;
    return 0;
}

int Push(t_stack* t, int x)
{
    if (t->ptr >= t->max)
    {
        return -1;
    }
    t->stk[t->ptr++] = x;
    return 0;
}

int Pop(t_stack* t, int* x)
{
    if (t->ptr <= 0)
    {
        return -1;
    }
    *x = t->stk[--t->ptr];
    return 0;
}

/*--- 모든 데이터 표시 ---*/
void Print(const t_stack *s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* 바닥(bottom) → 꼭대기(top)로 스캔 */
		printf("%d ", s->stk[i]);
	putchar('\n');
}


int IsEmpty(const t_stack* t)
{
    return t->ptr <= 0;
}

void Terminate(t_stack* t)
{
    if (t->stk != NULL)
        free(t->stk);
    t->ptr = t->max = 0;
}