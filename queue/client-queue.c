#include "queue.h"
#include <stdio.h>
// gcc client.c queue-circular.c -o a.out
int main(){
    Queue q = new_queue();
    int n = 0;
    char ch;
    while ((ch = getchar()) != '0'){
        switch (ch) {
        case 'p':
            print_queue(q);
            break;
        case '+':
            scanf("%d", &n);
            enqueue(q, n);
            break;
        case '-':
            dequeue(q);
            break;
        case 'a':
         //   print_array(q);
            break;
        }
    }
}