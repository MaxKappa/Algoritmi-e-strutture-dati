#include <stdio.h>
#include <stdlib.h>

void scambia(int a[], int i, int j){
    int temp = 0;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void ordina(int a[], int n){
    if (n == 1){
        return;
    }
    int max = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > a[max]){
            max = i;
        }
    }
    scambia(a, max, n-1);
    ordina(a, n-1);
}

int solve(int *array, int n, int L){
    ordina(array, n);
    int somma = 0;
    for(int i = 0; i < n; i++){
        if (somma+array[i] <= L){
            somma += array[i];
        } else {
            return i;
        }
    }
    return 0;
}

int main(){
    int L; int n;
    scanf("%d", &L);
    scanf("%d", &n);
    int *array = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }   
    printf("%d", solve(array, n, L));
    printf("\n");
}