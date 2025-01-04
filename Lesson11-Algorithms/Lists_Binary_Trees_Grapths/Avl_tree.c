#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int key; 
int balance; // range of (-1 to 1) and it is height of 
struct Node * left ;
struct Node * right; 
} node;
 
node *  init_tree(int key){
    node * root = (node*) malloc(sizeof(node));
    if (root == NULL){
        perror("Memory allocation for root failed!!");
        exit(1);
    }
    root -> key = key ; 
    root ->balance = 0 ; 
    root -> left = NULL; 
    root -> right = NULL;
    return root ;  
}


int update_balance(node* root){
    int r = 0 ; 
    int l = 0 ;
    int h = 0 ;
    if (root->left == NULL  && root -> right == NULL){
        return 0;
    } 
    
    if (root -> left != NULL){
        l = update_balance( root -> left);
    }

    if (root -> right != NULL){
        r = update_balance(root -> right);
    }

    if (l > r) {
        h = 1+l;
    }

    else {
        h = 1+r;
    }

    return h;
}





void add_node(node** root , int key   ){

    if ((*root) == NULL){
        (*root) = (node*) malloc(sizeof(node));
        if((*root)== NULL){
        perror("Memory allocation for insertion failed!!");
        exit(1);            
        }

        (*root) -> key = key; 
        (*root) -> left = NULL;
        (*root) -> right = NULL; 
        (*root) -> balance = update_balance(*root);
    }
    else{


    if ((*root) ->key >key  ){
        add_node( & (*root)->left , key  );
        (*root) -> balance = update_balance(*root);
    } 

    else if ((*root) ->key < key  ) {
        add_node(&(*root) -> right , key);
        (*root) -> balance = update_balance(*root);
    }
    else {
        perror("The key you want to insert, already exist in the tree");
    }
    } 

 }


void free_tree(node* root  ){
    if (root == NULL){
        return ; 
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}


void print_tree(node * root , int level){
    if (root == NULL){
        return ; 
    }

    ++level; 
    printf("Level: %d     value:%d    Balance:%d \n" , level , root -> key , root-> balance);

    print_tree(root->left , level);
    print_tree(root->right , level);

 
}




int main(){
    node * root = init_tree(5); 
    add_node(&root , 3 ); 
    add_node(&root , 7 ); 
    add_node(&root , 8 );
    add_node(&root , 9 );

    int left = update_balance(root ->left); 
    int right = update_balance(root -> right);
    printf("left h:%d      right h:%d\n\n" , ++left , ++right);
    print_tree(root , -1);

    free_tree(root);
}

