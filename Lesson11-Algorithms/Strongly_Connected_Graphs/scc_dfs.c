#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int MAX_CHAR = 120;
typedef struct node {
    L_Node * neighbors; 
    int df_num; 
    int lowlink; 
    int on_stack; 
} Node; 


void print_graph(Node * graph , int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        L_Node * temp = graph[i].neighbors; 
        printf("\nNode %d: ", i);
        while (temp != NULL){
            printf("%d ", temp -> node_num);
            temp = temp -> next; 
        }
    }
    printf("\n");
}
int main()
{

    FILE * file = fopen("input.txt" ,"r"); 
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n;
    char * buffer = (char*)malloc(MAX_CHAR);
    
    if (fgets(buffer, MAX_CHAR, file) != NULL) {
        printf("\n%s", buffer);
        n = atoi(buffer);
    } else {
        printf("No input provided.\n");
        free(buffer);
        fclose(file);
        return -1; 
    }

    Node * graph = (Node *) malloc(sizeof(Node) * n);

    for (int i = 0 ; i < n ; i++)
    {

    if (fgets(buffer, MAX_CHAR, file) != NULL) {
        // printf("\n%s", buffer);
        char * tok = strtok(buffer , " \n");
        L_Node * start = NULL;
        while (tok != NULL){
            int neibour_num = atol(tok);
            add(&start , neibour_num);
            tok = strtok(NULL , "\n"); 
        }
        graph[i].neighbors = start;
        graph[i].df_num = -1;
        graph[i].lowlink = -1;
        graph[i].on_stack = 0;

    } else {
        // printf("No input provided.\n");
        // Free any already allocated linked lists
        for (int j = 0; j < i; j++) {
            free_mem(graph[j].neighbors);
        }        return  -1 ; 
    }
    }

    fclose(file);
    print_graph(graph, n);
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free_mem(graph[i].neighbors);
    }   
    free(graph);
    free(buffer);
}