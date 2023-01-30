#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char *read_word(void){
    char *p = malloc(sizeof(char));
    char c; int size = 0;
    while (isalpha(c = getchar())){
        p[size] = c;
        size += sizeof(char);
        p = realloc(p, size);
    }
    p[size] = 0;
    return p;
}

int main(){
    char *p = read_word();
    for (int i = 0; i < strlen(p); i++){
        printf("%c", p[i]);
    }
}