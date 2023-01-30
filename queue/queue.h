#ifndef QUEUE_H
#define QUEUE_H
#endif

typedef int Item;

/*
struct queue{
    Item *array;
    Item front, rear, size, tot;
}
*/


struct node{
    int info;
    struct node *next;
};

typedef struct node *Node;

struct queue{
    Node front;
    Node rear;
};

typedef struct queue *Queue;

//Create queue

//Queue new_queue(int); per circular

Queue new_queue();

// Put element on rear
void enqueue(Queue, Item);

// Remove and return element from front
Item dequeue(Queue);

// Return front element
Item frontValue(Queue);

 // Check if queue is empty
int is_empty_queue(Queue);

 // Print queue content
void print_queue(Queue);

//Print array
void print_array(Queue);    