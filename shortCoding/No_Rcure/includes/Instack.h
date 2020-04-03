#ifndef ___Instack
#define ___Instack
struct Instack {
    int* stk;
    int ptr;
    int max;
};

int Init(struct Instack* s, int m);

int Push(struct Instack* s, int x);

int Pop(struct Instack* s, int* x);

int Isempty(struct Instack* s);

void Terminator(struct Instack* s);

#endif