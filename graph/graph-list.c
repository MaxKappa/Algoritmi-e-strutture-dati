#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#ifndef STACK_H
#define STACK_H
#endif
#ifndef QUEUE_H
#define QUEUE_H
#endif
#include "stack.c"
#include "queue-list.c"

//DFS non funzionante

Graph graph_new(int n);
void graph_destroy(Graph g);
void graph_edgeinsert(Graph g, int v, int w);
void graph_print(Graph g);
void graph_DFS(Graph g, int n);
void graph_BFS(Graph g, int n);


Graph graph_new(int n){
    Graph g = malloc(sizeof(struct graph));
    if(!g) {
        printf("Errore di Allocazione\n");
        return NULL;
    }
    g -> A = calloc(n, sizeof(struct listnode *));
    g->n = n;
    return g;
}
void destroy_list(struct listnode *node){
    if (node == NULL){
        return;
    }
    destroy_list(node->next);
    free(node);
}

void graph_destroy(Graph g){
    for(int i = 0; i < g->n; i++){
        destroy_list(g->A[i]);
    }
    free(g->A);
    free(g);
}


void graph_edgeinsert(Graph g, int v, int w){
    struct listnode *prev; struct listnode *curr;
    for(prev = NULL, curr = g->A[v]; curr != NULL; prev = curr, curr = curr->next);
    if (!prev){
        g->A[v] = calloc(1, sizeof(struct listnode));
        g->A[v]->v = w;
        return;
    }
    curr = calloc(1, sizeof(struct listnode));
    curr->v = w;
    prev -> next = curr;
}


void graph_print(Graph g){
    struct listnode *p;
    for(int i = 0; i < g->n; i++){
        printf("[%d]", i);
        p = g->A[i];
        while(p != NULL){
            printf(" -> [%d]", p->v);
            p = p->next;
        }
          printf("\n");
    }
}

int visitato(int *array, int length, int n){
    for(int i = 0; i < length; i++){
        if (array[i] == n){
            return 1;
        }
    }
    return 0;
}

void graph_BFS(Graph g, int n){
    Queue q = new_queue();
    int *visited = calloc(g->n, sizeof(int));
    visited[n] = 1;
    enqueue(q, n);
    while (!is_empty_queue(q)) {
        print_queue(q);
        int current = dequeue(q);
        printf("[%d] ", current);
        struct listnode* temp = g->A[current];
        while (temp != NULL) {
        int adiacente = temp->v;
        if (visited[adiacente] == 0) {
            visited[adiacente] = 1;
            enqueue(q, adiacente);
        }
        temp = temp->next;
        }
    }
}


void graph_DFS(Graph g, int n){
    int count = 0;
    struct listnode *p = g->A[n];
    int *visited = calloc(g->n, sizeof(int));
    Stack pila = newStack(g->n);
    printf("{%d} ", n);
    push(pila, n);
    visited[count] = n;
    count++;
    while(!isEmpty(pila)){
        if (!visitato(visited, g->n, p->v)){
            printf("{%d} ", p->v);
            push(pila, p->v);
            visited[count] = p->v;
            count++;
            p = g->A[pila->a[pila->top]];
        } else {
            p = p->next;
            if (p == NULL){
                pop(pila);
                p = g->A[pila->top];
            }
        }
    }
    printf("\n");
}

