#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
typedef struct q_obj{
    char* question; 
    char* A; 
    char* B;
    char* C; 
    char* D;
    char* Answer; 
}Q_obj;


void load_questions(Q_obj * arr_q_obj);

void init_q_obj(Q_obj* q){
      q->question =(char*) malloc(sizeof(char)*100);
      q->A        =(char*) malloc(sizeof(char)*100);
      q->B        =(char*) malloc(sizeof(char)*100);
      q->C        =(char*) malloc(sizeof(char)*100); 
      q->D        =(char*) malloc(sizeof(char)*100);
      q->Answer   =(char*) malloc(sizeof(char)*10);
}

void init_array(Q_obj * arr , int size ){
    
    for (int i = 0 ; i < size ; i++){
        init_q_obj(&arr[i]);
    }
}

void free_q_obj(Q_obj *q){
    free(q->question);
    free(q->A);
    free(q->B);
    free(q->C);
    free(q->D);
    free(q->Answer);
}

void free_array(Q_obj * arr, int size ){
    for(int i = 0 ; i< size ; i++){
        free_q_obj(&arr[i]);
    }
    printf("\nArray successfully dealocated!\n");
    return;
}


int random_array(int * array ,int size){
    for (int i = 0; i <size ;i++ ){
        array[i] = i;
    }
    for ( int i = size-1 ; i>= 0 ; i--){
        time_t now=time(NULL);  
        srand(time(0)) ;
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;  
    }
}