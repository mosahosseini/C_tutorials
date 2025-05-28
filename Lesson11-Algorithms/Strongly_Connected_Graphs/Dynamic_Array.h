#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct dyn_array{
    L_Node * linked_list ;
    int capacity; 
    int top;     
} dyn_array;





void push_dyn_array(struct dyn_array **p_array, L_Node *root) {
    struct dyn_array *array = *p_array;
    if (array == NULL) {
        // Initialize array if it is NULL
        array = (struct dyn_array*) malloc(sizeof(struct dyn_array) * 2);
        array->capacity = 2; // Initial capacity
        array->top = 0; // Array is empty
        array[0].linked_list = root; // Add the first linked list
        *p_array = array; // Update the original pointer
        return;
    }

    // Check if we need to resize the array
    if (array->top +1  == array->capacity) {
        array->capacity *= 2;
        array = (struct dyn_array*) realloc(array, sizeof(struct dyn_array) * array->capacity);
        *p_array = array;
    }

    array[++array->top].linked_list = root; // Add the new linked list to the array
}

void free_dynamic_array(struct dyn_array **d_array) {
    if (d_array == NULL || *d_array == NULL) return;
    for (int i = 0; i <= (*d_array)->top; i++) {
        free_mem((*d_array)[i].linked_list);
    }
}


// int main() {
//     struct dyn_array *array = NULL; // Initialize array as NULL
//     L_Node *root = NULL;
    
//     // Create a linked list and add some nodes
//     add(&root, 1);
//     add(&root, 2);
//     add(&root, 3);
    
//     push_dyn_array(&array, root); // Push the linked list into the dynamic array
    
//     root = NULL;
    
//     // Create a linked list and add some nodes
//     add(&root, 4);
//     add(&root, 5);
//     add(&root, 6);
    
//     push_dyn_array(&array, root); // Push the linked list into the dynamic array

//         root = NULL;
    
//     // Create a linked list and add some nodes
//     add(&root, 7);
//     add(&root, 8);
//     add(&root, 9);
//     add(&root, 10);
//     add(&root, 11);
//     add(&root, 12);
    
//     push_dyn_array(&array, root); // Push the linked list into the dynamic array

//     for (int i = 0; i <= array->top; i++) {
//         L_Node *temp = array[i].linked_list;
//         printf("Dynamic Array Element %d: ", i);
//         while (temp != NULL) {
//             printf("%d ", temp->node_num);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
//     // Print the first element of the dynamic array
//     if (array != NULL && array->top >= 0 && array[0].linked_list != NULL) {
//         printf("First element in dynamic array: %d\n", array[0].linked_list->node_num);
//     } else {
//         printf("Dynamic array is empty.\n");
//     }
    
//     free_dynamic_array(&array);
//     free(array); // Free the dynamic array memory
//     return 0;
// }