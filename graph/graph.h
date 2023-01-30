#ifndef GRAPH_H
#define GRAPH_H
#endif

struct listnode{
    struct listnode *next;
    int v;
};

typedef struct listnode *Listnode;

struct graph{ // struttura associata a ogni grafo
    int n, m; //n = num vertici, m = num archi
    Listnode *A; // lista di adiacenza
};

typedef struct graph *Graph;

// Crea un grafo con n nodi
Graph graph_new(int n);

// Distrugge il grafo g
void graph_destroy(Graph g);

// Inserisce l'arco (v,w) nel grafo g
void graph_edgeinsert(Graph g, int v, int w);

// Stampa su standard output un grafo (specificare il formato!!)
void graph_print(Graph g);

//Depth-first search
void graph_DFS(Graph g, int n);

//Breadth-first search
void graph_BFS(Graph g, int n);
