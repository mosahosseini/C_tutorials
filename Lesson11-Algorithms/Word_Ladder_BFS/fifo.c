#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int value ; 
    q_node* next;
} q_node; 

q_node* last_q_node;  
void  init_fifo(q_node ** q , int val ){
    q_node* fifo =  * q;
    fifo = (q_node*) malloc(sizeof(q_node));
    if (fifo == NULL){
        printf("faile to initiate fifo och last");
    }
    last_q_node = &fifo;
    fifo -> value  = val ; 
    fifo -> next = NULL ; 

}


void add_to_last(q_node ** last , int val){
    q_node * last_node = *last; 
    last_node ->next = (q_node*) malloc(sizeof(q_node));
    last_node -> next -> value = val ; 
    last_node -> next -> next = NULL ; 
    last_q_node = & last_node ->next; 

}


void add_to_queue(q_node ** fifo , int val) {
    q_node * root = *fifo;
    while( root -> next != NULL){
        root  = root->next;
    }
    root -> next = (q_node*) malloc(sizeof(q_node));
    root -> value = val; 
    root -> next -> next = NULL ; 

}


int remove_head(q_node ** head){
    q_node * root = *head ; 
    int removed_node_val = root ->value;
    root = root -> next ; 

    return removed_node_val;


}

int main(){


    
}