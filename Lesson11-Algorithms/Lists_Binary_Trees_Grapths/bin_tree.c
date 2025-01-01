#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int val ; 
struct Node * left ; 
struct Node * right ; 
}node;


node* init_tree(int val){
    node* n = (node*) malloc(sizeof(node));
    n -> val = val ; 
    n -> left = NULL ; 
    n -> right = NULL ; 
    
    return n; 
}



void add_node(node** root , int val){
    if ((*root) == NULL){
        (*root) = (node*) malloc(sizeof(node));
        (*root) -> val = val; 
        (*root) -> left = NULL;
        (*root) -> right = NULL; 
    }
    else if ((*root) ->val <=val  ){
        add_node( & (*root)->left , val);
    }
    else {
        add_node(&(*root) -> right , val);
    }

}


int main(){

    node * root = init_tree(5); 
    add_node(&root , 3); 
    add_node(&root , 7); 
    add_node(&root , 4);
    add_node(&root , 6);
    

}