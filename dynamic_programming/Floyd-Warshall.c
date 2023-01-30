#include <stdio.h>
#include <stdlib.h>
#define infinito 9999;


struct queue{
    int key;
    int priority;
    struct queue *next;
};

typedef struct queue *Queue;


struct listnode{
    int v;
    int peso;
    struct listnode *next;
};

typedef struct listnode *Listnode;

struct graph{
    int n,m; 
    Listnode *A;
};

typedef struct graph *Graph;

Graph new_Graph(int n);
Graph edge_insert(Graph g, int v, int w, int peso);
void print_graph(Graph g);
int **new_Matr(int n);
int find(Graph g, int v, int w);
void print_matrix(int **M, int n);
int deleteMin(Queue q);
void insert(Queue q, int key, int priority);
void changeKey(Queue q, int key, int priority);
int IsEmpty(Queue q);
int **Floyd_Warshall(Graph g);
int *Dijkstra(Graph g, int s);
  
Graph new_Graph(int n){
    Graph g = malloc(sizeof(struct graph));
    g->A = calloc(n,sizeof(Listnode));
    g->n = n;
    g->m = 0;
    return g;
}

Graph edge_insert(Graph g, int v, int w, int peso){
    Listnode prev;
    Listnode succ;
    for(succ = g->A[v], prev = NULL; succ; prev = succ, succ = succ->next);
    if (!prev){
        g->A[v] = calloc(1, sizeof(struct listnode));
        g->A[v]->v = w;
        g->A[v]->peso = peso;
    } else {
        succ = calloc(1, sizeof(struct listnode));
        prev->next = succ;
        succ->v = w;
        succ->peso = peso;
    }
    g->m++;
    return g;
}

void print_graph(Graph g){
    Listnode p;
    for(int i = 0; i < g->n; i++){
        printf("[%d] -", i+1);
        p = g->A[i];
        while(p){
            printf("%d-> ", p->peso);
            printf("[%d]", p->v+1);
            if (p -> next)
                printf(" -");
            p = p->next;
        }
        printf("\n");
    }
}

int **new_Matr(int n){
    int **m = calloc(n,sizeof(int *));
    for(int i = 0; i < n; i++){
        m[i] = calloc(n,sizeof(int));
    }
    return m;
}

int find(Graph g, int v, int w){
    Listnode p = g->A[v];
    while (p){
        if (p->v == w){
            return p->peso;
        }
        p = p->next;
    }
    return -1;
}

int peso(Graph g, int v, int w){
    Listnode p = g->A[v];
    int res = find(g, v, w);
    int min = infinito;
    if(res == -1){
        
    }
    return res;
}

void print_matrix(int **M, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (M[i][j] == 9999)
                printf("inf ");
            else
                printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return;
}

int findMinPriority(Queue q){
    Queue p = q;
    int min = 1000;
    while(p){
        if (p->priority < min)
            min = p->priority;
        p = p->next;
    }
    return min;
}

Queue cancel(Queue q, int n){
    Queue prec;
    Queue curr;
    for(prec = NULL, curr = q; curr != NULL && curr->priority != n; prec = curr, curr = curr->next);
    if (curr == NULL)
            return NULL;
    if (prec == NULL)
        q = q -> next;
    else     
        prec -> next = curr -> next;    
    curr = NULL;
    return q;
}

int deleteMin(Queue q){
    if (IsEmpty(q))
        return -1;
    Queue prev;
    Queue succ;
    int min = findMinPriority(q);
    return min;
}

Queue newQueue(int key, int priority){
    Queue q = calloc(1, sizeof(struct queue));
    q->key = key;
    q->priority = priority;
    return q;
}

void insert(Queue q, int key, int priority){
    Queue prev;
    Queue succ;
    for(prev = NULL, succ = q; succ; prev = succ, succ = succ -> next);
    if (!prev){
        succ = calloc(1, sizeof(struct queue));
        succ->key = key;
        succ->priority = priority;
    } else {
        succ = calloc(1, sizeof(struct queue));
        succ->key = key;
        succ->priority = priority;
        prev->next = succ;
    }
    return;
}

void changeKey(Queue q, int key, int priority){
    while(q){
        if (q -> key == key)
            q->priority = priority;
        q = q->next;
    }
    return;
}

int IsEmpty(Queue q){
    if (q == NULL)
        return 1;
    return 0;
}

void print_queue(Queue q){
    while(q){
        printf("key = %d, priority = %d\n", q->key, q->priority);
        q = q->next;
    }
    return;
}

int **Floyd_Warshall(Graph g){
    int **D = new_Matr(g->n);
    for (int i = 0; i < g->n; i++){
        for(int j = 0; j < g->n; j++){
            if (i == j)
                D[i][j] = 0;
            else if (find(g, i, j) != -1)
                D[i][j] = find(g, i, j);
            else
                D[i][j] = infinito;
        }
    }
    for(int k = 0; k < g->n; k++){
        for(int i = 0; i < g->n; i++){
            for (int j = 0; j < g->n; j++){
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
    return D;
}

void print_Array(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}

int *Dijkstra(Graph g, int s){
    int *d = calloc(g->n, sizeof(int));
    d[s] = 0;
    for(int i = 0; i < g->n; i++){
        if (i == s)
            continue;
        else
            d[i] = infinito;
    }
    print_Array(d,g->n);
    Queue C;
    for(int i = 0; i < g->n; i++){
        if (i == 0)
            C = newQueue(i, d[i]);
        else {
            insert(C, i, d[i]);
            printf("d[i] %d\n", d[i]);
        }
    }

    int u = 0;
    while(!IsEmpty(C)){
        u = deleteMin(C);
        C = cancel(C, u);
        print_queue(C);
        printf("\n");
        int p;
        for(int i = 0; i < g->n; i++){
            if (p != -1)    
                if (d[i] > d[u] + p){
                d[i] = d[u] + p;
                printf("Cazzo\n");
                changeKey(C, i, d[i]);
                }
            }
    }
    
    return d;
}

int main(){
    Graph g = new_Graph(5);
    edge_insert(g, 0, 1, 3); 
    edge_insert(g, 0, 3, 5);
    edge_insert(g, 1, 2, 7);
    edge_insert(g, 1, 4, 7);
    edge_insert(g, 2, 0, 11);
    edge_insert(g, 2, 4, 1);
    edge_insert(g, 4, 3, 3);
  //  print_graph(g);
    int **M = Floyd_Warshall(g);
    print_matrix(M, g->n);
    int *a = Dijkstra(g, 0);
    print_Array(a, g->n);
    print_graph(g);
}