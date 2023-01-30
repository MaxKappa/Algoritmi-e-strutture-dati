#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
/*
struct graph{ // struttura associata a ogni grafo
    int n, m; //n = num vertici, m = num lati
    int **A; // matrice di adicenza
};
*/
typedef struct graph *Graph;


Graph graph_new(int n);
void graph_destroy(Graph g);
void graph_edgeinsert(Graph g, int v, int w);
Graph graph_read(void);
void graph_print(Graph g);
int **matrix_new(int n);

int **matrix_new(int n){
    int **A = calloc(n, sizeof(int *));
    for(int i = 0; i < n; i++){
        A[i] = calloc(n, sizeof(int));
    }
    return A;
}

Graph graph_new(int n){
    Graph g = malloc(sizeof(struct graph));
    if(!g) {
        printf("Errore di Allocazione\n");
        return NULL;
    }
    g->A = matrix_new(n);
    g->n = n;
    return g;
}

void graph_print2(Graph g){
    for(int i = 0; i < g->n; i++){
        for (int j = 0; j < g->n; j++){
            if (g->A[i][j] == 1){
                printf("%d -> %d", i, j);
                printf("\n");
            }
        }
    }
}

void graph_print(Graph g){
    for(int i = 0; i < g->n; i++){
        printf("[%d]\n", i);
        for(int j = 0; j < g->n; j++){
            if(g->A[i][j] == 1) {
                printf("  -> %d\n", j);
            }
        }
        printf("\n");
    }
}


void graph_edgeinsert(Graph g, int v, int w){
    if (v >= g->n || w >= g-> n){
        printf("ERRORE\n");
        return;
    }
    g->A[v][w] = 1;
}



void graph_destroy(Graph g){

}
/*
Graph graph_read(void){
    int n = 0; int c;
    printf("Quanti nodi vuoi nel grafo? ");
    scanf("%d", &n);
    Graph g = graph_new(n);
    printf("GRAFO CREATO\n");
    for(int i = 0; i < n; i++){
        printf("Scrivere i nodi da collegare al nodo %d (separati da spazio):\n ", i);
        char *numeri = read_int();
        printf("%s", numeri);
    }
    return g;
}
*/