#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node *Nodo;

Nodo list_insert(Nodo list, int n);
int olist_search(Nodo list, int n);
Nodo olist_insert(Nodo list , int n);
void print_list(Nodo list);
void destroy_list(Nodo list);
Nodo cancel(Nodo list, int n);
int count_list(Nodo list);

int count_list(Nodo list){
    int count = 0;
    for(; list != NULL; list = list->next){
        count++;
    }
    return count;
}

Nodo list_insert(Nodo list, int n){
    Nodo new_node = malloc(sizeof(struct node));
    new_node->next = list;
    new_node->value = n;
    return new_node;    
}

int olist_search(Nodo list, int n){
    for(;list != NULL; list = list->next){
        if (list->value == n){
            return 1;
        }
    }
    return 0;
}

Nodo cancel(Nodo list, int n){
    Nodo prec;
    Nodo curr;
    for(prec = NULL, curr = list; curr != NULL && curr->value != n; prec = curr, curr = curr->next);
    if (curr == NULL)
            return list;
    if (prec == NULL)
        list = list -> next;
    else     
        prec -> next = curr -> next;    
    curr = NULL;
    return list;
}

void destroy_list_rec(Nodo list){
    if (list == NULL){
        return;
    }
    destroy_list_rec(list->next);
    free(list);
}


void destroy_list(Nodo list){
    Nodo prev; Nodo succ;
    for(prev = NULL, succ = list; succ != NULL; prev = succ, succ = succ->next){
        free(prev);
    }
    free(prev);
}

void print_list(Nodo list){  
    if (list == NULL){
        printf("\n");
        return;
    }
    printf("%d ", list->value);
    print_list(list->next);
}


int main(){
    Nodo list = NULL; char ch; int n = 0; int count;
    while((ch = getchar())!= 'f'){
        switch(ch){
            case '+':
                scanf("%d", &n);
                list = list_insert(list, n);
                break;
            case '-':
                scanf("%d", &n);
                list = cancel(list, n);
                break;
            case 'p':
                print_list(list);
                break;
            case 'd':
                destroy_list(list);
                list = NULL;
                break;
            case 'c':
                 count = count_list(list);
                if (count == 0)
                    printf("La lista è vuota\n");
                else
                    printf("La lista contiene %d elementi\n", n); 
                break;
            case '?':
                scanf("%d", &n);
                int b = olist_search(list, n);
                if (b == 1)
                    printf("Si, il numero %d appartiene alla lista\n", n);
                else 
                    printf("Nom il numero %d non appartiene alla lista\n", n);
                break;
        }
    }
}

