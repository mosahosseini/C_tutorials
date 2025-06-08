#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// Sample struct stored in the heap
typedef struct {
    int key;
    size_t pos;  // Required for position tracking
} item_t;

// Comparison function: Min-heap by key
int compare_items(const void *a, const void *b) {
    const item_t *ia = (const item_t *)a;
    const item_t *ib = (const item_t *)b;
    return ia->key - ib->key;
}

// Returns pointer to position field
size_t *get_position(void *x) {
    return &((item_t *)x)->pos;
}

int main() {
    // Initialize sample data
    item_t items[] = {
        { .key = 40 }, { .key = 10 }, { .key = 30 },
        { .key = 50 }, { .key = 20 }
    };
    size_t n = sizeof(items) / sizeof(items[0]);

    // Create a new heap
    heap_t *h = new_heap(n, compare_items, get_position);

    // Initialize heap with array
    init_heap(h, items, sizeof(item_t));

    printf("Initial heap state:\n");
    for (size_t i = 1; i <= heap_size(h); i++) {
        printf("  a[%zu] = %d\n", i, ((item_t *)h->a[i])->key);
    }

    // Extract all elements in order
    printf("\nExtracting elements in sorted order:\n");
    while (heap_size(h) > 0) {
        item_t *min = (item_t *)heap_min(h);
        printf("  Extracted: %d\n", min->key);
    }

    // Insert items individually
    printf("\nInserting new elements:\n");
    item_t a = { .key = 15 };
    item_t b = { .key = 5 };
    item_t c = { .key = 25 };

    heap_insert(h, &a);
    heap_insert(h, &b);
    heap_insert(h, &c);

    for (size_t i = 1; i <= heap_size(h); i++) {
        printf("  a[%zu] = %d\n", i, ((item_t *)h->a[i])->key);
    }

    // Change key of an element and update heap
    printf("\nDecreasing key of item 25 → 2 and reheapifying...\n");
    c.key = 2;
    heap_change_position(h, &c);

    printf("Heap after change:\n");
    for (size_t i = 1; i <= heap_size(h); i++) {
        printf("  a[%zu] = %d\n", i, ((item_t *)h->a[i])->key);
    }

    // Free heap
    free(h);
    return 0;
}
