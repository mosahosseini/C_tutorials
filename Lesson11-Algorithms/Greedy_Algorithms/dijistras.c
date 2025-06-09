#include <stdio.h>
#include <stdlib.h>
#include "define_llist.h"

// the edge data structure defined in define llist.h

/*
the edge data structure condains 
int dest;
float weight;
edge next;
*/



int main(){
    int MAX_LENGTH = 256;  
    int n; 
    char * buffer = (char*)malloc(MAX_LENGTH); 
    FILE * file = fopen("graph_input.txt" , "r");
    
    if(fgets(buffer, MAX_LENGTH , file ) != NULL){
        n = atoi(buffer);
    }
    else{
        printf("No input provided!");
        free(buffer);
        return -1;
    }

    list_t ** graph = (list_t **)malloc(sizeof(list_t*) * n);


    if(graph == NULL){
        printf("Something went wrong when initiating graph!");
        return -1;
    }


    for (int i = 0 ; i <n ; i++){
        list_t* list = new_list(compare , get_next, set_next );
        if(fgets(buffer, MAX_LENGTH , file ) != NULL){
            char * tok = strtok(buffer , " \n\t");
            while (tok != NULL){
                int dest , weight;
                sscanf(tok, "%d:%d", &dest, &weight);
                if (dest >= n) {
                    fprintf(stderr, "Error: destination node %d out of bounds for graph with %d nodes.\n", dest, n);
                    exit(EXIT_FAILURE);
                }

                edge * node = malloc(sizeof(edge));
                node -> dest = dest ; 
                node -> weight = weight;
                list_insert_front(list , node );
                tok = strtok(NULL, " \n\t");
            }
            graph[i] = list; 

        }    
    }

    // for (int i = 0; i < n; i++) {
    // list_free(graph[i]);
    // }
    // free(graph);
    for (int i = 0 ; i <n ; i++){
        printf("node: %d  \n" , i);
        list_foreach(graph[i] , &print_node);
    }

    free(buffer);
    fclose(file);
    
    return 0;
}