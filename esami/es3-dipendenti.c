#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct listnode{
    struct listnode *next;
    int v;
};

typedef struct listnode *Listnode;

struct graph{ 
    int n, m; 
    Listnode *A; 
};

typedef struct graph *Graph;

Graph graph_new(int n);
void graph_edgeinsert(Graph g, int v, int w);
void graph_print(Graph g);
void stampaSubordinati(Graph g, int n);
int supervisore(Graph g, int n);
int quantiSenzaSubordinati(Graph g);
void stampaImpiegatiSopra(Graph g, int n);
void stampaImpiegatiConSupervisore(Graph g);
int *stampaImpiegatiSenzaSupervisore(Graph g);
void stampaPerLivello(Graph g);

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

void stampaSubordinati(Graph g, int n){
    struct listnode *p = g->A[n];
    printf("I subordinati di {%d} sono:\n\n", n);
    while(p != NULL){
        printf("  {%d}\n", p->v);
        p = p->next;
    }
    return;
}

int supervisore(Graph g, int n){
    struct listnode *p;
    for(int i = 0; i < g->n; i++){
        p = g->A[i];
        while(p != NULL){
            if (p->v == n){
                return i;
            }
            p = p->next;
        }
    }
    return 56;
}

int quantiSenzaSubordinati(Graph g){
    int count = 0;
    for(int i = 0; i < g->n; i++){
        if (supervisore(g, i) == 56){
            count++;
        }
    }
    return count;
}

void stampaImpiegatiSopra(Graph g, int n){
    struct listnode *p;
    printf("L'elenco di tutti i dipendenti sopra a %d sono:\n\n", n);
    while(supervisore(g, n) != 56){
        printf("  {%d}\n", supervisore(g, n));
        n = supervisore(g, n);
    }
    printf("\n");
}

void stampaImpiegatiConSupervisore(Graph g){
     for(int i = 0; i < g->n; i++){
        if (supervisore(g, i) != 56){
            printf("%d ", i);
        }
    }
    printf("\n");
    return;
}

int *stampaImpiegatiSenzaSupervisore(Graph g){
    int *array = calloc(1, sizeof(int));
    int count = 0; 
    for(int i = 0; i < g->n; i++){
        if (supervisore(g, i) == 56){
            array[count] = i;
            array = realloc(array, count+1);
            count++;
            printf("%d ", i);
        }
    }
    printf("\n");
    return array;
}
/*
void stampaPerLivello(Graph g){
    int *array = stampaImpiegatiSenzaSupervisore(g);
    for (int i = 0; i < )
}
*/


int main(){
    char ch; int n; Graph g; int v; int w; int q; int t;
    printf("Scrivere:\n[n] Per creare una lista di dipendenti\n[+] Per aggiungere un dipendente\n[a] Per stampare i subordinati di un dipendente\n[b] Per stampare quanti dipendenti sono senza subordinati\n[c] Per stampare il supervisore di un dipendente\n[d] Per stampare i dipendenti sopra di un dipendente gerarchicamente\n[p] Per stampare la lista di adiacenza\n[f] Per terminare\n\n\n");
    while((ch = getchar()) != 'f'){
        switch(ch){
            case 'n':
                scanf("%d", &n);
                g = graph_new(n);
                break;
            case '+':
                scanf("%d %d", &v, &w);
                graph_edgeinsert(g, v, w);
                break;
            case 'a':
                scanf("%d", &n);
                stampaSubordinati(g, n);
                break;
            case 'b':
                printf("%d\n",quantiSenzaSubordinati(g));
                break;
            case 'c':
                scanf("%d", &t);
                int res = supervisore(g, t);
                if (res != 56){
                    printf("Il supervisore di %d è %d\n", t, res);
                } else {
                    printf("Il dipendente %d non ha supervisori\n", t);
                }
                break;
            case 'd':
                scanf("%d", &q);
                stampaImpiegatiSopra(g, q);
                break;
            case 'e':
                stampaImpiegatiConSupervisore(g);
                break;
            case 'k':
                //stampaPerLivello(g);
                break;
            case 'p':
                graph_print(g);
                break;
        }
    }   
}