#include <stdio.h>
#include "graph.h"

/*
n 5
+ 0 1
+ 0 2
+ 0 3
+ 4 1
+ 4 2
+ 4 3
+ 1 0
+ 1 4
+ 2 0
+ 2 4
+ 3 0
+ 3 4
p
*/

/*
n 5 
+ 0 1
+ 0 3
+ 1 2
+ 2 3
+ 3 0
+ 3 4
+ 4 2
p
*/




int main(){
    char ch; int v = 0; int w = 0; int n = 0;
    Graph g;
    while((ch = getchar()) != 'f'){
        switch (ch){
            case 'n':
                scanf("%d", &n);
                g = graph_new(n);
                break;
            case 'p':
                if (g == NULL){
                    printf("\n");
                    break;
                }
                graph_print(g);
                break;
            case '+':
                scanf("%d %d", &v, &w);
                graph_edgeinsert(g, v, w);
                break;
            case '-':
                graph_destroy(g);
                g = NULL;
                break;
            case 'd':
                graph_DFS(g, 0);
                break;
            case 'b':
                graph_BFS(g, 0);
                break;
        }
    }
}
