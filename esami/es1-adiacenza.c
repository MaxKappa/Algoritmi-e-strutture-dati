#include <stdio.h>
#include <stdlib.h>

struct listnode{
    int item;
    struct listnode *next;
};

typedef struct listnode *Listnode;

struct ArrayDiListe{
    Listnode *A;
    int n;    
};

typedef struct ArrayDiListe *arrayDiListe;

arrayDiListe matr2arrayDiListe (int **matr, int n){
    arrayDiListe arr = malloc(sizeof(struct ArrayDiListe));
    Listnode prev;
    Listnode succ;
    arr->A = malloc(n*sizeof(Listnode));
    arr->n = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (matr[i][j] == 1){
               for(prev = NULL, succ = arr->A[i]; succ != NULL; prev = succ, succ = succ->next);
               if (!prev){
                   arr->A[i] = malloc(sizeof(struct listnode));
                   arr->A[i]->item = j;
               } else {
               succ = malloc(sizeof(struct listnode));
               succ->item = j; 
               prev->next = succ; 
               }
            }
        }
    }
    return arr;
}

int **new_matr(int n){
    int **new_matr = calloc(n,sizeof(int *));
    for(int i = 0; i < n; i++){
        new_matr[i] = calloc(n,sizeof(int));
    }
    return new_matr;
}

int **f_matr( int **matr, int n ) { 
    int **matr2 = new_matr( n );
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){ 
            if ( matr[i][j] == 1 ){
                for ( int k = 0; k < n; k++ ){ 
                    if ( matr[j][k] == 1 ){
                        matr2[i][k] = 1;
                    }
                }
            }
        }
    }
    return matr2; 
}

void stampa(int **matr, int n){
    printf("  ");
    for(int i = 0; i < n; i++){
        printf("%d ", i);
    }
    printf("\n");   
    for(int i = 0; i < n; i++){
        printf("%d ", i);
        for (int j = 0; j < n; j++){
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}

void stampa_list(arrayDiListe arr, int n){
    Listnode p;
    for(int i = 0; i < n; i++){
        printf("[%d]", i);
        p = arr->A[i];
        if (p)
            printf(" -> ");
        while(p != NULL){
            printf("[%d]", p->item);
            if (p ->next != NULL)
                printf(" -> ");
            p = p->next;
        }
        printf("\n");
    }
}

arrayDiListe f_arrayDiListe(arrayDiListe v, int n){
    Listnode p;
    Listnode p2;
    Listnode prev;
    Listnode succ;
    arrayDiListe v2 = malloc(sizeof(struct ArrayDiListe));
    v2->A = malloc(n*sizeof(Listnode));
    for(int i = 0; i < n; i++){
        p = v->A[i];
        while(p){
            if (v->A[p->item]!= NULL){
                p2 = v->A[p->item];
                while(p2){
                    for(prev = NULL, succ = v2->A[i]; succ != NULL; prev = succ, succ = succ->next);
                    if (!prev){
                        v2->A[i] = malloc(sizeof(struct listnode));
                        v2->A[i]->item = p2->item;
                    } else {
                        succ = malloc(sizeof(struct listnode));
                        succ->item = p2->item;
                        prev->next = succ;
                    }    
                    p2 = p2->next;
                }
            }
            p = p->next;
        }
    }
    return v2;
}
int main(){
    int n = 8;
    int **matr = new_matr(n);
    matr[0][2] = 1;
    matr[0][5] = 1;
    matr[2][1] = 1;
    matr[2][5] = 1;
    matr[3][2] = 1;
    matr[4][5] = 1;
    matr[5][6] = 1;
    matr[6][4] = 1;
    matr[7][6] = 1;
    stampa(matr, n);
    arrayDiListe arr = matr2arrayDiListe(matr, n);
    stampa_list(arr, n);
    arrayDiListe arr2 = f_arrayDiListe(arr, n);
    printf("\n");
    stampa_list(arr2, n);
  //  int **matr2 = f_matr(matr, n);
  //  printf("\n");
   // stampa(matr2, n);
}