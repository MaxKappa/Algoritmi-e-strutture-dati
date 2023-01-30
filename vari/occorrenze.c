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

struct bit_node{
    Mappa item;
    struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

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

Bit_node bit_new(String parola, int n){
    Bit_node root = malloc(sizeof(struct bit_node));
    root->item = malloc(sizeof(struct mappa));
    root->item->s = calloc(1, sizeof(parola));
    root->item->s = parola;
    root->item->occorrenza = n;
    root->l = NULL;
    root->r = NULL;
    return root;
}

Bit_node inserisci(Bit_node root, String parola){
  if (root == NULL){
      root = bit_new(parola, 1);
      return root;
  }
    if (strcmp(root->item->s, parola) > 0){
        root -> l = inserisci(root->l, parola);
    } else if  (strcmp(root->item->s, parola) < 0){
        root -> r = inserisci(root->r, parola);
    } else {
        root -> item -> occorrenza++;
    }
    return root;
}

void bist_orderprint( Bit_node root ){
    if (root == NULL){
            return;
    }
    bist_orderprint(root->l);
    printf("[%s] [%d] \n", root -> item -> s, root -> item -> occorrenza);
    bist_orderprint(root->r);
}

void bist_invorderprint(Bit_node root){
    if (root == NULL){
        return;
    }
    bist_invorderprint(root->r);
    printf("[%s] [%d] \n", root -> item -> s, root -> item -> occorrenza);
    bist_invorderprint(root->l);
}

int search(Bit_node root, String parola){
    if (root == NULL){
        return 0;
    }
    if (strcmp(root->item->s, parola) == 0){
        return root->item->occorrenza;
    } else if (strcmp(root->item->s, parola) > 0){
        return search(root->l, parola);
    } else {
        return search(root->r, parola);
    }
}

int main(){
    Bit_node root = NULL;
     while(1){
        String parola = read_word();
        if (strcmp(parola, "") == 0){
            continue;
        }
        if (strcmp(parola, "stop") == 0){
            break;
        }
        root = inserisci(root, parola);
    }
    printf("OCCORRENZE DI PAROLE NEL TESTO IN ORDINE ALFABETICO:\n****************************************************\n");
    bist_orderprint(root);
    printf("\n"
           "OCCORRENZE DI PAROLE NEL TESTO IN ORDINE INVERSO:\n*************************************************\n");
    bist_invorderprint(root);
    printf("\n");
    int k = 0;
    printf("RICERCA DI PAROLE\n******************\n");
    while(1){
        String parola = read_word();
        if (strcmp(parola, "stop") == 0){
            break;
        }
        k = search(root, parola);
        printf("[%d]\n", k);
    }
}