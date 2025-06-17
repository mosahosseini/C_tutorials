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

}



int prims_algorithm( list_t ** graph , heap_t * h , item_t* items , size_t n ){
    int sum = 0 ; // this variable will keep track of the lowest weights.

    item_t * current = (item_t *) heap_min(h); // retrieve the node with minimum cost. (because we sett all other nodes except the start node to infinity, this will be our start node.)
    
    while (current != NULL){
        current->visited = 1; // We change the node to visited. 
        sum += current -> cost; // include the edge.
        int curr_ind = current -> ind ; // the index of current node in the graph.
        edge * temp = (edge *) (graph[curr_ind] -> head); //we retrieve a head of the current index.

        while (temp != NULL){  //traverse through all nodes. 

            int dest_ind = temp ->dest ; // get the destination nodes index.
            /*
                If the destination node is not visited and the weight of current node is lower that the cost of destination node.curr_ind
                set the cost to the weight of the current. 
                change position in the heap. 
            */
            if (!items[dest_ind].visited  && temp->weight < items[dest_ind].cost) {
            items[dest_ind].cost = temp->weight;
            heap_change_position(h, &items[dest_ind]);
            }

            //get the next node in the linked list. 
            temp =  get_next(temp);
            
        }
        // now we retrieve the node with min cost.
        current = (item_t *) heap_min(h);


    }

    // returning the sum of lowest weights.
    return sum;
}



int main(){
    int MAX_LENGTH = 256;  //buffer size
    int n;                 // variable n number of nodes
    int m;                 // variable m number of node for which we calculated the weights. 

    char * buffer = (char*)malloc(MAX_LENGTH); // allocate memory for buffer.
    
    
    // FILE * file = fopen("input.txt" , "r"); uncomment this if you want to run an specific file.
    if(fgets(buffer, MAX_LENGTH , stdin ) != NULL){   // change the stdin to file if you run it for specific file.
        sscanf(buffer , "%d %d", &n , &m); // sscan for setting values for n and m. 
    }
    else{
        printf("No input provided!");
        free(buffer);
        return -1;
    }

    /*
    graph representation: For graph we use a adjecency list representation.
    the graph is an array which contains pointers to linked list. 
    */
    // allocating memory for the graph. The heap is using indecies 1-n so we need to allocate n+1. 
    list_t ** graph = (list_t **)malloc(sizeof(list_t*) * (n+1));

    if (graph ==NULL){
            fprintf(stderr, "\nError: Graph initiation failed! \n");
            exit(EXIT_FAILURE);
        
    }

    // first element of the array is not used therefore we set it no NULL
    graph[0] = NULL;
    for(int i = 1 ; i <=n ; i++ ){
        graph[i] = new_list(compare , get_next, set_next ); // We initiate each graph element.
    }
    
    int ind, dest;
    double  weight;
    for (int j = 0 ; j < m ; j++ ){
        if(fgets(buffer , MAX_LENGTH , stdin) != NULL){
            sscanf(buffer , "%d %d %lf" ,&ind , &dest , &weight);
            edge * node = malloc(sizeof(edge)); // allocating memory for an ede structure.
            // set the dest weight parameters of this node. 
            node -> dest = dest ; 
            node -> weight = weight;
            list_insert_front(graph[ind] , node ); 
            // because the graph is undirected , we need to add add the edge to the destination node too. 
            // so there is an edge from ind  to dest and there is another edge with the same weight from dest to ind. 
            edge * node2 = malloc(sizeof(edge));
            node2 -> dest = ind;
            node2 -> weight = weight ; 
            list_insert_front(graph[dest] , node2); 
        }
    }

    //allocate memory for the heap array.
    item_t * items = malloc(sizeof(item_t)*(n+1));
    heap_t *h = new_heap(n, compare_items, get_position); // we initiated a new heap. 
    create_heap(h , items, n , 1 );  // put the elements in te heap. 
    int  c = prims_algorithm(graph , h , items , n); 

    printf("%d\n" , c );


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
    // fclose(file);   //uncomment this if you use specific files. 
    
    return 0;
}