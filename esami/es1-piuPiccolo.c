#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int func(int A[], int B[], int n, int m){
   //trovo il max di A
   int maxA = 0;
   for(int i = 0; i < n; i++){
       if (maxA < A[i]){
           maxA = A[i];
       }
   }
    //trovo il min di B
   int minB = 999;
   for(int i = 0; i < m; i++){
       if (minB > B[i]){
           minB = B[i];
       }
   }
    if (maxA < minB){
        return 1;
    }
    return 0;
}

int main(){
    int A[] = {1,5,5}; 
    int B[] = {7, 6};
    printf("%d\n",func(A, B, 3, 2));
    printf("Tempo di esecuzione = %lu\n", clock());
}