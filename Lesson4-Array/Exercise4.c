#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
- Implement linear search and binary search
- Implement bubble sort
- Reverse a string
*/



// Linear Search
// I want to implement it using pointer

int * linear_search(float *array  , float element ,int size , int *resultSize){
    int count = 0;
    for (int i = 0 ; i< size ; i++){
        if( array[i] == element){
            count ++;
        }
    }

    int* p_indexes = malloc(count*sizeof(int));
    *resultSize = count;
    count =0;
        for (int i = 0 ; i< size ; i++){
        if( array[i] == element){
//            printf("count : %d \n", count);
            p_indexes[count] = i ;
            count++;
        }
    }
    return p_indexes;
}


int main(){
    float array [] = {1 ,2,3,4,5,1,1,1,4,2,3,5,6,8,9,67,4};
    int resultSize;
    int* p_indexes = linear_search(array, 4 , sizeof(array)/sizeof(float) , &resultSize);

    printf("[");
    for (int i = 0 ; i<resultSize ; i++){
        if (i == resultSize-1){
            printf("%d" , p_indexes[i]);
        }
        else{
            printf("%d," , p_indexes[i]);
        }
    }
    printf("]");



}