#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct g_node{
    int node_num;
    char * values; 
    Node neighbours; 
}G_node;



void add_neighbour(Node * start , int node_num , char* val){
    if (start == NULL){
        start =  init_node(val, node_num);
    }
    else {
        add(start , node_num , val);
    }

}





int main(){



}