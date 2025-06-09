#include "generic_llist.h"
#include <stdio.h>
#include <string.h>

typedef struct l_node {
    int dest ;
    int weight;  
    struct l_node * next ; 

}l_node; 

void* get_next(void * node){
    return ((l_node*)node) ->next;
}

void set_next(void *node_1 , void* node_2 ){
    ((l_node*)node_1)->next = (l_node*)node_2;
}

int compare(const void* a , const void* b){
    const l_node * x = a ; 
    const int * key = b;


    return (x->weight > *key) - (x->weight < *key);;
}


void print_node(void* n){
    l_node* node = (l_node*)n;
    printf("dest: %d  , weight:%d \n" , node ->dest ,node ->weight);
}
int main(){

    list_t* list = new_list(compare , get_next, set_next );
    for (int i = 0 ; i <5 ; ++i){
        l_node * node = malloc(sizeof(l_node));
        node -> dest = i ; 
        node -> weight = (5-i);
        list_insert_front(list , node);
    }

    int key = 3; 
    l_node * found = list_find(list , &key);
    if (found){
        printf("Found nodes dest: %d weight: %d \n" , found ->dest , found ->weight);
    }
    list_foreach(list , &print_node);
    list_remove(list , &key);
    list_foreach(list , &print_node); 
    list_free(list);   
}