#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node *Nodo;

typedef struct{
    Nodo head;
    int count;
} Set;


Set *list_insert(Set *list, int n);
int olist_search(Set *list, int n);
Set *olist_insert(Set *list , int n);
void print_list(Set *list);
void destroy_list(Set *list);
Set *cancel(Set *list, int n);
int count_list(Set *list);

int count_list(Set *list){
    int count = 0;
    for(; list != NULL; list = list->head){
        count++;
    }
    return count;
}

Set *list_insert(Set *list, int n){
    Set *new_node = malloc(sizeof(Set));
    new_node->head->next = list->head;
    new_node->head->value = n;
    return new_node;
}

void print_list(Set *list){
    for ()
}



int main(){
    Set *list = NULL;
    list = list_insert(list, 5);
    list = list_insert(list, 4);
    list = list_insert(list, 6);
}


/*
int olist_search(Set *list, int n){
    for(;list != NULL; list = list->next){
        if (list->value == n){
            return 1;
        }
    }
    return 0;
}

Set *cancel(Set *list, int n){
    Set *prec;
    Set *curr;
    for(prec = NULL, curr = list; curr != NULL && curr->value != n; prec = curr, curr = curr->next);
    if (curr == NULL)
            return list;
    if (prec == NULL)
        list = list -> next;
    else     
        prec -> next = curr -> next;    
    free(curr);
    curr = NULL;
    return list;
}

void destroy_list(Set *list){
    if (list == NULL){
        return;
    }
    destroy_list(list->next);
    free(list);
}

void print_list(Set *list){  
    if (list == NULL){
        printf("\n");
        return;
    }
    printf("%d ", list->value);
    print_list(list->next);
}


int main(){
    Set *list = NULL; char ch; int n = 0; int count;
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

*/