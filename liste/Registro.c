#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char *String;

char **newBook(int n){
    char **m1;
    m1 = malloc(n * sizeof(char *) );
    for (int r = 0; r < n; r++) {
        *(m1+r) = calloc(n, sizeof(char));
    }
    return m1;
}

char *read_word(void){
    char *p = malloc(sizeof(char));
    char c; int size = 0;
    while (isalpha(c = getchar())){
        p[size] = c;
        size += 1;
        p = realloc(p, size+1);
    }
    p[size] = '\0';
    if (p == NULL){
        printf("ERRORE, INSERISCI IL NOME\n");
    }
    return p;
}


void book(int k, String name, char **m){
        if (!isalpha(m[k][0])){
            m[k] = name;
        } else {
            printf("ERRORE, POSTO OCCUPATO\n");
            return;
        }
}

void cancel(int k, char **m, int n){
    if (isalpha(m[k][0])){
        free(m[k]);
        m[k] = calloc(n, sizeof(char));
    } else {
        printf("ERRORE, POSTO NON OCCUPATO\n");
        return;
    }
}

void move(int from, int to, char **m, int n){
    if (isalpha(m[from][0]) && !isalpha(m[to][0])){
        strcpy(m[to], m[from]);
        cancel(from, m, n);
    } else if (!isalpha(m[from][0])){
        printf("ERRORE, POSTO DA SCAMBIARE NON ASSEGNATO\n");
        return;
    } else if (isalpha(m[to][0])){
        printf("ERRORE, POSTO DI DESTINAZIONE OCCUPATO\n");
        return;
    }
}



void printBook(char **m, int n){
printf("\nREGISTER [0 .. %d]:\n", n-1);
    for (int i = 0; i < n; i++){
        if (isalpha(m[i][0])){
            printf("%d --> %s\n", i, m[i]);
        }
    } 
    printf("\n");   
}


int main(){
    char c; String name; char **m; 
    int n = 0; int d = 0; int from = 0; int to = 0; int k = 0;
    while((c = getchar()) != 'f'){
        switch(c){
            case 'b':
                scanf("%d", &n);
                m = newBook(n);
                break;
            case '+':
                scanf("%d\n", &k);
                name = read_word();
                book(k, name, m);
                break;
            case 'p':
                printBook(m, n);
                break;
            case '-':
                scanf("%d", &d); 
                cancel(d, m, n);
                break;
            case 'm':
                scanf("%d %d", &from, &to);
                move(from, to, m, n);
                break;
        }
    }

}

