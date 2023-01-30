#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void riordina(int *a, int n){
    for(int i = 1; i < n; i++){
        if(a[i-1] == 1 && a[i] == 0){
            swap(a, i-1, i);
            i = 0;
        } 
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    riordina(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}