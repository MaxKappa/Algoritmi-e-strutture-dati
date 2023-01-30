#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
	char *w;
	struct node *next;
};

typedef struct node *Node;

char *fstring(char *w, Node l){
	if (l -> next == NULL){
		return strcat(w, l -> w);
	}
	return strcat(fstring(w, l -> next), l -> w);
}
char *fstring_iter(char *w, Node l){
	struct node *p;
	struct node *prev;
	int count = 0;
	int count_s = 0;
	char *stringa = calloc(1, sizeof(char));	
	for(p = l, prev = NULL; p != NULL;prev = p, p = p->next){
		count++;
	}
	int k = 0;
	for(int i = 0; i < count; i++){
		for(int j = k; j < count; j++){
			stringa[count_s] = prev->w[j];
			count_s++;
			stringa = realloc(stringa, count_s);
		}
		k++;
	}
	return stringa;
}


Node flist(Node l) {
	if (l -> w[0] != '\0' && l -> w[1] == '\0')
		return l;
	Node n = malloc( sizeof(struct node) );
	n -> w = (l -> w) + 1;
	n -> next = l;
	return flist(n);		
}

Node build(char *w) {
	Node lista = malloc (sizeof(struct node));
	lista -> w = w;
	lista -> next = NULL;
	return flist(lista);
}

Node flist2(Node l) {
	int length = strlen(l->w);
	//printf("%d\n", length);
	if (length == 0){
		return l;
	}
	Node n = malloc(sizeof(struct node));
	//printf("%s\n", l->w);
	n -> w = (l -> w) + 1;
	n -> next = l;
	return flist2(n);		
}

Node build2(char *w){
	Node lista = malloc(sizeof(struct node));
	lista->w = w;
	lista->next = NULL;
	return flist2(lista);
}


int main(){
	char word[20] = "";
    printf( "PROF: %s\n", fstring_iter(word, build("hello")));
}

/*
1. La funzione build crea un nodo, allocando con la malloc lo spazio per un nodo 
e ne restituisce il puntatore alla struttura, fa puntare il campo w al primo elemento dell'array di char w;
a. Restituisce un puntatore alla lista
b. La funzione flist viene invocata tante volte quanto è lungo l'array di char - 1 volte
c. Nell'if alla riga 9 viene verificato il caso base, che ci permette di uscire dalla funzione, cioè se siamo
arrivati all'ultimo elemento dell'array;
d. L'assegnamento a riga 12 assegna al campo w il valore dell'array successivo.
2. Concatena i caratteri contenuti nella lista in una stringa, lo fa scorrendo tutta la lista ricorsivamente
e concatenando il campo w e restituisce un puntatore a char;
*/
