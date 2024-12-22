#include <stdio.h>
#include <stdlib.h>


typedef struct person {
int index;
int * preferences;
int visited ; 
int wife_ind; 
int  proposed_ind; 
}man;

typedef struct MANSTACK {
    man* men_array;
    int top_ind; 
    int limit;   
}STACK;



STACK* init_stack(  int limit ){
    STACK* men_stack = (STACK*) malloc(sizeof(STACK*));
    men_stack->men_array = (man*)malloc(sizeof(man*)*limit);
    if(men_stack ->men_array == NULL){
        perror("\nMemory allocation for men stack failed!!\n");
        exit(1);
    } 
     men_stack -> limit = limit; 
     men_stack -> top_ind = -1; 
     return men_stack; 
}

int is_full(STACK* men_stk){
    return men_stk->top_ind == men_stk->limit;
}

int is_empty( STACK* men_stk){
    return men_stk->top_ind == -1 ; 
}

void push(STACK* men_stack , man* single_man){
    if (is_full(men_stack)){
        perror("------------\nThe stack is full!\n---------------\n");
        exit(1);
    }
    else{
    men_stack->men_array[++men_stack->top_ind] = *single_man;

    }
    }

man* pop(STACK * men_stack){
    if (is_empty(men_stack)){
        perror("-----------\nThe array is empty!\n-----------\n");
        exit(1);
    }
    else
    {
    return  &men_stack->men_array[men_stack->top_ind--];

    }   
    

}

// int main()
// {
//     int n = 4;
//     man * man1 = (man*) malloc(sizeof(man*)); 
//     man1->index = 1 ; 
//     int temp [4] ={1,2,3,4}; 
//     man1 -> preferences = (int*) malloc( sizeof(int)*n);
//     man1->proposed_ind = -1;
//     man1->visited =1 ;
//     man1->wife_ind = -1; 


//     man * man2 =(man*) malloc(sizeof(man*)); 
//     man2->index = 2 ; 
//     int temp2 [4] ={4,3,2,1}; 
//     man2->preferences = (int*) malloc( sizeof(int)*n) ;
//     man2->proposed_ind = -1;
//     man2->visited =1 ;
//     man2->wife_ind = -1; 

//     man * man3 =(man*) malloc(sizeof(man*)) ; 
//     man3->index = 3 ; 
//     int temp3 [4] ={2,3,4,1}; 
//     man3->preferences = (int*) malloc( sizeof(int)*n) ;
//     man3->proposed_ind = -1;
//     man3->visited =1 ;
//     man3->wife_ind = -1;  

//     for (int i = 0 ; i<n ; i++){
//         man1->preferences[i] = temp[i];
//         man2->preferences[i] = temp2[i];
//         man3->preferences[i] = temp3[i];
//     }   

//     STACK *s = init_stack(n );
//     push(s , man1); 
//     push(s , man2);
//     push(s , man3);

//     man* tmp_man = pop(s);
//     man* tmp_man2 = pop(s);
//     man* tmp_man3 = pop(s);
// //    man* tmp_man4 = pop(s);
 
//     printf("index: %d\n" , tmp_man ->index);
//     printf("preferences: [");
//     for (int i = 0 ; i <n ; i++) {
//         printf(" %d " , tmp_man ->preferences[i]);
//     }
//     printf("]");

//     return 0 ; 
// }


