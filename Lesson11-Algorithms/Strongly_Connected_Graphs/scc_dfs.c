#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Dynamic_Array.h"


/*Struct and global variables*/
Stack *stk = NULL;
dyn_array *sccs = NULL;
int DF_NUM = 0;
int MAX_CHAR = 120;

typedef struct node
{
    L_Node *neighbors;
    int df_num;
    int lowlink;
    int on_stack;
} Node;


// Function prototypes
void pop_stack(Node *graph, Stack **s, dyn_array **d_array, int terminator_node_val);



//DFS algorithm for finding the strongly connected components. 
void dfs(Node **graf, int ind)
{
    Node *graph = *graf; 

    if (graph[ind].df_num == -1) //if the node is not visited we push it to the stack and set the dfnum and lowlink to current DF_NUM also update the on_stack parameter.
    {
        push(&stk, ind); 
        graph[ind].df_num = DF_NUM;
        graph[ind].lowlink = DF_NUM;
        graph[ind].on_stack = 1;
        DF_NUM++;
    }

    L_Node *temp = graph[ind].neighbors; //Temporary pointer to the neighbours linked list. 
    int n_ind;
    while (temp != NULL)
    {
        n_ind = temp->node_num; // the index of current neighbour. 
        //If the neighbour is not visited, we visit it. 
        if (graph[n_ind].df_num == -1)
        {
            dfs(graf, n_ind); // neigbours ind
            if (graph[n_ind].lowlink < graph[ind].lowlink){
                graph[ind].lowlink = graph[n_ind].lowlink;
            }
        }
        else if (graph[n_ind].on_stack){
            if ( graph[n_ind].df_num < graph[ind].lowlink)
            {
                graph[ind].lowlink = graph[n_ind].df_num;
            }

        }

        temp = temp->next;
    }

    if (graph[ind].df_num == graph[ind].lowlink)
    {
        pop_stack(graph, &stk, &sccs, ind);
    }
}


/*This function will pop the stack 
and add the strongly connected components to a dynamic array for later representation*/
void pop_stack(Node *graph, Stack **s, dyn_array **d_array, int terminator_node_val)
{

    L_Node *root = NULL;
    Stack *stack = *s;
    if (stack == NULL)
    {
        printf("stack is null");
        return;
    }

    while ((*s)->top >= 0 )
    {
        // printf("poped element is: %d\n" , pop(s));
        int index_of_graph_node = pop(s);
        graph[index_of_graph_node].on_stack = 0;
        add(&root, index_of_graph_node);
        if (index_of_graph_node == terminator_node_val){
            break;
        }
    }

    push_dyn_array(d_array, root);
}

void print_graph(Node *graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        L_Node *temp = graph[i].neighbors;
        printf("\nNode %d: ", i);
        while (temp != NULL)
        {
            printf("%d ", temp->node_num);
            temp = temp->next;
        }
    }
    printf("\n");
}


void print_sccs(dyn_array *sccs)
{
    for (int i = 0; i <= sccs->top; i++)
    {   
        int counter = 0 ; 
        // printf("scc_%d: {", i);
        while (sccs[i].linked_list != NULL){
        L_Node *temp = sccs[i].linked_list;
        int max = -1; 
        while (temp != NULL)
        {   
            if (max < temp -> node_num ){
                max = temp -> node_num;
            }
            // printf(" %d ", temp->node_num);
            temp = temp->next;
        }
        if (counter == 0){
           printf("%d", max); 
           counter ++;
        }
        else {
            printf(" ");
            printf("%d", max);
        }
        remove_node(&sccs[i].linked_list , max);
        
    }
    printf("\n");


    }
}




int main()
{

    int n;
    char *buffer = (char *)malloc(MAX_CHAR);

    if (fgets(buffer, MAX_CHAR, stdin) != NULL)
    {
        n = atoi(buffer);
    }
    else
    {
        printf("No input provided.\n");
        free(buffer);

        return -1;
    }

    Node *graph = (Node *)malloc(sizeof(Node) * n);

    for (int i = 0; i < n; i++)
    {

        if (fgets(buffer, MAX_CHAR, stdin) != NULL)
        {   

            char *tok = strtok(buffer, " \n\t");

            L_Node *start = NULL;

            
            while (tok != NULL && tok[0] != '-' )
            {   

                int neibour_num = atol(tok);
                add(&start, neibour_num);
                tok = strtok(NULL, " \n\t");
            }
            graph[i].neighbors = start;
            graph[i].df_num = -1;
            graph[i].lowlink = -1;
            graph[i].on_stack = 0;
        }
        else
        {
            printf("No input provided.\n");
            // Free any already allocated linked lists
            for (int j = 0; j < i; j++)
            {
                free_mem(graph[j].neighbors);
            }
            return -1;
        }
    }

    for (int i = 0 ; i <n ; i++){
        int df_temp = graph[i].df_num;
        if (df_temp == -1){
        dfs(&graph, i);
        }
    }
    

    print_sccs(sccs);

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free_mem(graph[i].neighbors);
    }
    free(graph);
    free(buffer);
  
}