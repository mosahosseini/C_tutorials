#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "linked_list.h"
#include "dynamic_array.h"
#include <string.h>
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


BinTree* init_tree( int value){
    BinTree * tree = (BinTree*)malloc(sizeof(BinTree));
    tree->value = value ; 
    tree-> left = (BinTree*) malloc(sizeof(BinTree));
    tree->right = (BinTree*) malloc(sizeof(BinTree));
    tree-> left = NULL ; 
    tree-> right = NULL;
    return tree ; 
}


// alternative 1: using while loop
void insert(BinTree* tree , int value){
    BinTree* t = (BinTree*)malloc(sizeof(BinTree)) ; 
    t = tree; 
    
    int counter = 0; 
    while (1){
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
                return; 
            }
            else{   
                t = t->right; 
            }
        }

    }
    
}


// Insert can be implemented using recursion. 

void insert2(BinTree ** root ,int val ){
    if (*root == NULL){
        *root = (BinTree * ) malloc(sizeof(BinTree ));
        (*root) -> value = val ; 
        (*root) -> left = NULL ; 
        (*root) -> right = NULL; 
        return ;
    } else {
        if (val <=  (*root) ->value ){
            insert2(&(*root) -> left , val);
        }else if (val > (*root) -> value ){
            insert2(&(*root)->right , val);
        }
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
        printf("depth: %d left: %d  right: NULL\n" , depth ,tree->left->value);
        print_tree(tree->left, depth);
    }
    else if (tree-> right != NULL && tree-> left == NULL ){
        depth++;
        printf("depth: %d  left : NULL  right : %d\n" , depth ,tree->right->value);
        print_tree(tree->right , depth  ); 
    } else {
        depth++;
        printf("depth: %d left : %d   right: %d\n" ,depth, tree->left ->value, tree-> right -> value );
        print_tree(tree->left , depth );
        print_tree(tree-> right ,depth);
    }

}

//function for traversing the bst.
void travers_tree(BinTree * root , DynamicArray** arr , char mode [5]){
    if (root == NULL){
        append(*arr , -1);
        return ; 
    }
    else{

        if (root ->left == NULL && root->right == NULL){
            append(*arr , root->value); 
            return;
        }
        else{
            if (strcasecmp(mode , "pre") == 0){
                append(*arr , root->value); 
                travers_tree(root->left , arr , mode);
                travers_tree(root->right , arr , mode); 

            }
            else if (strcasecmp(mode , "post") == 0){ 
                travers_tree(root->left , arr , mode);
                travers_tree(root->right , arr , mode);
                append(*arr , root->value);

            }
            else if (strcasecmp(mode , "in") == 0){ 
                travers_tree(root->left , arr , mode);
                append(*arr , root->value);
                travers_tree(root->right , arr , mode);
            }
            else{
                printf("\nplease provide a valid mode: (in) for in order travers , (pre) for pre order travers and (post) for post order travers\n");
            }

  

        }
        
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

/*

    
BinTree  *root = init_tree(300);

insert(root , 500 ); 
insert(root , 600);
insert(root , 350);
insert(root, 200);
insert(root , 100);
insert(root , 250);
//print_tree(root , 0);

char  mode [50] = "in";

DynamicArray dyn_arr;
DynamicArray * arr = &dyn_arr;
initArray(arr , 4); 
travers_tree(root , &arr , mode );
print_array(arr);
freeArray(arr);
*/
    return 0;

}