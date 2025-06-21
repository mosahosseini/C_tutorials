#include "define_heap_kruskal.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int head; 
} node;



int kruskal(heap_t *h, node * graph){
    item_t * edge = (item_t *) heap_min(h);
    graph[edge->source].head = edge->source;
    graph[edge->dest].head = edge-> source;
    


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


    node * graph = (node*) malloc(sizeof(node)*(n+1));
    // graph[0] is not used or can be initialized as needed, but do not assign NULL to a struct
    graph[0].head = -1; 
    for (int i  = 1 ; i < n ; i++){
        graph[i].head = -1;
    }
    //allocate memory for the heap array.
    item_t * items = malloc(sizeof(item_t)*(m+1));
    heap_t *h = new_heap(m, compare_items, get_position); // we initiated a new heap. 

        
    int ind, dest;
    double  weight;
    for (int j = 1 ; j <= m ; j++ ){
        if(fgets(buffer , MAX_LENGTH , stdin) != NULL){
            sscanf(buffer , "%d %d %lf" ,&ind , &dest , &weight);
            items[j].source = j;
            items[j].dest = dest; 
            items[j].weight = weight;
        }
    }

    init_heap(h , &items[1] , sizeof(item_t));
    int  c = kruskal(graph , h , items , graph); 

    printf("%d\n" , c );

    free(graph);
    free(h);
    free(items);
    free(buffer);
    // fclose(file);   //uncomment this if you use specific files. 
    
    return 0;
}