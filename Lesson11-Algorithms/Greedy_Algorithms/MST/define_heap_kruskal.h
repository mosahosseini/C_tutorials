#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// Sample struct stored in the heap
typedef struct {
    double weight;
    int source;
    int dest;
    size_t pos;  // Required for position tracking   
} item_t;

// Comparison function: Min-heap by key
int compare_items(const void *a, const void *b) {
    const item_t *ia = (const item_t *)a;
    const item_t *ib = (const item_t *)b;
    return (ia->weight > ib->weight) - (ia->weight < ib->weight);
}

// Returns pointer to position field
size_t *get_position(void *x) {
    return &((item_t *)x)->pos;
}



