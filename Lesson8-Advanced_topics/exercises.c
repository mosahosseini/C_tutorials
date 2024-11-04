#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "linked_list.h"
/*
### Exercises:
- Implement a linked list from scratch
- Implement a stack using arrays and pointers
- Create a binary tree with traversal functions
*/

typedef struct bintree {
    int value; 
    struct bintree* left ; 
    struct bintree* right; 
}BinTree;


BinTree* init_tree(BinTree* tree , int value){
    tree->value = value ; 
    tree-> left = (BinTree*) malloc(sizeof(BinTree));
    tree->right = (BinTree*) malloc(sizeof(BinTree));
    tree-> left = NULL ; 
    tree-> right = NULL;
}

void insert(BinTree* tree , int value){
    BinTree* t = (BinTree*)malloc(sizeof(BinTree)) ; 
    t = tree; 
    
    int counter = 0; 
    while (counter < 10){
        if ( value <= t->value ){
            if ( t->left ==NULL){
                t->left = (BinTree*)malloc(sizeof(BinTree)) ; 
                t->left-> value = value ; 
                t->left->left =  (BinTree*)malloc(sizeof(BinTree)) ;  
                t->left->left = NULL ; 
                t->left->right = (BinTree*)malloc(sizeof(BinTree)) ;  
                t->left->right =  NULL; 
                return; 
            }
            else {
                t = t->left;
            }
            
        }
        else if(value > t-> value){
            if (t->right == NULL ){
                t->right = (BinTree*)malloc(sizeof(BinTree)) ; 
                t->right-> value = value ; 
                t->right->left =  (BinTree*)malloc(sizeof(BinTree)) ;  
                t->right->left = NULL ; 
                t->right->right = (BinTree*)malloc(sizeof(BinTree)) ;  
                t->right->right =  NULL; 
            }
            else{   
                t = tree->right; 
            }
        }
        counter ++;
    }
    
}

void print_tree(BinTree * tree , int depth){
    if (tree == NULL && depth == 0 ){
        printf("The tree is empty!");
        return;
    }else if(tree != NULL && depth == 0 ){
        printf("Root: %d\n" , tree->value);
    }
    if (tree-> right ==NULL  && tree -> left == NULL ){
        return ; 
    }
    else if (tree-> left != NULL && tree-> right == NULL ) {
        depth++;
        printf("depth: %d right: NULL  left: %d\n" , depth ,tree->left->value);
        print_tree(tree->left, depth);
    }
    else if (tree-> right != NULL && tree-> left == NULL ){
        depth++;
        printf("depth: %d  right : %d  left : NULL\n" , depth ,tree->right->value);
        print_tree(tree->right , depth  ); 
    } else {
        depth++;
        printf("depth: %d left : %d   right: %d\n" ,depth,  tree->left ->value , tree-> right -> value);
        print_tree(tree->left , depth );
        print_tree(tree-> right ,depth);
    }



}


int main(){
    /*
    
    Node_t* head = init_linked_list(0);
    add(head, 100);
    add(head,200);
    add(head , 3000) ;  
    head = remove_element(head , 200);

    print_linked_list(head);
    */


/*

    stack* stk = init_stack(5);
    push(stk , 100);
    push(stk ,2 );
    push(stk , 4);
    push(stk , 32);
    push(stk , 31);
    int k = pull(stk);
    printf("\n The top element in the stack is: %d" , stk->items[stk->top]);
    printf("\n The element removed is: %d" , k);
    int ind =  peek(stk ,32);
    printf("\n the index of 32 is: %d" , ind );
*/

    BinTree* root = (BinTree*)malloc(sizeof(BinTree));
    init_tree(root, 300);
    insert(root , 500 ); 
    insert(root , 350);
    insert(root, 200);
    insert(root , 100);
    insert(root , 50);
/*

    printf("root is : %d\n" , root->value);
    printf("left node is: %d\n" , root-> left -> value);
    printf("write node is : %d \n " , root -> right -> value);
    printf("left left node is: %d\n" , root -> left -> left -> value); 
*/   

print_tree(root , 0);

    return 0;
}