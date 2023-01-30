#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack newStack(int dim){
    Stack pila = calloc(1, sizeof(struct stack));
    pila->a = calloc(dim, sizeof(int));
    pila->count_dim = dim;
    pila->top = dim;
    return pila;
}


void push(Stack pila, int n){
    if (pila->top-1 >= 0){
        pila->a[pila->top-1] = n;
        pila->top--;
        return;
    }
    printf("Stack full\n");
    return;
}

int pop(Stack pila){
    if (pila->top == pila->count_dim){
        printf("Stack empty\n");
        return 0;
    }
    int res = pila->a[pila->top];
    pila->top++;
    return res;
}


void print_stack(Stack pila){
    for(int i = pila->top; i < pila->count_dim; i++){
        printf("[%d]\n", pila->a[i]);
    }
    return;
}

int isEmpty(Stack pila){
    if (pila->top == pila->count_dim){
        return 1;
    }
    return 0;
}