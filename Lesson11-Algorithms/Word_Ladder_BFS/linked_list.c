#include<stdio.h>
#include<stdlib.h>

typedef struct g_node{
    int node_num;
    char* value;
}G_NODE;

typedef struct node {
    int node_num; 
    char * value; 
    struct node * next;
} Node;

Node* init_node(char* value){
    Node * start = (Node*) malloc(sizeof(Node));
    if (start == NULL){
        printf("Initiation of linked list failed");
    }
    start -> node_num = 0; 
    start  -> value = value;
    start -> next = NULL;
    return start;
}

void add(Node** start  ,int node_num , char* value ){
    Node * temp = *start; 
    while( temp -> next != NULL){
        temp = temp ->next; 

    }
    temp -> next = (Node*) malloc(sizeof(Node));
    temp -> next -> value = value; 
    temp -> next -> node_num = node_num; 
    temp -> next -> next = NULL ; 
}



int  remove_node (Node ** start , int node_num)
{   int n_num = -1 ; 
    Node * temp = (*start); 
    if ( (*start) -> node_num == node_num){
        (*start) = (*start) -> next; 
        return 0;
    }
    else {

    while ( temp -> next != NULL)
    {    
        if (temp -> next -> node_num == node_num) {
            n_num = temp -> next -> node_num;
            temp-> next = temp -> next -> next;
            return  n_num;
            
        }
        temp = temp -> next; 
    }

        return n_num;
    }
}


int main(){
    char* s = "where";
    char * n1 = "there";
    char *n2 = "cat"; 
    Node * start = init_node(s);

    add(&start , 1, n1) ; 
    // printf("Node: %d , value: %s" , start -> next -> node_num , start -> next ->value);
    add(&start , 2, n2);
    
    Node* temp = start; 
    while (temp != NULL){
        printf("node number : %d    value: %s \n" , temp -> node_num , temp ->value );

        temp = temp -> next ; 
  
    }

    remove_node( &start , 2);
    printf("\n");
    temp = start ; 
    while (temp != NULL){
        printf("node number : %d    value: %s \n" , temp -> node_num , temp ->value );

        temp = temp -> next ; 
  
    }
    free(start); 



}