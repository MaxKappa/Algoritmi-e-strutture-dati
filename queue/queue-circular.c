#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* printf("q->front = %d\n", q->front);
    printf("q->rear = %d\n", q->rear);
    printf("q->size = %d\n", q->size);
*/


Queue new_queue(int tot){
    Queue q = malloc(sizeof(struct queue));
    q->array = calloc(tot, 4);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->tot = tot;
    return q;

}

void enqueue(Queue q, Item n){
    if (is_empty_queue(q) == 1){
        *(q->array) = n;
        q->size++;
        return;
    }
    *(q->array+(q->rear+1)%(q->tot)) = n;
    q->rear++;  
    q->size++;
    return;    
}

Item wdequeue(Queue q){
    if (is_empty_queue(q) == 1){
        printf("LISTA VUOTA");
        return 0;
    }
    *(q->array+q->front) = 0;
    q->front++;
    q->size--;
    return *(q->array+q->front);
}

Item frontValue(Queue q){
    return q->front;
}

int is_empty_queue(Queue q){
    if (q->size == 0)
        return 1;
    return 0;
}

void print_queue(Queue q){
    int count = 0;
    printf("[ ");
    for (int i = q->front;count != q->size; i = (i+1) % q->tot){ 
        printf("%d ", *(q->array+i));
        count++;
    }
    printf("]\n");
}

void print_array(Queue q){
    printf("Array = [ ");
    for (int i = 0; i < q->tot; i++){
        printf("%d ", *(q->array+i));
    }   
    printf("]\n");
}