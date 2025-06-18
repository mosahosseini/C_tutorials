#ifndef LList  //this is run the first time we run the file. 
#define LList //We define LList. 

typedef struct list_t list_t; //struct defining linked list
typedef void* (*next_getter_t)(void*);  //here we define a function named next_getter_t which have a pointer of type void and return a pointer of type void.
typedef void (*next_setter_t)(void* , void*);

list_t * new_list
(
    int (*compare)(const void* , const void*), // a function pointer function called compare that have the two argument of type pointer to constant void and returns an int. 
    next_getter_t get_next , 
    next_setter_t set_next
);

// THe function prototypes. 
void list_free(list_t * list);
void list_insert_front(list_t*list , void * node);
int list_remove(list_t * list , const void * node);
void* list_find(list_t * list , const void * key);
void list_foreach(list_t* list , void (*func)(void*));
#endif  //we end ifndef. 

#include <stdlib.h>

// we define the list_t. It have a pointer of type void with name head. compare , next_getter_t and next_setter_t.
struct list_t {
    void *head; 
    int (*compare)(const void* , const void*);
    next_getter_t get_next;
    next_setter_t set_next;
};

/*
 * Function: new_list
 * ------------------
 * Allocates memory for the linked list, sets the head to NULL. ALso sets the getter and setter and compare fuction. 
 * 
 * Parameters:
 *   - compare: Pointer to the compare function that takes in two pointer of type const void. 
 *   - get_next: A pointer to a function of type next_getter_t which is defined earlier. 
 *   - set_next: A pointer to a function of type next_setter_t
 * 
 * Behavior: 
 *   - Allocated memory for list and check if it is properly allocated. 
 *   - Sets the head to NULL.
 *   - sets the get_next and set_next and compare function.
 * 
 */
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

/*
 * Function: free_list
 * ------------------
 * This function is used to free the linked list.
 * 
 * Parameters:
 *   - list: A pointer of type list_t which is a pointer to the linked list
 * 
 * Behavior: 
 *   - Initiate a variable pointer of type void named "current" that points to the head of the list.
 *   - Initiate a variable pointer of type void named "prev".
 *   - While current is not NULL, set prev = current free prev and move current to the next element. 
 *   - Free the list itself after while loop.  
 * 
 */
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


/*
 * Function: list_insert_front
 * ------------------
 * Insert an element in front of the linked list.
 * 
 * Parameters:
 *   - list: A pointer to list_t which is a pointer to the linked list
 *   - node: A pointer of type void to a node. 
 * Behavior: 
 *   - let the node -> next to point to the head.
 *   - Set the heads pointer to point to the node.  
 * 
 */
void list_insert_front(list_t*list , void * node){
    list -> set_next(node, list -> head ); 
    list -> head = node ; 
}


/*
 * Function: list_remove
 * ------------------
 * This function is used to remove a node from the node.
 * 
 * Parameters:
 *   - list: A pointer of type list_t which is a pointer to the linked list.
 *   - node: A pointer of type void that point to the node we want to remove. 
 * Behavior: 
 *   - Initiate a variable pointer of type void named "current" that points to the head of the list.
 *   - Initiate a variable pointer of type void named "prev" and set it to NULL.
 *   - While current is not NULL,  compare the node to current, if it is the node we want to remove, there is two different cases, if prev is not null this means that we are at the end or in the middle of the list so set prev -> next to current -> next. 
 *   - else (if prev = NULL , means that the node we want to remove is the head of the list) set list -> head = current -> next. 
 *   - free the current node. 
 *   - After if statement we need to go to the next node. so set prev = current . current = current -> next. 
 * 
 */
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


/*
 * Function: list_find
 * ------------------
 * This function is used to find the node with specific key. 
 * 
 * Parameters:
 *   - list: A pointer of type list_t which is a pointer to the linked list.
 *   - key: A pointer of type void that point to the node we want to find. 
 * Behavior: 
 *   - Initiate a variable pointer of type void named "current" that points to the head of the list.
 *   - While current is not NULL,  compare the node to current, if it matches, return the current node 
 *   - else (if prev = NULL , means that the node we want to remove is the head of the list) set list -> head = current -> next. 
 *   - After if statement we need to go to the next node. so set current = current -> next.
 *   - After the while loop (means that we coulden't find the node that matches the key node), return NULL. 
 * 
 */
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


/*
 * Function: list_foreach
 * ------------------
 * This function is used apply a function to the nodes.
 * 
 * Parameters:
 *   - list: A pointer of type list_t which is a pointer to the linked list.
 *   - void: A pointer to the function that takes in a void pointer and return type is void.
 * Behavior: 
 *   - Initiate a variable pointer of type void named "current" that points to the head of the list.
 *   - While current is not NULL, apply function to current.   
 *   - Go to the next node. so set. current = current -> next. 
 */
void list_foreach(list_t * list , void (*func)(void*)){
    void * current = list -> head;
    
    while(current){
        func(current);
        current = list -> get_next(current);
    }
}
