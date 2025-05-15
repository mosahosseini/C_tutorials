#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include "test_edge.h"
#include "stack.h"
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
            break; 
    }
    return index ;
    }
}


int bfs (G_node * graph, int n  , char* start_word , char* dest_word){

    int start_ind = get_index(graph , n , start_word);
    Stack *q;
    init_stack(&q , start_ind);
    int counter = 0;
    while (q ->size != -1 | counter < 100){
        int ind = pop(q);
        graph[ind].visited = 1;
        // char *  temp_w= (char*) malloc(sizeof(char)*10); 
        // temp_w = graph[ind].value;
        if (strcmp(graph[ind].value , dest_word ) == 0 ){
            // free(temp_w);
            int edge_count = 0;
            int temp_ind = -1; 
            int counter2= 0;
            while (temp_ind != start_ind || counter2 == 100){
                temp_ind = graph[ind].pred;
                edge_count ++;
                counter2++;
            }
            return edge_count;
        }
        // free(temp_w);
        for (int i = 0 ; i < graph[ ind].edges -> size ; i++ ){
            int edge_ind = graph[ind].edges->array[i];
            graph[edge_ind].pred = ind;
            if (graph[edge_ind].visited == 0){
                push(q,edge_ind );
            }
        }
    }
    

    return -1 ;

 


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

    FILE *file;
    file = fopen("1.txt", "r"); // Opens file in read mode

    if (file == NULL) {
    perror("File opening failed");
    return 1;
    }
    
    int n ; 
    int q ; 
    char *word=  (char*) malloc(sizeof(char)*10);
    // scanf("%d %d" , &n , &q);
    fscanf(file , "%d %d" , &n , &q);

    printf("n = %d , q = %d\n" , n , q);
    G_node*  graph = (G_node*)malloc(n*sizeof(G_node));

    for (int i = 0 ; i < n ; i++) {
        fscanf(file,"%s" , word);
        // scanf("%s" , word);
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

    char *start_word =(char*) malloc(sizeof(char)*10);
    char *dest_word =(char*) malloc(sizeof(char)*10); 
    for (int i = 0 ; i<q ; i++){
        fscanf(file,"%s %s" , start_word , dest_word);
        int num_edge = bfs(graph , n , start_word , dest_word);
        if (num_edge == -1){
            printf("\nimpossible!");
        }
        else{
            printf("\n%d", num_edge);
        }
    }



    free_graph(&graph , n);

    free(word);
    // fclose(file);  




return 0;


}