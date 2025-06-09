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
    edge* graph ; 
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

    graph = (edge *)malloc(sizeof(edge) * n);

    if(graph == NULL){
        prinf("Something went wrong when initiating graph!");
        return -1;
    }


    for (int i = 0 ; i <n ; i++){
        if(fgets(buffer, MAX_LENGTH , file ) != NULL){
        int i = 0; 
        char * tok = strtok(buffer , "\n\t");
        while (tok != NULL){
            int dest , weight;
            sscanf("%d:%d" , &dest , &weight);
            if (dest >= n) {
                fprintf(stderr, "Error: destination node %d out of bounds for graph with %d nodes.\n", dest, n);
                exit(EXIT_FAILURE);
            }
            
        }

    }

    }

















    list_t* list = new_list(compare , get_next, set_next );
    for (int i = 0 ; i <5 ; ++i){
        edge * node = malloc(sizeof(edge));
        node -> dest = i ; 
        node -> weight = (float)(5-i);
        list_insert_front(list , node);
    }

    int key = 3; 
    edge * found = list_find(list , &key);
    if (found){
        printf("Found nodes dest: %d weight: %d \n" , found ->dest , found ->weight);
    }
    list_foreach(list , &print_node);
    list_remove(list , &key);
    list_foreach(list , &print_node); 
    list_free(list);   
    return 0;
}