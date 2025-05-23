#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;  
    struct node * next;
} Node;

Node* init_linked_list(int val){
    Node * root =  (Node*) malloc(sizeof(Node));
    if (root == NULL){
        printf("initiation failed!");
        return NULL;
    }
    root -> value = val ; 
    root -> next  = NULL; 

    return root; 
}

void add(Node ** root , int val){
    if ((*root) == NULL){
        (*root) = (Node*) malloc( sizeof(Node));
        if ( (*root) == NULL){
            printf("linked list initiation failed!!");
            return;
        }
        (*root) -> value = val;
        (*root) ->next = NULL;
        return;
    }


    Node * temp = *root; 
    while (temp-> next != NULL){
        temp = temp -> next; 
    }
    temp -> next =  (Node * ) malloc(sizeof(Node)); 
    if (temp->next == NULL) {
        printf("Memory allocation failed during node addition.\n");
        return;
    }
    temp -> next -> value = val; 
    temp -> next -> next = NULL;


}


void free_linked_list(Node ** root){
    Node * temp = *root ; 
    Node * temp2; 

    while (temp != NULL){
        temp2 = temp -> next ; 
        free(temp);
        temp = temp2;
    }
    *root = NULL;  // Set root to NULL to avoid dangling pointer

}

void remove_nodes(Node ** root , int val){

    if ((*root) == NULL){
        printf("The linked list is empy, cannot remove from empy linked list");
        return;
    }

    while ((*root) -> value == val){
        (*root) = (*root) -> next ;  
    }

    Node * prev; 
    Node * curr= *root;
    prev = curr;  

    while (curr != NULL){
        if (curr -> value == val){
            curr = curr -> next;
            prev -> next = curr;
            
        }
        else{
        prev = curr; 
        curr = curr -> next;
        }
         
    }   

}


int main(){

    Node *root = init_linked_list(2); 
    add(&root , 2);
    add(&root , 1);
    remove_nodes(&root , 2);
    free_linked_list(&root);
}