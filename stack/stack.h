#ifndef STACK_H
#define STACK_H
#endif

struct stack{
    int *a;
    int top;
    int count_dim;
};

typedef struct stack *Stack;


Stack newStack(int dim);
int pop(Stack pila);
void push(Stack pila, int n);
void print_stack(Stack pila);
int isEmpty(Stack pila);

