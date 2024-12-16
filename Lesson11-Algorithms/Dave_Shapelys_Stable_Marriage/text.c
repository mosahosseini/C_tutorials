#include <stdio.h>
#include <stdlib.h>

// typedef struct {
// int * preferences;
// int visited ; 
// }man;

// typedef struct {
//      man* val; 
//      Node* next ;
// }Node ;

typedef struct node {
    int val; 
    struct node* next;  
} Node ; 


void add(Node* head , int value){
    Node* n = head ; 
    while (n -> next != NULL){
        n = n -> next;
    }
    n -> next = (Node*)malloc(sizeof(Node*));
    n -> next -> val = value;
    n -> next -> next = NULL; 
}

int remove_node(Node** head , int value ){
    if ((*head) ->val == value){
        *head = (*head)->next; 
        return (*head) -> val ; 
    }

    Node* n = (*head) ; 
    int removed_val ;
    while (n -> next != NULL){
        if(n -> next -> val == value){
            break; 
        }
        n = n->next; 
    }

    if (n->next == NULL){
        perror("The element you want to remove does not exist in the list!");
        return -1 ;
    }else if (n->next -> next == NULL){
        removed_val = n -> next -> val; 
        n->next = NULL;
    }else {      
    removed_val = n -> next -> val; 
    n->next = n->next->next;
    }

        
    return removed_val;
    }

void print_linked_list(Node* head){   
    printf("[");
    Node* n = head ; 
    while (n != NULL){
        printf(" %d " , n -> val);
        n = n -> next; 
    }
    printf("]");
}

int main() {
    Node* head;
    head -> val = 0;
    head -> next = NULL; 
    add(head , 1);
    add(head , 2);
    add(head , 3);
    print_linked_list(head);
    int s = remove_node(&head, 2);
    print_linked_list(head);
    return 0;
}

