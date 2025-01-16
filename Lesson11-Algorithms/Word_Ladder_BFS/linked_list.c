#include<stdio.h>
#include<stdlib.h>

typedef struct g_node{
    int node_num;
    char* value;
}G_NODE;

typedef struct node {
    G_NODE* graph_node; 
    struct node * next;
} Node;

Node* init_node(char* value){
    Node * start = (Node*) malloc(sizeof(Node));
    start -> graph_node -> value = value;
    start -> next = NULL;
    return start;
}



int main(){
    char* w = "where";
    Node * start = init_node(w);
    printf("%s" , start->graph_node->value);


}