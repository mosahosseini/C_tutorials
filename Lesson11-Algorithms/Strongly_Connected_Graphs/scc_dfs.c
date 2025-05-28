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
        //If the neighbour is not visiter, we visit it. 
        if (graph[n_ind].df_num == -1)
        {
            dfs(graf, n_ind); // neigbours ind
        }

        if (graph[n_ind].on_stack && graph[n_ind].lowlink < graph[ind].lowlink)
        {
            graph[ind].lowlink = graph[n_ind].lowlink;
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

    while ((*s)->data[(*s)->top + 1] != terminator_node_val)
    {
        // printf("poped element is: %d\n" , pop(s));
        int index_of_graph_node = pop(s);
        graph[index_of_graph_node].on_stack = 0;
        add(&root, index_of_graph_node);
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
        printf("scc_%d: {", i);
        L_Node *temp = sccs[i].linked_list;
        while (temp != NULL)
        {
            printf(" %d ", temp->node_num);
            temp = temp->next;
        }
        printf("}\n");
    }
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int n;
    char *buffer = (char *)malloc(MAX_CHAR);

    if (fgets(buffer, MAX_CHAR, file) != NULL)
    {

        n = atoi(buffer);
    }
    else
    {
        printf("No input provided.\n");
        free(buffer);
        fclose(file);
        return -1;
    }

    Node *graph = (Node *)malloc(sizeof(Node) * n);

    for (int i = 0; i < n; i++)
    {

        if (fgets(buffer, MAX_CHAR, file) != NULL)
        {
            char *tok = strtok(buffer, " \n");
            L_Node *start = NULL;
            while (tok != NULL)
            {
                int neibour_num = atol(tok);
                add(&start, neibour_num);
                tok = strtok(NULL, " \n");
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

    dfs(&graph, 0);
    print_sccs(sccs);
    print_graph(graph, n);

    // Free allocated memory
    fclose(file);
    for (int i = 0; i < n; i++)
    {
        free_mem(graph[i].neighbors);
    }
    free(graph);
    free(buffer);
}