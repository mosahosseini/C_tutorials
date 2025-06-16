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




void create_heap(heap_t *h ,item_t * items , size_t n , size_t start_node_ind )
{
/**
 * Function: create_heap
 * ---------------------
 * Initializes a heap with given items for use in algorithms like Dijkstra's and prims.
 * 
 * Parameters:
 *   - h: Pointer to a heap structure.
 *   - items: Array of item_t structures representing nodes cost. the heap will use this array.
 *   - n: Number of elements in the items array.
 *   - start_node_ind: Index of the starting node.
 * 
 * Behavior:
 *   - Sets the `cost` of the start node to 0, indicating it's the starting point.
 *   - Sets all other items' `cost` to INT_MAX (representing "infinity" or unvisited).
 *   - Initializes the `ind` field of each item with its index.
 *   - Sets `pred` of the first item to 0.
 */
    item_t *test;
    for (int i = 1 ; i<= n ; i++){
        if(i == start_node_ind ){
            items[i].cost = 0;

        }
        else{
            items[i].cost = INT_MAX;

        }
        items[i].visited = 0;
        items[i].ind = i;
    };

    // Initialize heap with array
    init_heap(h, &items[1], sizeof(item_t));
    
    // printf("Initial heap state:\n");
    // for (size_t i = 1; i <= heap_size(h); i++) {
    //     printf("  a[%zu] = %d\n", i, ((item_t *)h->a[i])->ind);
    // }

}



int prims_algorithm( list_t ** graph , heap_t * h , item_t* items , size_t n ){
    int sum = 0 ; 

    item_t * current = (item_t *) heap_min(h);
    
    while (current != NULL){
        current->visited = 1;
        sum += current -> cost;
        int curr_ind = current -> ind ; 
        edge * temp = (edge *) (graph[curr_ind] -> head);

        while (temp != NULL){

            int dest_ind = temp ->dest ; 
            
            if (!items[dest_ind].visited  && temp->weight < items[dest_ind].cost) {
            items[dest_ind].cost = temp->weight;
            heap_change_position(h, &items[dest_ind]);
            }
            // items[dest_ind].cost = temp ->weight;
            // item_t * w  = &items[dest_ind];
            // heap_change_position(h, &items[dest_ind]);
            temp =  get_next(temp);
            
        }
        current = (item_t *) heap_min(h);


    }
    return sum;
}



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

    list_t ** graph = (list_t **)malloc(sizeof(list_t*) * (n+1));
    if (graph ==NULL){
            fprintf(stderr, "\nError: Graph initiation failed! \n");
            exit(EXIT_FAILURE);
        
    }
    graph[0] = NULL;
    for(int i = 1 ; i <=n ; i++ ){
        graph[i] = new_list(compare , get_next, set_next );
    }
    
    int ind, dest;
    double  weight;
    for (int j = 0 ; j < m ; j++ ){
        if(fgets(buffer , MAX_LENGTH , file) != NULL){
            sscanf(buffer , "%d %d %lf" ,&ind , &dest , &weight);
            edge * node = malloc(sizeof(edge));
            node -> dest = dest ; 
            node -> weight = weight;
            edge * node2 = malloc(sizeof(edge));
            node2 -> dest = ind;
            node2 -> weight = weight ; 
            list_insert_front(graph[ind] , node );
            list_insert_front(graph[dest] , node2);
        }
    }

    // for (int i = 1 ; i <n ; i++){
    //     printf("source: %d  ," , i);
    //     list_foreach( graph[i], &print_node);
    // }

    item_t * items = malloc(sizeof(item_t)*(n+1));
    heap_t *h = new_heap(n, compare_items, get_position);
    create_heap(h , items, n , 1 );
    int  c = prims_algorithm(graph , h , items , n);

    printf("The sum is: %d:" , c );
    // Free the edges inside the graph
    for (int i = 1; i <= n; i++) {
        edge *temp = (edge *) graph[i]->head;
        while (temp != NULL) {
            edge *next = get_next(temp);
            free(temp);
            temp = next;
        }
    }
    for (int i = 1 ; i <=n ; i++){
        free(graph[i]);

    }
    
    free(graph);
    free(h);
    free(items);
    free(buffer);
    fclose(file);
    
    return 0;
}