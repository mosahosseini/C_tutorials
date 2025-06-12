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
    int (*compare)(const void* , const void*);
    size_t * (*position)(void*);
    size_t i;
    size_t n;
    void* a[];
};

heap_t* new_heap(
    size_t n,
    int     (*compare)(const void* , const void*),
    size_t * (*position)(void*))
{
    heap_t* heap; 
    size_t s;
    s = sizeof(heap_t)+(n+1)*sizeof(void*);
    heap =(heap_t*) malloc(s);
    memset(heap , 0 , s);
    heap -> n = n;
    heap -> i = 0;
    heap -> compare = compare ; 
    heap -> position  = position; 
    return heap;
}


static void swap(heap_t * h , size_t i , size_t j){
    void*   x; 
    x = h->a[i];
    h -> a[i] = h->a[j];
    h -> a[j] = x;
    *(*h->position)(h->a[i])=i;
    *(*h->position)(h->a[j])=j;    
}


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


void init_heap(heap_t * h , void* b , size_t s)
{
    size_t  k; 
    void*   x;
    /*
    *The array b contains elements of size s
    *Initialize the heap array with pointers
    *to each element in b. Also set their positions.
    */

    for(k = 1 ; k <= h->n ; k++){
        h->a[k] = (char*)b +s*(k-1);
        *(*h-> position)(h->a[k]) = k;
    }

/*Merge increasingly larger heaps. */

    h-> i = h -> n;
    for (k= h->n/2; k >=1 ; k--){
        down(h,k);
        if (k==1) break ; 
    }
}


void heap_insert(heap_t * h , void *x )
{
    h-> i +=1;
    h-> a[h->i] = x; 
    *(*h->position)(h->a[h->i])=h->i;
    up(h , h->i);
}


size_t heap_size(heap_t*h){
    return h->i;
}

void * heap_min(heap_t*h){
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

void heap_change_position(heap_t*h , void* x){
    size_t   k; 
    k = *(*h->position)(x);
    up(h , k);
    down(h,k);
}


