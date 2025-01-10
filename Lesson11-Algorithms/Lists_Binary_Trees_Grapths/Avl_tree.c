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
                (*root) -> h = 0;

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
                (*root) -> h = 0 ; 
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
            (*root) -> h = 0;
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
                (*root) -> h = 0;
                h = 0 ;

            }   
        }
//        (*root) -> balance = get_balance((*root));
    }
    }
    return h ;  
    
 }



node* find_min(node* root ){
    if (root -> left == NULL)
    {
        return root; 
    }

    return find_min(root->left);
}


int max(int a , int b){
    if (a<=b)
    {
        return b;
    }
    else {
        return a; 
    }
}

int get_balancee(node* root){
    if (root == NULL){
        return 0; 
    }
    return root->left->h - root->right ->h;
}

int height(node * root){
    if (root == NULL){
        return 0;
    }
    return root -> h; 
}

// Function RightRotate(y):
//     x = y.left
//     T2 = x.right
    
//     // Perform rotation
//     x.right = y
//     y.left = T2

//     // Update heights
//     y.height = Max(Height(y.left), Height(y.right)) + 1
//     x.height = Max(Height(x.left), Height(x.right)) + 1
    
//     Return x

node*  right_rotate(node *root){
    node * s = root -> left; 
    node * t = s -> right ;
    s -> right = root; 
    root -> left = t ; 

    root -> h = max( height(root -> left) , height(root-> right));
    s -> h    = max( height(s -> left)  , height( s -> right )) ; 

    return s;
}


node* left_rotate( node *root){
    node* s = root -> right ; 
    node* t = s -> left ; 
    s-> left = root ; 
    root -> right = t; 

    root -> h = max( height(root -> left) , height(root -> right) ); 
    s -> h = max( height( s -> left) , height( s -> right)); 
    return s ; 
}







node* delete(node** root , int key ){

if ((*root) == NULL){
    return (*root); 
}
else if( key < (*root)->key){
    (*root) -> left = delete(&((*root)-> left) , key);
}
else if( key > (*root)->key){
    (*root)-> right = delete(&((*root)->right) , key);
}
else { 
    // key = (*root) ->key 
    //case 1 Node has no children 
    if ((*root)-> left == NULL && (*root)-> right == NULL ){
        return NULL;
    }
    //case 2 Node has one child
    else if ((*root)-> left == NULL){
        node * temp = (*root) ->right; 
        (*root) = NULL;
        return temp; 
    }
    else if ((*root) -> right == NULL){
        node * temp = (*root) -> left ; 
        (*root) = NULL ;
        //(*root) ->balance = 0;  
        return temp;
    }
    else {
        // Find the minimum inorder successor 
       node* temp = find_min( (*root) -> right );

       // Copy the inorder successors content to this node 
       (*root )-> key = temp->key ; 

       // Delete the inorder successor
       (*root ) -> right = delete(&((*root )->right) , temp -> key );

    }

    // Step 2: update the height of the current node
    (*root) -> h = max( height((*root) -> left) , height((*root) -> right) ) +1; 

    // Step 3: Get the balance factor
    int balance = get_balancee((*root));



//     // Step 4: Check the four cases of imbalance and apply the necessary rotation

//     // Left-Left (LL) Case: Left child of the left subtree is unbalanced
//     If balance > 1 AND GetBalance(root.left) >= 0:
//         Return RightRotate(root)

    if (balance > 1 && get_balancee( (*root) -> left ) >= 0){
        return right_rotate((*root));
    }

//     // Left-Right (LR) Case: Right child of the left subtree is unbalanced
//     If balance > 1 AND GetBalance(root.left) < 0:
//         root.left = LeftRotate(root.left)
//         Return RightRotate(root)

    if ( balance >1 && get_balancee( (*root) -> left ) >= 0  ){
        (*root) -> left = left_rotate( (*root) -> left);
        return right_rotate( (*root)); 
    }

//     // Right-Right (RR) Case: Right child of the right subtree is unbalanced
//     If balance < -1 AND GetBalance(root.right) <= 0:
//         Return LeftRotate(root)

    if (balance < -1 && get_balancee( (*root) -> right) <= 0) {
        return left_rotate((*root));
    }


//     // Right-Left (RL) Case: Left child of the right subtree is unbalanced
//     If balance < -1 AND GetBalance(root.right) > 0:
//         root.right = RightRotate(root.right)
//         Return LeftRotate(root)

//     Return root


    if ( balance < -1  && get_balancee( (*root) -> right) > 0 ){
        (*root) -> right = right_rotate( (*root) -> right );
        return left_rotate( (*root) ); 
    }




// Function RightRotate(y):
//     x = y.left
//     T2 = x.right
    
//     // Perform rotation
//     x.right = y
//     y.left = T2

//     // Update heights
//     y.height = Max(Height(y.left), Height(y.right)) + 1
//     x.height = Max(Height(x.left), Height(x.right)) + 1
    
//     Return x

// Function LeftRotate(x):
//     y = x.right
//     T2 = y.left
    
//     // Perform rotation
//     y.left = x
//     x.right = T2
    
//     // Update heights
//     x.height = Max(Height(x.left), Height(x.right)) + 1
//     y.height = Max(Height(y.left), Height(y.right)) + 1
    
//     Return y

// Function GetBalance(node):
//     If node is NULL:
//         Return 0
//     Return Height(node.left) - Height(node.right)

// Function Height(node):
//     If node is NULL:
//         Return 0
//     Return node.height

// Function FindMin(node):
//     current = node
//     While current.left is not NULL:
//         current = current.left
//     Return current



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
    node * root = init_tree(40); 
    int k [6] = {20,10,25,30,22,50};
    
    for( int i = 0 ; i<6 ; i++){
        int h = insert(&root , k[i]);
    }
    
    
    print_tree(root , -1);

    free_tree(root);
}

