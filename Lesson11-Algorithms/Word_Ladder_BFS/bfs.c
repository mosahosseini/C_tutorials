#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include "test_edge.h"
#include "stack.h"
#define WORD_LENGTH 5


typedef struct g_node{
    Dynamic_Array* edges;
    char *  value; 
    int pred; 
    int visited; 
}G_node;


int get_index(G_node* graph, int n ,  char* word) {

    int index ;
    for (int i= 0 ; i < n ; i++ ){
        G_node * temp = &graph[i];
        int val = strcmp(graph[i].value, word);
        if (strcmp(graph[i].value, word)== 0){
            index = i ; 
            break; 
        }
    }
    return index ;
}


int bfs (G_node * graph, int n  , char* start_word , char* dest_word){

    int start_ind = get_index(graph , n , start_word);
    Stack *q  ;
    init_stack(&q , start_ind);
    int counter = 0;
    int ind = pop(q);
    graph[ind].visited = 1;
    while (ind != -1 & counter < 100000){
        G_node * temp = &graph[ind];
        // char *  temp_w= (char*) malloc(sizeof(char)*10); 
        // temp_w = graph[ind].value;
        if (strcmp(graph[ind].value , dest_word ) == 0 ){
            // free(temp_w);
            int edge_count = 0;
            int temp_ind = ind; 
            int counter2= 0;
            while (temp_ind != start_ind && counter2 < 10000){
                temp_ind = graph[temp_ind].pred;

                edge_count ++;
                counter2++;
            }
            free_stack(&q);
            return edge_count;
        }
        // free(temp_w);
        for (int i = 0 ; i < graph[ ind].edges -> size ; i++ ){
            int edge_ind = graph[ind].edges->array[i];
            G_node * temp2 = &graph[edge_ind];

            if (graph[edge_ind].visited == 0){
                graph[edge_ind].visited = 1;
                graph[edge_ind].pred = ind;
                push(q,edge_ind );
            }
        }
        ind = pop(q);
    }
    free_stack(&q);

    return -1 ;
}



void construct_graph(G_node ** graph , int n){ 
    G_node * g_arr = * graph;
    for (int i = 0 ; i< n-1 ; i++){
        for (int j= i+1 ; j < n ; j++){
            // if ( node_from_1_to_2(g_arr[i].value , g_arr[j].value)){
                if ( node_from_1_to_2(g_arr[i].value , g_arr[j].value)){
                add_to_dyn_arr(&g_arr[i].edges , j);

            }

            if ( node_from_1_to_2(g_arr[j].value , g_arr[i].value) ){
                
                add_to_dyn_arr(&g_arr[j].edges , i);
                
            }
        }
    }

}

void restore_default_value(G_node*  graph , int n ){
    for (int i = 0 ; i <n  ; i++){
        graph[i].pred=-1;
        graph[i].visited = 0;
    }
}


void free_graph(G_node ** p_graph , int n){
    G_node * graph = *p_graph;
    for (int i = 0; i < n ; i++){
        if (graph[i].value != NULL){
            free(graph[i].value);
        }
        
        if (graph[i].edges->array != NULL){
            free( graph[i].edges->array);
        }
        
        if (graph[i].edges != NULL){
            free( graph[i].edges);
        }

    }
}
int main(){

    FILE *file;
    file = fopen("3medium1.in", "r"); // Opens file in read mode
    FILE *outfile ; 
    outfile = fopen("output.txt" , "w");
    if (outfile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    if (file == NULL) {
    perror("File opening failed");
    return 1;
    }
    
    int n ; 
    int q ; 
    char *word=  (char*) malloc(sizeof(char)*6);
    // scanf("%d %d" , &n , &q);
    fscanf(file , "%d %d" , &n , &q);

    // printf("n = %d , q = %d\n" , n , q);
    G_node*  graph = (G_node*)malloc(n*sizeof(G_node));

    for (int i = 0 ; i < n ; i++) {
        // graph[i].edges = NULL;
        graph[i].value = (char*)malloc(sizeof(char)*6);
        graph[i].edges =  (Dynamic_Array*) malloc(sizeof(Dynamic_Array));
        graph[i].edges->array = NULL;
        graph[i].edges->size = 0;
        graph[i].edges -> capacity = 0;
        graph[i].pred = -1;
        graph[i].visited = 0;
        // printf("\nNode number: %d   value: %s " , i, graph[i].value );
    }    

    for (int i = 0 ; i < n ; i++) {
        fscanf(file,"%s" , word);
        // scanf("%s" , word);
        strcpy(graph[i].value , word); 
    }



    construct_graph(&graph , n);

//    for (int i = 0 ; i < n ; i++) {
//         printf("\nNode number: %d   value: %s   Edges: [" , i, graph[i].value );
//         for (int j = 0 ; j < graph[i].edges->size ; j++){
//                 printf(" %d " , graph[i].edges->array[j]);
//         }
//          printf("]\n");


//     }

    char *start_word =(char*) malloc(sizeof(char)*10);
    char *dest_word =(char*) malloc(sizeof(char)*10); 

    // strcpy(start_word ,"baccc" );
    // strcpy(dest_word ,"bccba" );
    for (int i = 0 ; i<q ; i++){
        fscanf(file,"%s %s" , start_word , dest_word);
        // scanf("%s %s" , start_word ,dest_word );
        int num_edge = bfs(graph , n , start_word , dest_word);
        restore_default_value(graph , n);
        if (num_edge == -1){
            // fprintf(outfile, "Impossible\n");
            printf("Impossible\n");
        }
        else{
            // fprintf(outfile, "%d\n" , num_edge);            
            printf("%d\n", num_edge);
        }
    }


    free(start_word);
    free(dest_word);
    free_graph(&graph , n);
    free(graph);

    free(word);
    // fclose(file);  




return 0;


}