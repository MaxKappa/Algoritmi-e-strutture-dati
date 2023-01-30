#include <stdio.h>
#include "stack.h"

   
int main(){
    char ch; int v = 0; int w = 0; int n = 0; int k = 0;
    Stack pila;
    while((ch = getchar()) != 'f'){
        switch (ch){
            case 'n':
            scanf("%d", &n);
            pila = newStack(n);
            break;
            case '+':
            scanf("%d", &v);
            push(pila, v);
            break;
            case '-':
            w = pop(pila);
            printf("The number drawn from the stack is %d\n", w);
            break;
            case 'p':
            print_stack(pila);
            break;
            case 'e':
            k = isEmpty(pila);
            if (k == 1){
                printf("The stack is empty\n");
                break;
            } else {
                printf("Not empty\n");
                break;
            }
       }
    }
}
