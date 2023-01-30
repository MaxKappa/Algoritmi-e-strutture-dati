#include <stdio.h>
#include <stdlib.h>


int *creaRete(int n, int *rete){
    if (rete != NULL){
        free(rete);
    }
    int *new = malloc(n*sizeof(int));
    return new;
}

void stampa(int *rete, int n){
    for(int i = 0; i < n; i++){
        printf("[%d] ", rete[i]);
    }
    printf("\n");
    return;
}

void doPremi(int *rete, int i){
    if (rete[i] == 1)
        rete[i] = 0;
    else
        rete[i] = 1;
}

void premiInterruttore(int *rete, int i, int n){
    if (i == 0){
        doPremi(rete, 0);
        doPremi(rete, 1);
        doPremi(rete, n-1);
    } else if (i == n-1){
        doPremi(rete, 0);
        doPremi(rete, n-1);
        doPremi(rete, n-2);
    } else {
        doPremi(rete, i-1);
        doPremi(rete, i+1);
        doPremi(rete, i);
    }
    return;
}

int main(){
    char c; int n; int i; int m; int k; int temp; int *rete = NULL;
    while((c = getchar()) != 'f'){
        switch (c) {
        case '+':
            scanf("%d", &n);
            rete = creaRete(n, rete);
            if (rete == NULL){
                printf("Errore di allocazione\n");
                exit(-1);
            }
            break;
        case 'p':
            stampa(rete, n);
            break;
        case 'o':
            if (rete == NULL){
                printf("La rete non è stata creata\n");
                break;
            }
            for(int i = 0; i < n; i++){
                scanf("%d", &temp);
                rete[i] = temp;
            }
            break;
        case 's':
            scanf("%d", &i);
            premiInterruttore(rete, i-1, n);
            break;
        case 'S':
            scanf("%d", &m);
            for(int j = 0; j < m; j++){
                scanf("%d", &k);
                premiInterruttore(rete, k-1, n);
            }
            break;
        }
    }
}