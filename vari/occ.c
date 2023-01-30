#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char *String;

struct mappa{
    String s;
    int occorrenza;
};

typedef struct mappa *Mappa;

String newString(){
    String s = calloc(1, sizeof(char));
    return s;
}

char *read_word(void){
    String p = newString();
    char c; int size = 0;
    while (isalpha(c = getchar())){
        p[size] = c;
        size += sizeof(char);
        p = realloc(p, size);
    }
    p[size] = 0;
    return p;
}


int main(){
    int j = 0; int count = 0;
    String *frase = calloc(1,sizeof(char *));
    while(1){
        String parola = read_word();
        if (strcmp(parola, "stop") == 0){
            break;
        }
        frase[j] = calloc(1, sizeof(parola));
        printf("[%s]\n", parola);
        strcpy(frase[j], parola);
        j++;
        count++;
        free(parola);
    }
    for (int i = 0; i < count; i++){
        printf("[%s] ", frase[i]);
    }

    printf("\n");
}