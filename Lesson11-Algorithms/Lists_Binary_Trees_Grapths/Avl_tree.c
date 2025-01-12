#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int key; 
int h;
struct Node * left ;
struct Node * right; 
} node;
 
node *  init_tree(int key){
    // Initiates an AVL tree , (creates a node and )
    node * root = (node*) malloc(sizeof(node));
    if (root == NULL){
        perror("Memory allocation for root failed!!");
        exit(1);
    }
    root -> key = key ; 
    root -> h  =1; 
    root -> left = NULL; 
    root -> right = NULL;
    return root ; 

}


node* find_min(node* root ){
    /*
    Because the a binary tree is ordered, the left subtrees will contain the minimum,
    so we traversing the left of the root untill we reach the left leaf. 
    */ 
    
    if (root -> left == NULL)
    {
        return root; 
    }

    return find_min(root->left);

}


int max(int a , int b){
    /*
    returns the max of two integers
    */

    if (a<=b){
        return b;
    }
    else {
        return a; 
    }

}


int height(node * root){
    //the the root is only a node , then the height is 1 else just return the height of it. 
    if (root == NULL){
        return 1;
    }
    return root -> h;

}


int get_balance(node* root ){
    /*
    the balance of a leaf node is 0 , it the node is not a leaf node the node balance is the difference between the height of the left 
    and right nodes
    */
    
    if (root == NULL){
        return 0; 
    }
    return height(root->left) - height(root->right);
}


node* left_rotate( node **root){
    /*
    the function performs a left rotation
            root                s
                \             /  \
                 s   ->   root    s2
                / \          \  
                t  s2         t

    */
    node* s = (*root) -> right ; 
    node* t = s -> left ; 
    s-> left = (*root) ; 
    (*root) -> right = t; 
    (*root) -> h = max( height((*root) -> left) , height((*root) -> right) ); 
    s -> h = max( height( s -> left) , height( s -> right)); 
    (*root) =s ; 
    return s ; 
}


node*  right_rotate(node **root){
    /*
    the function performs a left rotation
        root                s
       /                  /  \
      s         ->      s2    root
    /  \                     / 
  s2    t                   t

    */

    node * s = (*root) -> left; 
    node * t = s -> right ;
    s -> right = (*root); 
    (*root) -> left = t ; 
    (*root) -> h = max( height((*root) -> left) , height((*root)-> right));
    s -> h    = max( height(s -> left)  , height( s -> right )) ; 
    (*root) = s; 
    return s;
}


void  insert(node** root , int key   ){
    // This function is for inserting a node in the avl tree. We might need to perform Left , Right , Left Right (LR) or Right Left (RL) rotation. 

    // if root null, insert the new node
    if ((*root) == NULL){
        (*root) = (node*) malloc(sizeof(node));

        if((*root)== NULL){
            perror("Memory allocation for insertion failed!!");
            exit(1);            
        }

        (*root) -> key = key; 
        (*root) -> left = NULL;
        (*root) -> right = NULL; 
        (*root) -> h = 1; 
    }

    else{
        //if the node we want to insert have a lower key than the current node, go to left 
        if ( key < (*root) ->key ){
            insert( & (*root)->left , key  );
            (*root) -> h = max(height( (*root) -> left ) , height( (*root) -> right )) +1 ;  // uppdate height
            int balance = get_balance((*root));
            
            //left heavy ->  rotate to right 
            if ( balance > 1 && get_balance((*root) -> left) >=0 ){
                // single right rotation
                (*root) = right_rotate(root);
            }

            else if ( balance > 1 && get_balance((*root) -> left) <0 )  {

                // first you perform a left rotation of roots left child then you rotate the root to the right
                (*root) -> left = left_rotate( &(*root) -> left);
                (*root) = right_rotate( root);

            }
        } 

        else if ( key > (*root) ->key  ) {

            insert(&(*root) -> right , key);
            (*root) -> h = max(height( (*root) -> left ) , height((*root) -> right )) +1 ;  //adjusting the heigh
            int balance = get_balance((*root));            
                //right heavy
            if( balance < -1 && get_balance((*root) -> right) <= 0){
                (*root) = left_rotate(root);
            }
            //double rotation RL
            else if ( balance < -1 && get_balance((*root) -> right) > 0) {
                (*root) -> right = right_rotate( &(*root) -> right );
                (*root) = left_rotate( root ); 

            }
        }

    }
   
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

            return temp;
        }
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
    int balance = get_balance((*root));



    // Step 4: Check the four cases of imbalance and apply the necessary rotation

    // Left-Left (LL) Case: Left child of the left subtree is unbalanced
    // If balance > 1 AND GetBalance(root.left) >= 0:
    //  Return RightRotate(root)


    if (balance > 1 && get_balance( (*root) -> left ) >= 0){
        return right_rotate(root);
    }

    // Left-Right (LR) Case: Right child of the left subtree is unbalanced
    //If balance > 1 AND GetBalance(root.left) < 0:
    //root.left = LeftRotate(root.left)
    // Return RightRotate(root)

    if ( balance >1 && get_balance( (*root) -> left ) < 0  ){
        (*root) -> left = left_rotate( &(*root) -> left);
        return right_rotate( root); 
    }

    // Right-Right (RR) Case: Right child of the right subtree is unbalanced
    //     If balance < -1 AND GetBalance(root.right) <= 0:
    //         Return LeftRotate(root)

    if (balance < -1 && get_balance( (*root) -> right) <= 0) {
        return left_rotate(root);
    }


    // Right-Left (RL) Case: Left child of the right subtree is unbalanced
    //     If balance < -1 AND GetBalance(root.right) > 0:
    //         root.right = RightRotate(root.right)
    //         Return LeftRotate(root)

    //Return root

    if ( balance < -1  && get_balance( (*root) -> right) > 0 ){
        (*root) -> right = right_rotate( &(*root) -> right );
        return left_rotate( root ); 
    }

return (*root);


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
    printf("Level: %d     value:%d    Balance:%d \n" , level , root -> key , get_balance(root));

    print_tree(root->left , level);
    print_tree(root->right , level);

 
}




int main(){
    node * root = init_tree(40); 
    int k [6] = {20,10,25,30,22,50};
    
    for( int i = 0 ; i<6 ; i++){
        insert(&root , k[i]);
    }

    node * deleted_node =  delete( &root , 25);
    
    
    print_tree(root , -1);

    free_tree(root);
}

