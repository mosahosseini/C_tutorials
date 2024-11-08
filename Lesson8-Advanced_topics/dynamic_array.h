#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * array;    //Pointer to the array of elements 
    int size;       // Number of elements in the array
    int capacity;   // Total capacity of the array
    int initialized ;
} DynamicArray;

void initArray(DynamicArray *arr , int capacity){
    arr -> array = (int*) malloc(capacity* sizeof(int));
    if (arr->array ==NULL){
        printf("memory allocation to dynamic array failed");
    }
    else{
    arr -> size = 0;
    arr -> capacity = capacity;
    arr -> initialized = 1;
    printf("\narray initiated...\n");
    }
}

void resizeArray(DynamicArray *arr , int new_capacity){
    arr->array= (int* )realloc(arr->array , new_capacity * sizeof(int));

    if (arr->array != NULL){
        arr -> capacity = new_capacity;
    } else {

        printf("Memory allocation failed during resize. \n");
        exit(EXIT_FAILURE);
    }
    
}


int dyn_array_get(DynamicArray *arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->array[index];
    }
    printf("Index out of bounds.\n");
}


void append(DynamicArray *arr ,int element){

    if (arr -> size == arr -> capacity){
        resizeArray(arr , 2*(arr-> capacity));

    }
    arr -> array[arr->size] = element;
    arr -> size++;
    
}

// Function to free the allocated memory
void freeArray(DynamicArray *arr) {
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}


void print_array(DynamicArray *arr){

    if (arr -> initialized  != 1){
        printf("\nThe dynamic array is not initiated!\n");
        //exit(EXIT_FAILURE);
    }
    else if ( arr -> size == 0 ){
        printf("The array is empty!\n");
    }
    else if (arr -> size == 1){
        printf("[%d]" , arr->array[0]);
    }
    else {
        for (int i = 0 ; i< arr-> size ; i++){
            if (i== 0){
                printf("[%d", arr->array[i]);
            }
            else if (i== arr -> size-1){
                printf(",%d]", arr ->array[i]);
            }
            else{
                printf(",%d" , arr -> array[i]);
            }

        }
    }

}