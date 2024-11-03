#include <stdlib.h>
#include <stdio.h>



typedef struct {
    int * items;
    int top ;
    int max_size; 
}stack;


stack* init_stack(int size){
    stack* stk = (stack*) malloc( sizeof(stack*));
    stk->items = (int*) malloc( sizeof(int) * size);
    stk->top = -1; 
    stk->max_size = size ; 
    return stk; 
}

int is_full(stack* stk){
    return stk->top == stk->max_size-1;
}

int is_empty(stack* stk ){
    return stk->top ==-1;
}

void push(stack* stk , int value){
    if(is_full(stk)){
        printf("\n!!! Stack overflow! Cannot push %d !!!!\n", value);
    }
    else
    {   
        stk->items[++stk->top] = value; 
        printf("\nSuccessfully added %d into the stack.\n" , value);

    }

}

int pull(stack* stk ){
    if (is_empty(stk)){
        printf("!!! The stack is empty!!!" );
        return -1; 
    }
    else{
        return stk->items[stk->top--];
    
    }
} 




int peek(stack* stk , int value){
    if (is_empty(stk)){
        printf("!!! The stack is empty!!!" );
        return -1; 
    }
    else{
        for (int i = 0 ; i<=stk->top ; i++){
            if (stk-> items[i] == value){
                printf("\nThe value found!");
                return i; // index of the element in question. 
            }

        }  
    }
    printf("\nThe value was not found in the stack!!" );
    return -1; 
} 

