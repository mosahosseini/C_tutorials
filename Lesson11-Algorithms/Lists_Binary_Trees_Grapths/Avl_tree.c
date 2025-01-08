#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int key; 
int balance; // range of (-1 to 1) and it is height of 
int h;
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
    root -> h  =0; 
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


int get_balance(node* root ){
    int left = 0 ; 
    int right = 0;
    if (root -> left != NULL){
        left = update_balance(root->left);
        left++;
    }
    if (root -> right != NULL){
        right = update_balance(root->right);
        right ++; 
    }
    return right - left;
}

int insert(node** root , int key   ){
    int h = 0 ; 
    if ((*root) == NULL){
        (*root) = (node*) malloc(sizeof(node));
        if((*root)== NULL){
        perror("Memory allocation for insertion failed!!");
        exit(1);            
        }

        (*root) -> key = key; 
        (*root) -> left = NULL;
        (*root) -> right = NULL; 
        (*root) -> balance = 0;
        (*root) -> h = 1;
        return 1; 
    }
    else{

    if ( key < (*root) ->key ){
        h = insert( & (*root)->left , key  );
        
        if (h == 1){
            if ((*root) -> balance == 1){
                (*root)-> balance =0;
                h = 0;
            }

            else if ((*root) ->balance == 0){
                (*root)->balance = -1;
            }
            else{
                if ((*root) -> left -> balance == -1){
                    // single rigth rotation
                    node * s = (*root) -> left; 
                    (*root)->left = s->right ; // possible error; 
                    s->right = (*root);
                    (*root)->balance = 0;
                    (*root) = s;

                }
                else {
                    //Double right rot
                    node * s = (*root) -> left; 
                    node * t = (*root) -> left -> right;

                    s-> right = t-> left ;
                    t->left   = s; 
                    
                    (*root) -> left = t-> right; 
                    t-> right = (*root);


                    if (t->balance == -1){
                        t->right->balance = 1;
                    }
                    else{
                        t->right -> balance = 0 ; 
                    }

                    if (t->balance == 1){
                        s->balance = -1;
                    }
                    else{
                        s->balance = 0;
                    }
                    (*root)= t; 
                }
                
                (*root)->balance = 0;
                h=0;
            }
        }
//        (*root) -> balance = get_balance((*root));

    } 
    else if ( key > (*root) ->key  ) {
        h = insert(&(*root) -> right , key);

        if (h == 1){
            if ((*root)->balance == -1){
            (*root) -> balance = 0 ; 
            h = 0 ; 
            }

            if ((*root) -> balance == 0 ){
                (*root) -> balance = 1; 
            }

            else{
                if((*root) ->right -> balance == 1){
                    //single right rotation. 
                    node *s = (*root) -> right;
                    (*root) -> right  = s->left; 
                    s->left = (*root);
                    (*root) -> balance = 0 ; 
                    (*root) = s; 
                }
                else{
                    // double right rotation
                    node * s = (*root) -> right;
                    node * t = s->left ; 
                    s-> left = t->right; 
                    t->right = s; 
                    (*root) ->right = t; 

                    (*root) -> right = t-> left; 
                    t->left = (*root) ;
                    if (t->balance == 1){
                        t->left -> balance = -1;
                    }
                    else {
                        t->left -> balance = 0;
                    }

                    if(t-> balance == -1){
                        s-> balance = 1;
                    }
                    else {
                        s->balance = 0; 
                    }
    
                    (*root) = t ; 

                }
                (*root) -> balance = 0 ; 
                h = 0 ;

            }   
        }
//        (*root) -> balance = get_balance((*root));
    }
    }
    return h ;  
    
 }

node* delete(node** root , int key ){

if ((*root) == NULL){
    return (*root); 
}
else if( key < (*root)->key){
    delete((*root)-> left , key);
}
else if( key > (*root)->key){
    delete((*root)->right , key);
}
else { // key = (*root) ->key 
    if ((*root)-> left == NULL){
        node * temp = (*root) ->right; 
        (*root) = temp;
        (*root) -> balance = 0; 
        return temp; 
    }
    else if ((*root) -> right == NULL){
        node * temp = (*root) -> left ; 
        (*root) = temp ;
        (*root) ->balance = 0;  
        return temp;
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
    node * root = init_tree(20); 
    int h = insert(&root , 10);
    h = insert(&root , 15);
    h = insert(&root , 12) ; 
    

    print_tree(root , -1);

    free_tree(root);
}

