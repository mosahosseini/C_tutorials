#include <stdio.h>
#include <stdlib.h>

typedef struct person {
int index;
int * preferences;
int visited ; 
}man;

typedef struct node {
    man *person; 
    struct node* next;  
} Node ; 

Node* init_head( man* person){
    Node* head = (Node*) malloc(sizeof(Node*));
    if (head == NULL){
        perror("Memory allocation of head failed!");
    }
    head->person = person; 
    head->next = NULL; 
}

void add(Node* head , man* new_person){
    Node* n = head ; 
    while (n -> next != NULL){
        n = n -> next;
    }
    n -> next = (Node*)malloc(sizeof(Node*));
    n -> next -> person = new_person;
    n -> next -> next = NULL; 
}

man* remove_node(Node** head , int ind ){
    man* removed_person;
    if ((*head) ->person->index == ind){
        removed_person = (*head)->person;
        *head = (*head)->next; 
        return removed_person;
    }

    Node* n = (*head) ; 
    while (n -> next != NULL){
        if(n -> next -> person->index == ind){
            break; 
        }
        n = n->next; 
    }

    if (n->next == NULL){
        perror("The element you want to remove does not exist in the list!");
        return removed_person;
    }else if (n->next -> next == NULL){
        removed_person = n -> next -> person; 
        n->next = NULL;
    }else {      
    removed_person = n -> next -> person; 
    n->next = n->next->next;
    }

        
    return removed_person;
    }

void print_linked_list(Node* head , int prefs ){   

    Node* n = head ; 
    while (n != NULL){
        printf(" man %d    pref: " , n -> person->index);
        printf("[");
        for (int i = 0 ;i<prefs ; i++){
            printf(" %d " , n->person->preferences[i]);
        }
        printf("]\n");
        n = n -> next; 
    }
}


