#include <stdio.h>
#include <stdlib.h>

int valoreMancante(int *array, int n){
    int i = 0; int j = n-1;
    int m = (i+j)/2;
    j = m;
    while(j < n){
        if (array[i] != i){
            printf("Stampa i\n");
            return i;
        }
        else if (array[j] != j){
            printf("Stampa j\n");
            return j;
        }
    i++; j++;
    } 
    return -1;
}

int main(){
    int n; int temp;
    scanf("%d", &n);
    int *array = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        array[i] = temp;
    }
    printf("%d\n", valoreMancante(array, n));
}