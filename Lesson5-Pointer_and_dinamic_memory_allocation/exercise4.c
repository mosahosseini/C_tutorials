#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
// Exercises:
/*
- Implement dynamic arrays
- Matrix addition using pointers
- Use `malloc` to allocate memory for an array
*/

int main(){
    DynamicArray arr;
    initArray(&arr , 4);
    append(&arr , 1);
    append(&arr , 2);
    append(&arr , 4);
    print_array(&arr);
    freeArray(&arr);
 
    return 0;
}