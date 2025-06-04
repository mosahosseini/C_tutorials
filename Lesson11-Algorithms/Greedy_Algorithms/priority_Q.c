#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct heap{
    int * arr ; 
    int last_pos;
    int capacity; 
}Heap;


void swap(Heap **h , int pos_k , int pos_j){
    int k = (*h)->arr[pos_k];
    (*h)->arr[pos_k]=(*h)-> arr[pos_j];
    (*h)->arr[pos_j] = k;
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

void down(Heap **h ,int pos_k){
    int pos_j;
    int s = (*h) ->last_pos;
    if (2*pos_k >s){
        return ;
    }
    else if (2*pos_k == s){
        pos_j = 2*pos_k;
    }
    else if (compare((*h) ->arr , 2*pos_k , (2*pos_k)+1) < 0){
        pos_j = 2*pos_k;
    }
    else {
        pos_j = (2*pos_k)+1;
    }
    if (compare((*h) -> arr , pos_k , pos_j)>0){
        swap(h,pos_k , pos_j);
        down(h, pos_j);
    }

}

void up(Heap ** h , int pos_k){
    int pos_j;
    if (pos_k >1){
        pos_j = pos_k/2;
        if (compare((*h) -> arr , pos_k , pos_j) > 0){
            swap(h , pos_k , pos_j);
            up(h , pos_j);
        }
    }
}



void insert(Heap ** h , int val  ){
    if ((*h) -> capacity -1 == (*h) -> last_pos){
      int * new_arr = (int *) realloc((*h) -> arr , sizeof(int)*2* (*h) ->capacity);
      if (new_arr ==NULL){
        printf("Reallocation failed!!! Fail is in insert.");
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
        int pos_k = (*h)->last_pos;
        up(h, pos_k );
    }

}

int remove_min(Heap **h){
    int min_val = (*h) ->arr[1];
    down(h,1);
    return min_val;
}


void heapfy(Heap **h){
    int n = (*h) ->last_pos;
    for (int k = n/2 ; k>=1 ; k--){
        down(h, k);
    }
}

int main()
{
    int MAX_ARRAY_LENGTH = 256;
    int n;
    char *buffer = (char *)malloc(MAX_ARRAY_LENGTH);
    FILE * file = fopen("intput.txt","r");
    if (fgets(buffer, MAX_ARRAY_LENGTH, file) != NULL)
    {
        n = atoi(buffer);
    }
    else
    {
        printf("No input provided.\n");
        free(buffer);

        return -1;
    }

    Heap * h = (Heap *)malloc(sizeof(Heap));
    if (h==NULL){
        fprintf(stderr,"Failed to initiate heap!!\n");

    }
    h->arr = (int*)malloc(sizeof(int)*n+1);
    if (h->arr == NULL){
        fprintf(stderr , "Failed to initiate the array!!\n");
    }
    h->capacity= n;
    h ->last_pos = 0;
    h ->arr[0]=-1;

    if (fgets(buffer, MAX_ARRAY_LENGTH, file) != NULL)
    {   
        int i = 1;
        char *tok = strtok(buffer, " \n\t");

        
        while (tok != NULL )
        {   
            int val = atol(tok);
            h ->arr[i] = val;
            h -> last_pos++;
            int k = h ->arr[ h -> last_pos] ;
            tok = strtok(NULL, " \n\t");
            i++;
        }

    }
    else
    {
        printf("No input provided.\n");
        // Free any already allocated linked lists
        free(buffer);
        return -1;
    }
    heapfy(&h);
    int val= -1;
    for (int i = 1 ; i < n+2 ; i++){
        val = h->arr[i];
    }

    free(h->arr);
    free(h);
    free(buffer);
  
}
