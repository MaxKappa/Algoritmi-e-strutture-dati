#include <stdio.h>
#include <stdlib.h>

int latoCristallo(int t) {
    if (t == 0){
        return 1;
    }
    return latoCristallo(t-1)*2+1;    
}

char **creaMatrice(int n){
    char **m;
    m = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++){
        *(m+i) = calloc(n ,  sizeof(char));
    }
    return m;
}

void stampaMatrice(char **m, int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
    return;
}

void crist(char **m, int r0, int c0, int l){
    if (l == 1){
        m[r0][c0] = '*';
        return;
    } 
    m[l/2][l/2] = '*';
    crist(m, 0, 0, l/2);
    crist(m, 2, 0, l/2);
    crist(m, 0, 2, l/2);  
    crist(m, 2, 2, l/2);
}

int main(){
  //  printf("%d", latoCristallo(3));
    char **m = creaMatrice(latoCristallo(2));
    crist(m, 0, 0, latoCristallo(2));
    stampaMatrice(m, latoCristallo(2));
}


/*
t    l

0 -> 1

1 -> 3  

2 -> 7 = 3*2+1

3 -> 15 = 7*2+1

4 -> = 15*2+ 1 


l(t) = l(t-1)*2+1



*/

