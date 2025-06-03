#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int * arr ; 
    int last_pos;
    int capacity; 
}Heap;


void swap(Heap **h , int pos_k , int pos_j){

}

void insert(Heap ** h , int val  ){
    if ((*h) -> capacity -1 == (*h) -> last_pos){
      int * new_arr = (int *) realloc((*h) -> arr , sizeof(int)*2* (*h) ->capacity);
      if (new_arr ==NULL){
        prinf("Reallocation failed!!! Fail is in insert.");
        exit;
      }
      
      (*h) -> arr = new_arr; 
    }

    if ((*h) -> last_pos == 0){
        (*h) -> arr[1] = val;
        (*h)->last_pos++; 
    }
    else{
        (*h) -> arr[++(*h)->last_pos] = val;

    }

}


int compare(int * arr , int x , int y){
    if (arr[x]<arr[y] ){
        return -1;
    }

    else if (arr[x]>arr[y]){
        return 1;
    }
    else{
        return 0;
    }

}



int main(){
    int n = 5;
    

    return 0;
}