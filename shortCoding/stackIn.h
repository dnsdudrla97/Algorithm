#ifndef __StackIn
#define __StackIn

/* --- stack --- */
typedef struct s_stack
{
    /* data */
    int ptr;
    int* stk;
    int max;
    int num;

}t_stack;

/* init */
int Init(t_stack* t, int max);

/* Push */
int Push(t_stack* t, int x);

/* Pop */
int Pop(t_stack* t, int* x);

/* IsEmpty? */
int IsEmpty(const t_stack* t);

/* Terminate */
void Terminate(t_stack* t);

#endif