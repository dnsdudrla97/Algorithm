#include <stdio.h>
#include <stdlib.h>
#include "Instack.h"


int Init(struct Instack* s, int max) {
    
    if ((s->stk=calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return (-1);
    }
    s->max = max;
    s->ptr=0;
    return (0);
}

int Push(struct Instack* s, int x) {
    if (s->ptr >= s->max) return (-1);
    s->stk[s->ptr++] = x;
    return(0);
}

int Pop(struct Instack* s, int* x) {
    if (s->ptr <= 0) return (-1);
    *x = s->stk[--s->ptr];
    return (0);
}

int Isempty(struct Instack* s) {
    return (s->ptr <= 0);
}

void Terminator(struct Instack* s) {
    if (s->stk != NULL) free(s->stk);
    s->ptr = s->max = 0;
}