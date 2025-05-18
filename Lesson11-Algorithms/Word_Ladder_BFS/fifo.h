#include <stdlib.h>
#include <stdio.h>

typedef struct q_node{
    int value ; 
    struct q_node* next;
} q_node; 

q_node* last_q_node = NULL; 
void  init_fifo(q_node ** q , int val ){
    q_node* fifo = (q_node*) malloc(sizeof(q_node));
    if (fifo == NULL){
        printf("faile to initiate fifo och last");
    }

    fifo -> value  = val ; 
    fifo -> next = NULL ; 
    *q = fifo; 
    last_q_node = fifo;
}


void add_to_last(q_node**q , int val) {
    if ( *q == NULL) {
        q_node * temp ;  
        temp = (q_node*) malloc(sizeof(q_node));
        if (temp == NULL){
            printf("Failed to allocate memory in add to last ");
        }
        (*q) = temp ; 
        (*q) ->value = val; 
        (*q) -> next = NULL; 

    }
    else{
    last_q_node -> next = (q_node*) malloc(sizeof(q_node));
    if (last_q_node->next == NULL) {
        printf("Failed to allocate memory for new node.\n");
        return;
    }

    last_q_node->next->value = val;
    last_q_node->next->next = NULL;
    last_q_node = last_q_node->next;
    }
}


void add_to_queue(q_node ** fifo , int val) {
    if( (*fifo)== NULL){
        q_node * temp ;  
        temp = (q_node*) malloc(sizeof(q_node));
        if (temp == NULL){
            printf("Failed to allocate memory in add to last ");
        }
        (*fifo) = temp ; 
        (*fifo) ->value = val; 
        (*fifo) -> next = NULL; 
    }
    else{
        q_node * root = *fifo;
        while( root -> next != NULL){
            root  = root->next;
        }
        root -> next = (q_node*) malloc(sizeof(q_node));
        root -> next -> value = val; 
        root -> next -> next = NULL ; 

    }


}


int remove_head(q_node ** head){
    if (*head == NULL) return -1; // Optional: handle empty queue

    q_node* temp = *head;
    int removed_node_val = temp->value;
    *head = temp->next;
    free(temp);  // ✅ Free the removed node
    return removed_node_val;


}

void print_q(q_node * q){
    q_node * temp = q ;
    printf("[");
    while (temp  != NULL){
    printf(" %d " , temp ->value);
    temp = temp -> next ; 
    }
    printf("]\n");    

}
void free_fifo(q_node ** root){
    q_node* temp = *root; 
    q_node * temp2;
    while (temp != NULL){
        temp2 = temp->next ; 
        free(temp); 
        temp = temp2;    
    }
    *root = NULL;
    last_q_node = NULL;  // ✅ Add this
}

q_node * get_last(){
    return last_q_node;
}

// int main(){
//     q_node * root ; 
//     init_fifo(&root , 1);
//     add_to_last( 2);
//     add_to_last(4);
//     print_q(root);

//     int head = remove_head(&root);
//     int head2 = remove_head(&root);
//     int head3 = remove_head(&root);
//     printf("removed node : %d\n" , head);

//     print_q(root);
//     free_fifo(&root);
    
// }