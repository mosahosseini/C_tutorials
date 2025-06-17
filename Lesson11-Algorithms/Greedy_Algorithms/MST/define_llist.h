#include "generic_llist.h"
#include <stdio.h>
#include <string.h>


/*
This is  the struct defining the edge. An edge is defined by: 
* Index of the destination node.
* The weight between those two.
* A pointer to the next node. 
*/
typedef struct edge {
    int dest ;
    double weight;  
    struct edge * next ; 

}edge; 


/**
 * Function: get_next
 * ------------------------------
 * This function will return the pointer to the next node.
 *
 * Parameters:
 *   - node: A pointer to the current node.
 *
 * Behavior:
 *   - Calls the next on the current node.
 *
*/
void* get_next(void * node){
    return ((edge*)node) ->next;
}


/**
 * Function: set_next
 * ------------------------------
 * This function will return set the next node..
 *
 * Parameters:
 *   - node_1: A pointer to the current node.
 *   - node_2: A pointer to the node which we want to insert.
 *
*/
void set_next(void *node_1 , void* node_2 ){
    ((edge*)node_1)->next = (edge*)node_2;
}

/**
 * Function: compare
 * ------------------------------
 * This function will compare the wheights of the two nodes. 
 *
 * Parameters:
 *   - a: A pointer to the first node.
 *   - b: A pointer to the second node
 * 
 * Behavior:
 *   - Because the weight can be very large , we cant simply use a -> weight - b -> weight. We must use a logical operator. 
 *
*/
int compare(const void* a , const void* b){
    const edge * x = (const edge *)a ; 
    const int * key = (int *)b;
    return (x->weight > *key) - (x->weight < *key);;
}

/**
 * Function: print_node
 * ------------------------------
 * This function prints a node and its all nodes.
 *
 * Parameters:
 *   - node: A pointer to a node.
 *
 * Behavior:
 *   - Prints nodes destination index and its weight.
 *
*/
void print_node(void* n){
    edge* node = (edge*)n;
    printf("dest: %d  , weight:%f \n" , node ->dest ,node ->weight);
}