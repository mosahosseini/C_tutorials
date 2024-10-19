#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include "matrix_operations.h"
// Exercises:
/*
- Implement dynamic arrays
- Matrix addition using pointers
- Use `malloc` to allocate memory for an array
*/

int main(){
    /*
    DynamicArray arr;
    initArray(&arr , 4);
    append(&arr , 1);
    append(&arr , 2);
    append(&arr , 4);
    print_array(&arr);
    freeArray(&arr);
    */

    int arr [] = {1,2,3,4,5,6,7,8,9};
    int col = 3;
    int row = 3;
    

    
    printf("|");
    for (int i = 0 ; i< sizeof(arr)/sizeof(int) ; i += col){
        for (int j = 0 ; j<col ; j++){
            printf("%d " , arr[i+j]);
        }
            printf("|\n|");

    }  


   
    return 0;
}