#include <stdio.h>
#include <stdlib.h> 


typedef struct Stack {
    int *data;      // Pointer to stack data
    int top;       // Index of the top element
    int capacity;  // Maximum number of elements in the stack
} Stack;  

void push(struct Stack **p_stack, int value) {
    Stack *stack = *p_stack;
    if (stack == NULL) {
        //initialize stack if it is NULL
        stack = (Stack*) malloc(sizeof(Stack));
        stack->capacity = 2; // Initial capacity
        stack->data = (int*) malloc(stack->capacity * sizeof(int));
        stack->top = 0; // Stack is empty
        stack->data[0] = value; // Push the first element
        *p_stack = stack; // Update the original pointer
        return;
    }
    // Check if the stack is full   
    if (stack->top == stack->capacity - 1) {
        // Stack is full, resize it
        stack->capacity *= 2;
        stack->data = (int*) realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = value;
}


int pop(Stack **p_stack) {
    Stack *stack = *p_stack;
    if (stack == NULL || stack->top == -1) {
        // Stack is empty
        return -1; // or handle underflow as needed
    }
    int value = stack->data[stack->top--];
    // Check if we can shrink the stack
    if (stack->top < stack->capacity / 4 && stack->capacity > 2) {
        stack->capacity /= 2;
        stack->data = (int*) realloc(stack->data, stack->capacity * sizeof(int));
    }
    return value;
}

int top(Stack *stack) {
    if (stack == NULL || stack->top == -1) {
        return -1; // or handle empty stack case
    }
    return stack->data[stack->top];
}

// int main() {
//     Stack *stack = NULL; // Initialize stack as NULL
//     push(&stack, 10);
//     push(&stack, 20);
//     push(&stack, 30);
    
//     printf("Top element: %d\n", top(stack)); // Should print 30
    
//     printf("Popped element: %d\n", pop(&stack)); // Should print 30
//     printf("Popped element: %d\n", pop(&stack)); // Should print 20
//     printf("Popped element: %d\n", pop(&stack)); // Should print 10
//     printf("Popped element: %d\n", pop(&stack)); // Should print -1 (empty stack)
    
//     free(stack->data); // Free allocated memory for data
//     free(stack); // Free the stack structure itself
//     return 0;
// }