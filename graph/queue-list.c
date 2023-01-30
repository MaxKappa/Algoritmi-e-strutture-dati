#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue new_queue(){
    Queue q = malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue q, Item n){
    if (is_empty_queue(q) == 1){
        Node new = malloc(sizeof(struct node));
        new->info = n;
        new->next = NULL;
        q->front = new;
        q->rear = new;
        return;
    }
    Node new = malloc(sizeof(struct node));
    new->info = n;
    new->next = NULL;
    q->front->next = new;
    q->front = new;
    return;

}

Item dequeue(Queue q){
    if (q->rear == q->front){
        Item p = q->rear->info;
        q->rear = NULL;
        q->front = NULL;
        return p;
    }
    Item p = q->rear->info;
    q->rear = q->rear->next;
    return p;
}

int is_empty_queue(Queue q){
    if (q->front == NULL && q->rear == NULL){
        return 1;
    }
    return 0;
}

void print_queue(Queue q){
    struct node *p = q->rear;
    printf("[ ");
    for(; p != NULL; p = p->next){
        printf("%d ", p->info);
    }
    printf("]\n");
}


