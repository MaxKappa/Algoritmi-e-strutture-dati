#include <stdio.h>
#include <stdlib.h>

struct queue{
    int key;
    int priority;
    struct queue *next;
};

typedef struct queue *Queue;

int deleteMin(Queue q);
void insert(Queue q, int key, int priority);
void changeKey(Queue q, int key, int priority);
int IsEmpty(Queue q);
Queue cancel(Queue q, int n);

int findMinPriority(Queue q){
    Queue p = q;
    int min = 1000;
    while(p){
        if (p->priority < min)
            min = p->priority;
        p = p->next;
    }
    return min;
}

Queue cancel(Queue q, int n){
    Queue prec;
    Queue curr;
    for(prec = NULL, curr = q; curr != NULL && curr->priority != n; prec = curr, curr = curr->next);
    if (curr == NULL)
            return q;
    if (prec == NULL)
        q = q -> next;
    else     
        prec -> next = curr -> next;    
    free(curr);
    curr = NULL;
    return q;
}

int deleteMin(Queue q){
    if (IsEmpty(q)){
        q = NULL;
        return -1;
    }
    Queue prev;
    Queue succ;
    int min = findMinPriority(q);
    q = cancel(q, min);
    return min;
}

Queue newQueue(int key, int priority){
    Queue q = calloc(1, sizeof(struct queue));
    q->key = key;
    q->priority = priority;
    return q;
}


void insert(Queue q, int key, int priority){
    Queue prev;
    Queue succ;
    for(prev = NULL, succ = q; succ; prev = succ, succ = succ -> next);
    if (!prev){
        succ = calloc(1, sizeof(struct queue));
        succ->key = key;
        succ->priority = priority;
    } else {
        succ = calloc(1, sizeof(struct queue));
        succ->key = key;
        succ->priority = priority;
        prev->next = succ;
    }
    return;
}

void changeKey(Queue q, int key, int priority){
    while(q){
        if (q -> key == key)
            q->priority = priority;
    }
    return;
}

int IsEmpty(Queue q){
    if (q == NULL)
        return 1;
    return 0;
}

void print_queue(Queue q){
    if (!q){
        printf("\n");
        return;
    }
    while(q){
        printf("key = %d, priority = %d\n", q->key, q->priority);
        q = q->next;
    }
    return;
}


int main(){
    Queue q = newQueue(4, 3);
    insert(q, 5, 2);
    insert(q, 1, 8);
    insert(q, 2, 1);
    print_queue(q);
    printf("%d\n",deleteMin(q));
    printf("%d\n",deleteMin(q));
    printf("%d\n",deleteMin(q));
    printf("%d\n", IsEmpty(q));
    q = NULL;
    print_queue(q);

}