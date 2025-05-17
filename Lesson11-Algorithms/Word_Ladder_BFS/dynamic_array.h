#include <stdlib.h>
#include <stdio.h>

typedef struct dynamic_array{
    int size ; 
    int capacity; 
    int * array;
} Dynamic_Array;

// void init_dyn_arr(Dynamic_Array **  arr  , int value){
//     Dynamic_Array * dyn_arr = *arr;
//     dyn_arr -> size = 1; 
//     dyn_arr->capacity = 2; 
//     dyn_arr->array = malloc(dyn_arr -> capacity * sizeof(int));
//     if (dyn_arr == NULL){
//         printf("Error occured while initiating the dynamic array look at \"init_dyn_arr\" function");
//         exit(0);
//     }
//     dyn_arr -> array[0] = value;
// }


void add_to_dyn_arr(Dynamic_Array ** dyn_arr , int value){
    Dynamic_Array * arr = *dyn_arr;
    int new_capacity = arr -> capacity == 0 ? 2 : 2* arr->capacity;
    if (arr ->size == arr -> capacity ){
        int * new_arr ; 
        if (arr -> capacity > 0  ){
            
            new_arr = (int*)  realloc(arr -> array , sizeof(int) * new_capacity);
            if (new_arr == NULL){
            printf("Error when reallocating the dynamic array.");

            }
        }
        else{

            new_arr = (int*) malloc(sizeof( int) * new_capacity);
            if (new_arr == NULL){
                printf("Error occured while initiating the dynamic array");
            }
            

        }
        arr -> array = new_arr;
        arr -> capacity = new_capacity;
    }

    arr -> array[arr -> size++] = value;

}





// int main(){

//     Dynamic_Array * neighbours = init_dyn_arr(1);
//     add_to_dyn_arr(&neighbours , 2);
//     add_to_dyn_arr(&neighbours , 5);
//     add_to_dyn_arr(&neighbours , 7);
//     add_to_dyn_arr(&neighbours , 8); 
//     add_to_dyn_arr(&neighbours , 10);     

//     for (int i = 0 ; i <neighbours -> capacity ; i++){
//     printf("Index: %d   Capacity: %d    Size: %d\n" , neighbours->array[i] , neighbours -> capacity , neighbours ->size );

//     }
    
    
//     free(neighbours);

// }