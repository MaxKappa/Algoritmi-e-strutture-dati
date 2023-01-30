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
        p[size] = tolower(c);
        size += sizeof(char);
        p = realloc(p, size);
    }
    p[size] = 0;
    return p;
}

int contains(Mappa map, String parola, int count){
    for (int i = 0; i < count; i++){
        if (strcmp(map[i].s, parola) == 0){
            return 1;
        }
    }
    return 0;
}

void aumenta(Mappa map, String parola, int count){
    for (int i = 0; i < count; i++){
        if (strcmp(map[i].s, parola) == 0){
            map[i].occorrenza++;
            return;
        }
    }
    return;
}

int main(){
    int j = 0; int count = 0;
    Mappa map = NULL;
    while(1){
        String parola = read_word();
        if (strcmp(parola, "") == 0){
            continue;
        }
        if (strcmp(parola, "stop") == 0){
            break;
        }
        map = realloc(map, j+1*sizeof(struct mappa));
        if (contains(map, parola, count) != 1){
            map[j].s = calloc(1, sizeof(parola));
           // printf("[%s]\n", parola);
            strcpy(map[j].s, (parola));
            map[j].occorrenza = 1;
            j++;
            count++;
        } else {
            aumenta(map, parola, count);
        }
       free(parola);
    }
//    ordina(map, count);
    for (int i = 0; i < count; i++){
        printf("[%s] [%d] \n", map[i].s, map[i].occorrenza);
    }

    printf("\n");
}