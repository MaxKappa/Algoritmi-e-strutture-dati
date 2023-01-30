#include <stdio.h>
#include <stdlib.h>

int max(int *array, int length){
  int max = 1;
  int count = 1;
  for(int i = 1; i < length; i++) {
    if(array[i-1] < array[i])
      count++;
    else 
      count = 1;    
    if(max < count)
        max = count;
  }
  return max;
}


int main(){
    int n = 0; 
    int input = 0;
    scanf("%d", &n);
    int *array = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &input);
        array[i] = input;
    }
    
    int max_res = max(array, n);
    printf("%d ", max_res);
    printf("\n");
}

/*
7
1 3 2 5 1 4 7
*/