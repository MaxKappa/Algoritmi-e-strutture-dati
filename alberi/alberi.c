#include <stdio.h>
#include <stdlib.h>

typedef int Item;

struct bit_node{
    Item item;
    struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

Bit_node bit_new(Item n);
void bit_preorder(Bit_node root);
void bit_inorder(Bit_node root);
void bit_postorder(Bit_node root);
void bit_printassummary(Bit_node root, int spaces);
Bit_node bit_arr2tree(Item a[], int size, int i);

Bit_node bit_new(Item n){
    Bit_node root = malloc(sizeof(struct bit_node));
    root->item = n;
    root->l = NULL;
    root->r = NULL;
    return root;
}

void bit_preorder(Bit_node root){
    if (root == NULL){
        return;
    }
        printf("%d ", root->item);
        bit_preorder(root->l);
        bit_preorder(root->r);
}

void bit_inorder(Bit_node root){
    if (root == NULL){
        return;
    }
    bit_inorder(root->l);
    printf("%d ", root -> item);
    bit_inorder(root->r);
}

void bit_postorder(Bit_node root){
    if (root == NULL){
        return;
    }
    bit_postorder(root->l);
    bit_postorder(root->r);
    printf("%d ", root->item);
}


void bit_printassummary(Bit_node root, int spaces){
    if (root == NULL){
        for (int i = 0; i < spaces; i++){
            printf(" ");
        }
        printf("*\n");
        return;
    }
    for (int i = 0; i < spaces; i++){
        printf(" ");
    }
    printf("*%d \n", root->item);
    spaces++;
    bit_printassummary(root->l, spaces);
    bit_printassummary(root->r, spaces);
}


Bit_node bit_arr2tree(Item a[], int size, int i){
    Bit_node root = malloc(sizeof(struct bit_node));
    root->item = a[i];
    if (i*2+1 > size || i*2+2 > size){
        root->r = NULL;
        root->l = NULL;
        return root;
    }
    root->l = bit_arr2tree(a, size, i*2+1);
    root->r = bit_arr2tree(a, size, i*2+2);
    return root;
}


int main(){
    int a[] = {69, 89, 28, 39, 66, 44, 12, 2, 71};
    Bit_node root = bit_arr2tree(a, 9, 0);
    bit_preorder(root);
    printf("\n");
}