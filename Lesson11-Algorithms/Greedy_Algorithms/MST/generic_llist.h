#ifndef LList
#define LList

typedef struct list_t list_t; 
typedef void* (*next_getter_t)(void*);
typedef void (*next_setter_t)(void* , void*);

list_t * new_list
(
    int (*compare)(const void* , const void*), 
    next_getter_t get_next , 
    next_setter_t set_next
);

void list_free(list_t * list);
void list_insert_front(list_t*list , void * node);
int list_remove(list_t * list , const void * node);
void* list_find(list_t * list , const void * key);
void list_foreach(list_t* list , void (*func)(void*));
#endif

#include <stdlib.h>

struct list_t {
    void *head; 
    int (*compare)(const void* , const void*);
    next_getter_t get_next;
    next_setter_t set_next;
};

list_t * new_list
(
    int (*compare)(const void* , const void*), 
    next_getter_t get_next , 
    next_setter_t set_next
)
{
    list_t* list = (list_t*)malloc(sizeof(list_t));
    if (!list) return NULL; 
    list -> head = NULL; 
    list -> compare = compare ;
    list -> get_next = get_next ; 
    list -> set_next = set_next ;
    return list;
}


void list_free(list_t* list){
    void* current = list ->head ; 
    void* prev;
    while (current){
        prev = current; 
        free(prev);
        current = list ->get_next(current);

    }
    free(list);
}

void list_insert_front(list_t*list , void * node){
    list -> set_next(node, list -> head ); 
    list -> head = node ; 
}

int list_remove(list_t * list , const void * node){

    void * current = list -> head ; 
    void * prev = NULL;
    while (current){

        if (list -> compare(current , node ) == 0){
            if (prev) {
                list->set_next(prev, list -> get_next(current));
            }
            else{
                list-> head = list -> get_next(current);
            }

            free(current);
            return 1 ;

        }
        prev = current ; 
        current = list -> get_next(current);
    }

    return 0;
}

void* list_find(list_t * list , const void * key){
    void * current = list -> head; 
    while (current){
        if ( list -> compare(current, key)==0){
            return current ;
        }

        current = list ->get_next(current);
    }

    return NULL;
}

void list_foreach(list_t * list , void (*func)(void*)){
    void * current = list -> head;
    
    while(current){
        func(current);
        current = list -> get_next(current);
    }
}
