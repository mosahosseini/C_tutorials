#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * arry ; 
    int size ; 
    int capacity ; 
} Stack;

Stack* init_stack( int value){
    Stack* stk; 
    stk->arry = (int*)malloc(sizeof(int)*2);
    if (stk == NULL) {
        printf("Error initiating stack!");
    }
    stk->arry[0] = value;
    stk ->capacity = 2;
    stk -> size = 1;
    return stk;
}


void push( Stack * stk , int value){

    if (stk -> capacity == stk -> size){
        int new_capacity = 2* stk -> capacity;
        int* new_arr = (int *) realloc(stk -> arry , sizeof(int)*new_capacity);
        if (new_arr == NULL){
            printf("The reallocatin of stack failed!");
            return ;
        }
        stk -> arry = new_arr ; 
        stk -> capacity = new_capacity;


    }
 
    stk -> arry[stk -> size] = value ;
    stk -> size ++; 
}


int pop(Stack* stk ){
    if (stk ->size == 0){
        return -1;
    }
    int last_ind = stk -> arry[stk->size -1 ];
    stk -> size --;

    return last_ind;
}


void free_stack(Stack * stk){
    free(stk -> arry);

}


void print_stack(Stack * stk){
    printf("[");
    for(int i =0 ; i < stk-> size ; i++ ) {
        printf(" %d " , stk->arry[i]);
    }
    printf("]");

}
int main(){
    Stack * s = init_stack(4);
    push(s , 3);
    push(s , 2);
    push(s , 1);
    push(s , 0);
    printf("initial stack: ");
    print_stack(s);
    int stop_iter = s->size;
    for(int i = 0 ; i< stop_iter+1 ; i++){  
        printf("\n");
        printf("poped element: %d\n" , pop(s) );
        printf("stack after poping : ");
        print_stack(s);
     
    }
    free_stack(s);
    free(s);
    

}