#include <stdio.h>
#include <stdlib.h>

// Nel caso peggiore O(n2) perchè il ciclo for itera n volte, il while viene ripetuto n volte.
// Abbiamo il caso peggiore quando l'array è al contrario
int solve(int *arr, int n){
    int robot = -1;
    int sol = 0;
    while(robot != n-1){
        for(int i = 0; i < n; i++){
            if (robot+1 == arr[i])
                robot = arr[i];   
        }
        sol++;
    }  
    return sol;  
}


int main(){
    int n;
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", solve(arr, n));
}