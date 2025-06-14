#include <stdio.h>
#include <stdlib.h>
#include "define_heap.h"
#include "define_llist.h"
#include <limits.h>
// the edge data structure defined in define llist.h

/*
the edge data structure condains 
int dest;
float weight;
edge next;
*/




// void create_heap(heap_t *h ,item_t * items , size_t n )
// {
//     for (int i = 0 ; i <n ; i++){
//         if(i == 0 ){
//             items[i].cost = 0;
//             items[i].ind =0;
//             items[i].pred = 0;
//         }
//         else{
//             items[i].cost = INT_MAX;
//             items[i].ind =i;
//         }
//     };

    
//     // Initialize heap with array
//     init_heap(h, items, sizeof(item_t));
//     printf("Initial heap state:\n");
//     for (size_t i = 1; i <= heap_size(h); i++) {
//         printf("  a[%zu] = %d\n", i, ((item_t *)h->a[i])->ind);
//     }

// }

// int* dijkstras(heap_t *h  , item_t* items , list_t ** graph ,size_t n ){
//     item_t * current = (item_t*)heap_min(h);

//     while (current != NULL){
//         int curr_ind = current->ind;
//         edge* temp = (edge*)(graph[curr_ind]->head);
//         while (temp != NULL){
//             int dest_ind = temp ->dest; 
//             int dv = items[dest_ind].cost;
//             int du = current ->cost;
//             int wuv = temp ->weight;
//             if (du+wuv <dv){
//                 items[dest_ind].cost = du + wuv;
//                 heap_change_position(h, &items[dest_ind]);
//                 items[dest_ind].pred = current->ind;
//             }
//             temp = get_next(temp);
//         }
//         current = (item_t * ) heap_min(h);

//     }
    
// }


int main(){
    int MAX_LENGTH = 256;  
    int n; 
    int m; 
    char * buffer = (char*)malloc(MAX_LENGTH); 
    FILE * file = fopen("input.txt" , "r");
    
    if(fgets(buffer, MAX_LENGTH , file ) != NULL){
        sscanf(buffer , "%d %d", &n , &m);
    }
    else{
        printf("No input provided!");
        free(buffer);
        return -1;
    }

    list_t ** graph = (list_t **)malloc(sizeof(list_t*) * n+1);
    if (graph ==NULL){
            fprintf(stderr, "\nError: Graph initiation failed! \n");
            exit(EXIT_FAILURE);
        
    }
    for(int i = 1 ; i <n ; i++ ){
        graph[i] = new_list(compare , get_next, set_next );
    }
    
    int ind, dest ,weight;
    for (int j = 0 ; j < m ; j++ ){
        if(fgets(buffer , MAX_LENGTH , file) != NULL){
            sscanf(buffer , "%d %d %d" ,&ind , &dest , &weight);
            edge * node = malloc(sizeof(edge));
            node -> dest = dest ; 
            node -> weight = weight;
            list_insert_front(graph[ind] , node );
        }
    }

    for (int i = 1 ; i <n ; i++){
        printf("source: %d  ," , i);
        list_foreach( graph[i], &print_node);
    }
 
    
    for (int i = 0 ; i <n ; i++){
        free(graph[i]);
        graph[i] = NULL;
    }
    free(graph);

    free(buffer);
    fclose(file);
    
    return 0;
}