#include <stdio.h>
#include <stdlib.h>

struct node{
    int item;
    struct node *next;
};

typedef struct node *Node;

Node new_node(Node lista, int item){
     
}

int main(){
    int n = 0; int t = 0;
    scanf("%d", &n);
    Node lista = NULL;
    for(int i = 0; i < n; i++){
        scanf("%d", t);
        new_node(lista, t);
    }
    printf("%d \n", solve(arr, n));
}