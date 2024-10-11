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

    if (count ==0){
        printf("No such element found!\n");
        return ;
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

int* binary_search(float * array , int size , int* result_size ){
    /* 
    Binary Search is a bit special. For it to work, the input array must be sorted. given a sorted input array it can find the elements in constant time.
    
    first we implements it so that i find only index of 1. Which means we assume arrays elements are unique , then we can build upon it so that it returns an array of indecies. 

    Algorithm: 
    - 1. Find the middle of the array.  
    - 2. Initiate 3 pointers , left ,mid right : array = [1,2,3,4,5,6,7]   - left = 1 , mid = 7  , right = 7   :  searched_element = 6 
    - 3. If searched_element> left and  searched_element <= mid :  right = mid ,  mid = (int) (index(left)+ index(mid))/2  
    - 4. If searched_element> mid and  searched_element <= right :  left = mid+1 ,  mid = (int) (index(mid)+ index(right))/2  
    - 5. If left ==mid or right == mid  return index.

    */


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