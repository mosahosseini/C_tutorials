#include <stdio.h>
#include <stdlib.h>
/*
- Implement a structure to manage student records
- Create a date/time handling program
*/

typedef struct {
    char name [50]  ; 
    int  id ;
    float grade; 
}student;

typedef struct{
    student * array; 
    int size; 
    int capacity;
}dynamic_array ;


void add(dynamic_array array , student st){
    int size = array.size;
    int capacity = array.capacity;

    if (capacity == size){
        
    }

}




int main(){


   student array [3]; 




}