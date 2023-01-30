#include <stdio.h>
#include <stdlib.h>


struct intervallo{
    int i;
    int j;
    int v;
};

typedef struct intervallo *Intervallo;


void swap(Intervallo input, int index1, int index2){
    Intervallo temp = malloc(sizeof(struct intervallo));
    temp->i = input[index1].i;
    temp->j = input[index1].j;
    temp->v = input[index1].v;
    input[index1].i = input[index2].i;
    input[index1].j = input[index2].j;
    input[index1].v = input[index2].v;
    input[index2].i = temp->i;
    input[index2].j = temp->j;
    input[index2].v = temp->v;
    return;
}

void ordinaChiavi(Intervallo input, int n){
    if (n == 1)
        return;
    int max = 0;
    for(int i = 0; i < n; i++){
        if (input[max].j < input[i].j)
            max = i;
    }
    swap(input, max, n-1);
    ordinaChiavi(input, n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    Intervallo input = malloc(n*sizeof(struct intervallo));
    for (int j = 0; j < n; j++){
        scanf("%d-%d %d", &input[j].i, &input[j].j, &input[j].v);
    }
    ordinaChiavi(input, n);
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d-%d %d\n", input[i].i, input[i].j, input[i].v);
    }
}
