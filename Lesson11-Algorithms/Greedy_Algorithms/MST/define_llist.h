#include "generic_llist.h"
#include <stdio.h>
#include <string.h>

typedef struct edge {
    int dest ;
    int weight;  
    struct edge * next ; 

}edge; 

void* get_next(void * node){
    return ((edge*)node) ->next;
}

void set_next(void *node_1 , void* node_2 ){
    ((edge*)node_1)->next = (edge*)node_2;
}

int compare(const void* a , const void* b){
    const edge * x = (const edge *)a ; 
    const int * key = (int *)b;
    return (x->weight > *key) - (x->weight < *key);;
}


void print_node(void* n){
    edge* node = (edge*)n;
    printf("dest: %d  , weight:%d \n" , node ->dest ,node ->weight);
}