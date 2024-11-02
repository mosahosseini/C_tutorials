#include <stdlib.h>
#include <stdio.h>

/*
### Exercises:
- Implement a linked list from scratch
- Implement a stack using arrays and pointers
- Create a binary tree with traversal functions
*/
typedef  struct Node {
    int data; 
    struct Node * next; 
} Node_t ;




Node_t* init_linked_list(int head_val){
    Node_t* head = NULL;
    head = (Node_t*) malloc(sizeof(Node_t));
    if (head ==NULL){
        printf("\nMemory allocation in init_linked_list failed!\n");
        EXIT_FAILURE;
    }

    head-> data = head_val;
    head-> next = NULL; 

    return head;

}


void add(Node_t * head ,int value){
    Node_t* last_node = head;
    int counter = 0 ; 

    while(last_node->next != NULL &&  counter <10){
        counter ++;
        last_node = last_node->next;
    }
    last_node->next = (Node_t * ) malloc(sizeof(Node_t));
    if (last_node -> next == NULL ){
        perror("\n Memory Allocation in add function failed! \n");
        EXIT_FAILURE;
    }
    last_node->next->data = value; 
    last_node->next->next = NULL; 
}

void print_linked_list(Node_t* head){
    Node_t* last_node = head ; 
    int counter = 0;
    while (last_node !=NULL){
        printf("\n element at position: %d is: %d " ,counter ,last_node -> data );
        last_node = last_node ->next;
        counter ++;
    } 
    free(head);
    free(last_node);
}

Node_t * get(Node_t * head , int value){
    Node_t * current_node = head;
    while(current_node != NULL){
        if (current_node-> data == value ){
            return current_node;
        }
        current_node = current_node->next;
    }

    printf("\n The value: %d  not found in the linked list!" , value);
}


Node_t* remove_element (Node_t* head , int value){
 
    if (head -> data == value){
        printf("trying to remove head... \n ");
        Node_t * temp = head; 
        head = head -> next;
        free(temp);
        return head;
    }
    Node_t * current_node = head ; 

    while (current_node-> next != NULL){
        if (current_node-> next -> data == value){
            current_node->next = current_node -> next ->next;
            return head ; 
        }
        current_node = current_node ->next;
    }
    printf("\n The value: %d  not found in the linked list!" , value);
    return head ; 
}
