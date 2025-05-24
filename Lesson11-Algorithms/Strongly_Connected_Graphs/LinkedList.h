#include<stdio.h>
#include<stdlib.h>

typedef struct L_Node {
    int node_num;  
    struct L_Node * next;
} L_Node;



void add(L_Node** start  ,int value  ){


    if ((*start) == NULL){
            (*start) = (L_Node*) malloc(sizeof(L_Node));
            (*start) -> node_num =  value; 
            (*start) -> next = NULL ; 
    }
    else {
    // Traverse to the end of the list and add the new node
    // to the end of the list
    L_Node * temp = *start;         
    while( temp -> next != NULL){
        temp = temp ->next; 

    }
    temp -> next = (L_Node*) malloc(sizeof(L_Node));
    temp -> next -> node_num = value; 
    temp -> next -> next = NULL ; 
    
    }
}



int  remove_node (L_Node ** start , int node_num)
{   int n_num = -1 ; 
    L_Node * temp = (*start); 
    if ( (*start) -> node_num == node_num){
        (*start) = (*start) -> next; 
        free(temp);
        return 0; // Return 0 if the first node is removed
    }
    else {

        while ( temp -> next != NULL)
        {    
            if (temp -> next -> node_num == node_num) {
                L_Node * to_remove = temp -> next;
                n_num = to_remove -> node_num;
                temp-> next = temp -> next -> next;
                free(to_remove);
                // Return the node number of the removed node
                return  n_num;
                
            }
            temp = temp -> next; 
        }

            return n_num;
    }
}

void free_mem(L_Node* start){
    L_Node * temp = start; 
    L_Node * temp2; 
    while (temp != NULL){
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }

}

void print_linked_list(L_Node * start){
    L_Node* temp = start; 
    while (temp != NULL){
        printf("node number : %d " , temp -> node_num );
        temp = temp -> next ; 
    }

    }