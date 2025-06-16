#ifndef heap_h
#define heap_h
#include <stddef.h>

typedef struct heap_t heap_t;

heap_t* new_heap( size_t , int(*) (const void* , const void*) , size_t* (*) (void*));
void init_heap(heap_t* , void* , size_t);
void free_heap(heap_t*);
void heap_insert(heap_t* , void*);
void* heap_min(heap_t*);
void heap_change_position(heap_t* , void*);
size_t heap_size(heap_t*);
#endif

#include <stdlib.h>
#include <string.h>


struct heap_t{
    int (*compare)(const void* , const void*);  // a pointer to compare function it compares the two object
    size_t * (*position)(void*);  // a pointer to position function. In returns the position of the element in the array.
    size_t i; // index of the last element. 
    size_t n; // size of the array which is used as heap.
    void* a[]; // the array that we use as the heap. 
};


/**
 * Function: new_heap
 * ------------------
 * Allocates and initializes a new heap structure with space for n elements.
 * This heap is generic and can be used to store pointers to any type of element.
 * 
 * Parameters:
 *   - n: Maximum number of elements the heap can store.
 *   - compare: Function pointer used to compare two elements (for min-heap or max-heap behavior).
 *   - position: Function pointer used to retrieve a pointer to the `pos` field of an element,
 *               allowing the heap to track and update the position of elements during operations.
 * 
 * Returns:
 *   - A pointer to a newly allocated `heap_t` structure.
 * 
 * Behavior:
 *   - Allocates enough memory for the `heap_t` structure and its backing array (`a`) that can hold
 *     `n + 1` elements (1-based indexing is used, so the 0th index is unused).
 *   - Initializes all fields to zero using `memset`.
 *   - Sets the `compare` and `position` function pointers for heap operations.
 *   - Initializes the heap size `i` to 0 (i.e., currently empty).
 * 
 * Notes:
 *   - Exits the program with an error message if memory allocation fails.
 *   - This function only allocates memory; elements are set up later using `init_heap` or `heap_insert`.
 */
heap_t* new_heap(
    size_t n,
    int     (*compare)(const void* , const void*),
    size_t * (*position)(void*))
{
    // Allocate enough memory for the heap_t structure and its dynamic array (a[])
    heap_t* heap; 
    size_t s;
    s = sizeof(heap_t)+(n+1)*sizeof(void*);
    heap =(heap_t*) malloc(s);

    if (!heap) {
    fprintf(stderr, "Heap allocation failed\n");
    exit(EXIT_FAILURE);
    }
    // Initiate all memory to zero.
    memset(heap , 0 , s);
    //set heap parameters
    heap -> n = n; //maximum capacity.
    heap -> i = 0; // current number of elements.
    heap -> compare = compare ; // comparison for ordering.
    heap -> position  = position; // position tracking function.
    return heap;
}

/**
 * Function: swap
 * ------------------
 * Swap the element in position i , j. 
 * 
 * Parameters:
 *   - h: Pointer to heap.
 *   - i: the index of the first element
 *   - j: the index of the second element.  
 * 
 * Behavior:
 *   - Created a temporary pointer variable x  
 *   - lets the x copy the address of i:th element in a
 *   - Lets the pointer to i:th element copy the j:th element address.
 *   - Pointer to j:th will copy the x.
 *   - sets the position of the variables.
 * 
*/
static void swap(heap_t * h , size_t i , size_t j){
    void*   x; 
    x = h->a[i];
    h -> a[i] = h->a[j];
    h -> a[j] = x;
    *(*h->position)(h->a[i])=i;
    *(*h->position)(h->a[j])=j;    
}

/**
 * Function: up
 * ------------------
 * Moves the element upper in the tree.
 * 
 * Parameters:
 *   - h: Pointer to heap.
 *   - k: the index of element we want to move up.
 * 
 * Behavior:
 *   - Created a temporary variable j.  
 *   - if k>1 then compare k:th element with its parent in k/2. swap the element in k with k/2. Check if the element needs to be moved upper in the tree by using up. 
 * 
*/
static void up(heap_t * h , size_t k){
    size_t j;
    if (k>1){
        j= k/2;
        if((*h -> compare)(h->a[j] , h->a[k])>0){
            swap(h , k , j);
            up(h , j);
        }
    }

}

/**
 * Function: down
 * ------------------
 * Moves the element further down in the tree.
 * 
 * Parameters:
 *   - h: Pointer to heap.
 *   - k: the index the element we want to move up. 
 * 
 * Behavior: 
 *   - If 2k is larger than the index of the last element, i then we cannot go further down in the tree. So we need to return. 
 *   - else if 2k is equal the index of the last element, i then we set then we swap element in index k and 2k and call down one more time to be sure it cannot more further down in the tree.
 *   - else if 2k dont reach the index of the last element we check if which of the elements in indecies 2k and 2k+1 is larger we move the smallest of those two to the kth position. swap and then call down to be sure it cannot more further down in the tree.  
 * 
*/
static void down(heap_t* h , size_t k ){
    size_t j;
    if(2*k > h-> i ){
        return ;
    }
    else if (2*k == h-> i){
        j=2*k;
    }
    else if ((*h -> compare)(h->a[2*k] , h-> a[2*k+1])<0){
        j= 2*k;
    }
    else{
        j= 2*k+1;
    }
    if((*h->compare)(h->a[k], h->a[j])>0){
        swap(h , k , j);
        down(h , j);
    }
}

/**
 * Function: init_heap
 * -------------------
 * Initializes the internal heap array with pointers to external elements.
 *
 * Parameters:
 *   - h: Pointer to the heap structure.
 *   - b: Pointer to the base address of an array containing `n` elements.
 *   - s: Size in bytes of each element in the array `b`.
 *
 * Behavior:
 *   - Fills the heap's internal array `a[]` with pointers to elements from the external array `b`.
 *   - Sets the position field of each element (via the `position` callback) to its index in the heap.
 *   - Performs a bottom-up heapify to enforce the heap property.
 *
 * Notes:
 *   - The array `b` must contain at least `n` valid elements of size `s`.
 *   - Assumes 1-based indexing for heap storage.
 */
void init_heap(heap_t * h , void* b , size_t s)
{
    size_t k;

    for (k = 1; k <= h->n; k++) {
        h->a[k] = (char*)b + s * (k - 1);
        *(*h->position)(h->a[k]) = k;
    }

    h->i = h->n;

    for (k = h->n / 2; k >= 1; k--) {
        down(h, k);
        if (k == 1) break; // Prevent unsigned underflow
    }
}



/**
 * Function: heap_insert
 * ---------------------
 * Inserts a new element into the heap.
 *
 * Parameters:
 *   - h: Pointer to the heap structure.
 *   - x: Pointer to the element to insert.
 *
 * Behavior:
 *   - Adds the element at the next available position in the heap.
 *   - Updates the element's position (via the `position` callback).
 *   - Restores the heap property by bubbling the element up.
 *
 * Notes:
 *   - The heap must not be full.
 */
void heap_insert(heap_t * h , void *x)
{
    h->i += 1;
    h->a[h->i] = x;
    *(*h->position)(x) = h->i;
    up(h, h->i);
}

/**
 * Function: heap_size
 * -------------------
 * Returns the current number of elements in the heap.
 *
 * Parameters:
 *   - h: Pointer to the heap structure.
 *
 * Returns:
 *   - The number of elements currently in the heap.
 */
size_t heap_size(heap_t* h)
{
    return h->i;
}


/**
 * Function: heap_min
 * ------------------
 * Extracts and returns the minimum element from the heap.
 *
 * Parameters:
 *   - h: Pointer to the heap structure.
 *
 * Returns:
 *   - Pointer to the element with the minimum value, or NULL if the heap is empty.
 *
 * Behavior:
 *   - Removes the root (minimum) element.
 *   - Moves the last element to the root.
 *   - Updates its position and restores the heap property by bubbling it down.
 *
 * Notes:
 *   - The returned element is removed from the heap but not freed.
 */
void * heap_min(heap_t*h){
    if (h->i == 0) return NULL;
    void *  x;
    x = h ->a[1];
    if (x!=NULL){
        // x = h ->a[1];
        h->a[1] = h->a[h->i];
        *(*h -> position)(h->a[1]) = 1; 
        h->a[h->i] = NULL;
        h->i -=1;
        down(h,1);
        return x;
    }
    else{
        return NULL;
    }
}



/**
 * Function: heap_change_position
 * ------------------------------
 * Adjusts the position of an element in the heap after its key value changes.
 *
 * Parameters:
 *   - h: Pointer to the heap structure.
 *   - x: Pointer to the element whose value has changed.
 *
 * Behavior:
 *   - Retrieves the current position of the element.
 *   - Performs both upward and downward bubbling to restore the heap property.
 *
 * Notes:
 *   - Typically used after modifying the priority or cost of an element already in the heap.
 */
void heap_change_position(heap_t*h , void* x){
    size_t   k; 
    k = *(*h->position)(x);
    up(h , k);
    down(h,k);
}


