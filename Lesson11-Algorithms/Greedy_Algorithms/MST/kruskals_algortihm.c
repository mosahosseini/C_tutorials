#include "define_heap_kruskal.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int ind;
    int head; 
    int num_children; 
} node;



int find(
    int  ind ,node * graph
){  
        int node_ind = graph[ind].ind;
        int  head_ind = graph[ind].head;

        while (node_ind != head_ind){
            node_ind = head_ind; 
            head_ind = graph[node_ind].head;
        }

        return head_ind;
    }


void unionn(
    int source, 
    int dest , node** graph
){  
    node  s = (*graph)[source]; 
    node d = (*graph)[dest]; 
    if (s.head== -1 &&  d.head== -1){
        (*graph)[source].head = s.ind;
        (*graph)[dest].head= s.ind;
        (*graph)[source].num_children++;
    }
    else if (s.head == -1 && d.head != -1){
        (*graph)[source].head = d.head; 
        (*graph)[dest].num_children ++;
    }
    else if (s.head != -1 && d.head == -1 ){
        (*graph)[dest].head = s.head;
        (*graph)[source].num_children ++;
    }
    else{
        int nodes_head = find(s.head , graph);
        int noded_head = find(d.head , graph);
        if (graph[nodes_head]->num_children < graph[noded_head] -> num_children){
            (*graph)[source].head = noded_head;
            (*graph)[noded_head].num_children ++;
        }
        else {
            (*graph)[dest].head = nodes_head;
            (*graph)[nodes_head].num_children ++;
        }

    }


};


int kruskal(heap_t *h, node * graph){
    int sum = 0 ; 
    item_t * edge = (item_t *) heap_min(h);
    while(edge){
        int head1 = find(edge->source , graph);
        int head2 = find(edge -> dest , graph);
        if (head1 !=  head2 || (head1 == -1 && head2 == -1 )){
            unionn(edge->source , edge->dest , &graph);
            node  temps = graph[1];
            node  tempd = graph[2];
            sum += edge->weight;
        }
        edge = (item_t * ) heap_min(h);
    } 

    return sum;
    
}



int main(){
    int MAX_LENGTH = 256;  //buffer size
    int n;                 // variable n number of nodes
    int m;                 // variable m number of node for which we calculated the weights. 
    char * buffer = (char*)malloc(MAX_LENGTH); // allocate memory for buffer.
    

    FILE * file = fopen("input.txt" , "r"); //uncomment this if you want to run an specific file.
    if(fgets(buffer, MAX_LENGTH , file ) != NULL){   // change the stdin to file if you run it for specific file.
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
    graph[0].ind  =  0;
    graph[0].head = -1; 
    for (int i  = 1 ; i <= n ; i++){
        graph[i].ind = i;
        graph[i].head = -1;
    }
    //allocate memory for the heap array.
    item_t * items = malloc(sizeof(item_t)*(m+1));
    heap_t *h = new_heap(m, compare_items, get_position); // we initiated a new heap. 

        
    int source, dest;
    double  weight;
    for (int j = 1 ; j <= m ; j++ ){
        if(fgets(buffer , MAX_LENGTH , file) != NULL){
            sscanf(buffer , "%d %d %lf" ,&source , &dest , &weight);
            items[j].source = source;
            items[j].dest = dest; 
            items[j].weight = weight;
        }
    }


    
    init_heap(h , &items[1] , sizeof(item_t));
    int  c = kruskal( h , graph); 

    printf("%d\n" , c );

    free(graph);
    free(h);
    free(items);
    free(buffer);
    // fclose(file);   //uncomment this if you use specific files. 
    
    return 0;
}