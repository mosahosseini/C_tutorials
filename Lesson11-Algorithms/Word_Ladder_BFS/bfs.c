#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include "test_edge.h"

#define WORD_LENGTH 5


typedef struct g_node{
    Dynamic_Array* edges;
    char  value[5]; 
    int pred; 
    int visited; 
}G_node;


int get_index(G_node* graph, int n ,  char* word) {

    int index ;
    for (int i= 0 ; i < n ; i++ ){
        if (strcmp(graph[i].value, word)== 0){
            index = i ; 
            graph[i].visited = 1; 
            break; 
    }
    return index ;
    }
}

int bfs (G_node * graph, int n  , char* start_word , char* dest_word){

    int start_ind = get_index(graph , n , start_word);
    
    

    return 0 ;

 


}







void construct_graph(G_node ** graph , int n){ 
    G_node * g_arr = * graph;
    for (int i = 0 ; i< n ; i++){
        for (int j= i+1 ; j < n-1 ; j++){
            if ( node_from_1_to_2(g_arr[i].value , g_arr[j].value)){

                add_to_dyn_arr(&g_arr[i].edges , j);

            }

            if ( node_from_1_to_2(g_arr[j].value , g_arr[i].value) ){
                
                add_to_dyn_arr(&g_arr[j].edges , i);
                
            }
        }
    }

}


void free_graph(G_node ** p_graph , int n){
    G_node * graph = *p_graph;
    for (int i = 0; i < n ; i++){
        free( graph[i].edges->array);
       free( graph[i].edges);
    }
    free(graph);
}
int main(){

    // FILE *file;
    // file = fopen("1.txt", "r"); // Opens file in read mode

    // if (file == NULL) {
    // perror("File opening failed");
    // return 1;
    // }
    
    int n ; 
    int q ; 
    char *word=  (char*) malloc(sizeof(char)*10);
    scanf("%d %d" , &n , &q);
    // fscanf(file , "%d %d" , &n , &q);

    printf("n = %d , q = %d\n" , n , q);
    G_node*  graph = (G_node*)malloc(n*sizeof(G_node));

    for (int i = 0 ; i < n ; i++) {
        // fscanf(file,"%s" , word);
        scanf("%s" , word);
        strcpy(graph[i].value , word); 
    }

    for (int i = 0 ; i < n ; i++) {
        // graph[i].edges = NULL;
        graph[i].edges =  (Dynamic_Array*) malloc(sizeof(Dynamic_Array));
        graph[i].edges->size = 0;
        graph[i].edges -> capacity = 0;
        graph[i].pred = -1;
        graph[i].visited = 0;
        // printf("\nNode number: %d   value: %s " , i, graph[i].value );
    }    

    construct_graph(&graph , n);

   for (int i = 0 ; i < n ; i++) {
        printf("\nNode number: %d   value: %s   Edges: [" , i, graph[i].value );
        if (graph[i].edges != NULL){
            for (int j = 0 ; j < graph[i].edges->size ; j++){
                printf(" %d " , graph[i].edges->array[j]);
            }
        }
         printf("]\n");


    }


     free_graph(&graph , n);

    free(word);
    // fclose(file);  




return 0;


}