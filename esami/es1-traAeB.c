#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>


struct bit_node {
  int item;
  struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

// prototipi delle funzioni generali su alberi binari
Bit_node bit_new( int item );
void bit_printassummary( Bit_node p, int spaces );

// prototipi delle funzioni su alberi binari di ricerca
int bist_search( Bit_node p, int k );
void bist_insert( Bit_node *r, int item );



/***********************************************************************
INSERIRE QUI LA FUNZIONE MAIN E EVENTUALI ALTRE FUNZIONI AGGIUNTIVE
**********************************************************************/

void print_inorder(Bit_node p, int n1, int n2){
    if (!p)
        return;
    print_inorder(p->l, n1, n2);
    if (p->item >= n1 && p->item <= n2)
        printf("%d ", p->item);
    print_inorder(p->r, n1, n2);
}


int main(void){
    int *arr = calloc(1, sizeof(int));
    int count = 1;
    int c;
    Bit_node p = malloc(sizeof(struct bit_node));
    while(1){
        scanf("%d", &c);
        if (c == 0)
            break;
        if (bist_search(p, c) == 0){
            bist_insert(&p, c);
        }
    }
    int n1;
    int n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    if (n1 >= n2){
        printf("n1 deve essere minore di n2 \n");
        exit(-1);
    }
    print_inorder(p, n1, n2);
    printf("\n");
}



/*************************************************************
Implementazione delle funzioni generali su alberi binari
***************************************************************/

Bit_node bit_new( int item ) {
  Bit_node new = malloc( sizeof( struct bit_node ) );

  if ( new == NULL ) {
    printf( "err malloc\n" );
    exit(-1);
  }

  new -> l = new -> r = NULL;
  new -> item = item;
  return new;
}


void bit_printassummary( Bit_node p, int spaces ){
  int i;
  for ( i = 0; i < spaces; i++ )
    printf( "  " );
  printf( "*" );
  if (!p)
    printf( "\n" );

  else {
    printf( "%d\n", p -> item );
    if ( p -> l || p -> r ) {
      bit_printassummary( p -> l, spaces + 1 );
      bit_printassummary( p -> r, spaces + 1 );
    }
  }
}


/**************************************************************************
* Implementazione delle funzioni specifiche su alberi binari di ricerca
*************************************************************************/

int bist_search( Bit_node p, int k ) {
  if ( p ) {
    while ( p && ( k != p -> item ) )
      p = k < p -> item ? p -> l : p -> r;
  }
  if ( p == NULL ) return 0; // 0 e' usato come valore speciale (item NULL)
  else return p -> item;
}

// assumo che item non sia già nell'albero
void bist_insert(Bit_node *r, int item ) {
  Bit_node f, p = *r, new = bit_new( item );

  if ( p == NULL ) {
    /* inserisco nell'albero vuoto */
    *r = new;
    return;
  }
  while ( p != NULL ) {
    if ( item < p -> item ) {
      f = p;
      p = p -> l;
    } else { // quindi  item > p -> item
      f = p;
      p = p -> r;
    }
  }

/* f e' il padre del nuovo nodo */
  if ( item < f -> item ) {
    f -> l = new;
   }
  else
    f -> r = new;
}