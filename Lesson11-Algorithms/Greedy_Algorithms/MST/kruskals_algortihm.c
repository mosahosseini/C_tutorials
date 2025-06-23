#include "define_heap_kruskal.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int ind; //index of nodex in the array. 
    int head; // head/parent of that node 
    int num_children;  //number of children of that node.
} node;



int find(int ind, node *graph) {
    // if the head is not set or the head is pointing to itself return its index.
    if (graph[ind].head == -1 || graph[ind].head == ind)
        return ind;

    // Path compression
    graph[ind].head = find(graph[ind].head, graph); //this will sets all childrens head to the root parent. if we have 3->2->1  this will set 3->1 , 2->1 
    return graph[ind].head;
}

void unionn(int source, int dest, node *graph) {
    int rootS = find(source, graph); //finds the root of the source
    int rootD = find(dest, graph); // finds the root of the dest. 
    
    if (rootS == rootD) return; // if they have the same root , we wil do nothing. 

    if (graph[rootS].num_children < graph[rootD].num_children) {  // if number of children of the source is less that the dest.
        graph[rootS].head = rootD; //we set the the root of source as children of the root of dest.
        graph[rootD].num_children += graph[rootS].num_children + 1; //number of children of the dests root will be = 1+ (number of children of dest +number of children of source)
    } else {
        graph[rootD].head = rootS;
        graph[rootS].num_children += graph[rootD].num_children + 1;
    }
}


int kruskal(heap_t *h, node * graph){
    int sum = 0 ; //variable to keep track of the min weights.
    item_t * edge = (item_t *) heap_min(h); // remove min
    while(edge){
        int head1 = find(edge->source , graph); //find the sources head
        int head2 = find(edge -> dest , graph); //find the dests head
        if (head1 !=  head2 ){ // if the head of the source and dest is not the same.
            unionn(edge->source , edge->dest , graph); //Use union on them. 
            sum += edge->weight;  // sum the weight. 
        }
        edge = (item_t * ) heap_min(h);  // remove the next min edge.
    } 

    return sum; //return sum. 
    
}



int main(){
    int MAX_LENGTH = 256;  //buffer size
    int n;                 // variable n number of nodes
    int m;                 // variable m number of node for which we calculated the weights. 
    char * buffer = (char*)malloc(MAX_LENGTH); // allocate memory for buffer.
    

    // FILE * file = fopen("input.txt" , "r"); //uncomment this if you want to run an specific file.
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
    graph[0].ind  =  0;
    graph[0].head = -1; 
    for (int i  = 1 ; i <= n ; i++){
        graph[i].ind = i;
        graph[i].head = -1;
        graph[i].num_children = 0;
    }
    //Allocate memory for the heap array.
    item_t * items = malloc(sizeof(item_t)*(m+1));
    heap_t *h = new_heap(m, compare_items, get_position); // we initiated a new heap. 

    // write data to the datastructure.    
    int source, dest;
    double  weight;
    for (int j = 1 ; j <= m ; j++ ){
        if(fgets(buffer , MAX_LENGTH , stdin) != NULL){
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