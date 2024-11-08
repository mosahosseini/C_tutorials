# Topics:
- Introduction to Pointers
- Pointer Arithmetic
- Pointers and Arrays
- Dynamic Memory Allocation (`malloc`, `calloc`,`realloc`, `free`)


# Table Of Content



# 1. Introduction to Pointers
## 1.1 What are pointers ? 
What are Pointers? Pointers are variables that store the memory address of another variable.
They are a powerful feature in languages like C and C++, allowing for direct memory access and manipulation. 

## 1.2 Why it usefull?
Well the first reason is that pointer make the code memory efficient for example Instead of passing large structures or arrays, you can pass their addresses.
Another reason that makes pointers so special is that They are crucial for using dynamic memory allocation (e.g., malloc, free in C).
And lastely , Pointers are fundamental in creating complex data structures like linked lists, trees, etc.

## 1.3 Basic Syntax
So how we declare a pointer? 
### 1.3.1 Declaring a pointer
Here is how we declare a pointer: 
```c
int* ptr; // pointer to an integer .
```
### 1.3.2 Assigning an Address
Use the `&` operator to get the address of a variable.
```c
int num = 10 ; 
ptr  = &num ;  // ptr hold the address of num 
printf("%p" , ptr); // prints the memory address. "%p" is used to print memory addresses. 
```

### 1.3.3 Dereferencing a Pointer 
Use the `*` operator to access the value at the address the pointer is pointing to.

```c
printf("%d" , *ptr); // prints the value stored in memory address. 
```

**Example**
```C
#include <stdio.h>
int main(){
    int num = 10; 
    int*  ptr = &num; 

    printf("The address of num using & is : %p \n" , &num);
    printf("The value of ptr is : %p \n" , ptr); 
    printf("Dereferencing ptr give us that value of num: %d \n " ,*ptr)
}
```

### 1.3.4 Null Pointer 
A pointer that is not assigned any address. It's good practice to initialize pointers to NULL to avoid undefined behavior.
```c
int* ptr = NULL ; 
```

### 1.3.5 Pointer to Arrays
Array Name as a Pointer:

- The name of an array acts as a pointer to its first element. For example, if you have an array `arr`, the expression arr is equivalent to `&arr[0]`.
- This means when you assign `int* ptr = arr;`, you are actually assigning the address of the first element of the array to the pointer ptr.

- When you write int `*ptr = arr;`, you’re effectively saying "point to the first element of `arr`.
```c 
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30};

    // Using the array name as a pointer to the first element
    int *ptr1 = arr;         // Correct: ptr1 points to arr[0]
    printf("First element via ptr1: %d\n", *ptr1); // Outputs: 10

    // Using & with the first element
    int *ptr2 = &arr[0];     // Also correct: ptr2 points to arr[0]
    printf("First element via ptr2: %d\n", *ptr2); // Outputs: 10

    // Using & with the entire array
    int (*ptr3)[3] = &arr;   // This points to the whole array, not just an int
    printf("First element via ptr3: %d\n", (*ptr3)[0]); // Outputs: 10

    return 0;
}

```

### 1.3.6 Pointer Arithmetics
It is possible to do basic arithmetic on pointers. For example if we declare a pointer to an array. The pointer points to its first element:
```c
int arr [] = {1,52,3,4,5,6,7};
int * p_arr = arr;
printf("%d" , *p_arr); // output: 1 
printf("%d" , *p_arr+1); // output: 2 because we first dereference pointer to the first element which is 1 then add 1 
printf("%d" , *(p_arr+1)); // output: 52 because we first add one to the memory address of the first eleement then dereference it and therefore it gives the second element in array. 
```
we can also make a pointer that points to the last element in array and then traverse it backwards using pointer arithmetics. 

```c
int arr [] = {1,52,3,4,5,6,7};
int index_of_last_element = sizeof(arr)/sizeof(arr[0])-1
int * p_arr = &arr[index_of_last_element];
printf("%d" , *p_arr); // output: 7  
printf("%d" , *(p_arr-1)) // output: 6  
```
### 1.3.7 Pointer to Pointer
You can have pointers that point to other pointers.
```c
int **pptr = &ptr; // pptr is a pointer to ptr
```
## 1.4 Common Mistakes When Handling the pointer
There are some frequent mistakes associated with pointers. Make sure you avoid them when you building you own c programms. 

### 1.4.1 Dereferencing NULL Pointers
Always ensure a pointer is not NULL before dereferencing it. This is very common mistake. You can check if the pointer is reffering to NULL using an if statement. 
```c
    int num = 10; 
    int * ptr = NULL; 
    if (ptr == NULL) {
    printf("The pointer is NULL" );
    }
```

### 1.4.2 Double Pointer Usecases
Sometimes it is nessessary to use, specially in two cacese: 
1. we want to send a matrix to a function. 
2. We want to modify a data structure 

### 1.4.2.1 Pointer To Matrices
If we want to create a matrix pointer we can use: 

**Example code:**
```c
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int ** mat , int rows , int cols){
    for (int i  = 0 ; i <rows ;i++){
        if (i == 0 ){
            printf("[");
        }
        printf("[");
        for(int j = 0 ; j < cols ; j++){
            if (j == cols-1){
                printf("%d", mat[i][j]);
            }
            else{
                printf("%d,", mat[i][j]);
            }
        
        }
    
        
        if (i == rows-1 ){
            printf("]]");
        } 
        else{
            printf("],");
        }       
    }

}

int main (){
    int rows = 3; 
    int cols = 2; 
    int ** matrix = (int**) malloc(sizeof(int) * rows);
    for (int i  = 0 ; i <3 ;i++){
        matrix[i] = (int * ) malloc(sizeof(int) * cols);
    }

    for (int i  = 0 ; i <rows ;i++){
        for(int j = 0 ; j < cols ; j++){
        matrix[i][j] = i+j;
        }
    }

    print_matrix(matrix , rows , cols ); 

}
// output: [[0,1],[1,2],[2,3]]
``` 


### 1.4.2.2 Double Pointer For Modification Outside A Function. 
Sometimes you might want to modify a data structure outside a function. The problem is that if you send a pointer to an object into a function modyfying the pointer the object inside the function will not effect the object outside the function.This is because every time you send a pointer in a function it will create a copy of it and modfying the copy will not effect the object outside the function. Simply if we modify an objects pointer inside a function the changes will not reflect outside the function. 

```c
// Function to modify a pointer
void modifyPointer(int *ptr) {
    ptr = (int *)malloc(sizeof(int));  // Allocates new memory, modifies the local copy of ptr
    *ptr = 42;                         // Sets the new memory to 42
    printf("Inside modifyPointer: %p, value = %d\n", (void *)ptr, *ptr);
}

int main() {
    int *originalPtr = NULL;

    modifyPointer(originalPtr);  // Pass the pointer to the function
    // Check if the original pointer was modified
    if (originalPtr == NULL) {
        printf("originalPtr is still NULL after modifyPointer call\n");
    } else {
        printf("originalPtr points to %d\n", *originalPtr);
    }

    return 0;
}
```
One solution is to use double pointer: 
```c
#include <stdio.h>
#include <stdlib.h>

// Function to modify a pointer
void modifyPointer(int **ptr) {
    *ptr = (int *)malloc(sizeof(int));  // Allocates new memory, modifies the actual pointer in main
    if (*ptr != NULL) {
        **ptr = 42;                     // Sets the new memory to 42
        printf("Inside modifyPointer: %p, value = %d\n", (void *)*ptr, **ptr);
    }
}

int main() {
    int *originalPtr = NULL;

    modifyPointer(&originalPtr);  // Pass the address of originalPtr
    // Check if the original pointer was modified
    if (originalPtr == NULL) {
        printf("originalPtr is still NULL after modifyPointer call\n");
    } else {
        printf("originalPtr points to %d\n", *original) }
        return 0 ; }

```


### 1.4.2 Memory Leaks
Forgetting to free dynamically allocated memory can lead to memory leaks. More about memory allocation later.

### 1.4.3 Dangling Pointers
A dangling pointer is a pointer that no longer points to a valid memory location. This situation often occurs when a pointer references memory that has been freed or deleted. Accessing a dangling pointer can lead to undefined behavior, crashes, or data corruption.Pointers that point to memory that has been freed can cause errors. Here are some  way to prevent dangling pointers. 

1. **Sett pointers to NULL after freeing memory**
```c
int *ptr = malloc(sizeof(int));
free(ptr);    // Free the memory
ptr = NULL;   // Set the pointer to NULL
```

2. **Check for NULL Before Dereferencing**
Always check if a pointer is NULL before using it. This prevents dereferencing a dangling pointer.

```c
if (ptr != NULL) {
    // Safe to dereference ptr
}
``` 

# 2. Dynamic Memory Allocation (`malloc`, `calloc`,`realloc`, `free`)
Dynamic memory allocation allows you to allocate memory at runtime using functions from the C Standard Library.
This is useful when you don't know the size of your data beforehand or when you want to allocate memory for data
 structures that can grow or shrink.

1. `malloc()` - Allocates uninitialized memory.
2. `calloc()` - Allocates zero-initialized memory.
3. `realloc()` - Resizes previously allocated memory.
4. `free()` - Deallocates previously allocated memory.


## 2.1 Basic Syntax

1. `void* malloc(size_t size);`
2. `void* calloc(size_t num, size_t size);` 
3. `void* realloc(void* ptr, size_t new_size);` 
4. `void free(void* ptr);` 

Examples:

**Step 1: Using `malloc()`**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if allocation fails
    }

    // Input values
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display values
    printf("You entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);
    return 0;
}
```

**Step 2: Using `calloc`**
In contrary to malloc , calloc takes two arguments, `(int*) calloc(int num_items, sizeof_item)`

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
   int n = 5;
   int *array;
   
   // use calloc function to allocate the memory
   array = (int*)calloc(n, sizeof(int));
   
   if (array == NULL) {
      fprintf(stderr, "Memory allocation failed!\n");
      return 1;
   }
   
   //Display the array value
   printf("Array elements after calloc: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
   
   //free the allocated memory
   free(array);
   return 0;
}
```

**Step 3: Using `realloc`**
Sometimes we need to change the size of previousely allocated memory. Lets say we have an array that number of students in a classrum. The class have 30 student and we initiate an array that contains the name of all students. After a while a new student arrives but our array doesnt have anough memory allocated for the last student. 

1. Create a new array and allocated memory for 31 elements. 
2. Copy each element form the old array to the new array. 
3. At the last position in array add the new student. 
4. Free memory that was allocated for the old array.

But doing this for each new student  is not efficient, a better way is to use `realloc`. 

1. Use the `realloc` to allocate additional memory to the original array. 
2. In the 31 th position add a the new element. 

```c
    int size = 5;
    int *arr ;
    arr = (int*)malloc(size*sizeof(int));

    for (int i = 0 ; i< size ; i++){
        arr[i] = i
    }

    int new_size = 9;
    // reallocation 
    arr = realloc(arr , new_size*sizeof(int) );

    for (int i = size ; i < new_size ; i++ ){
        arr[i] = i
    }
    
    
    for (int i = 0 ; i < new_size ; i++ ){
        if (i==0){
        printf("[%d," , arr[i])            
        }
        else if(i== new_size-1){
         printf("%d]" , arr[i])           
        }
        else{
        printf("%d" , arr[i])
        }

    }
```


**Step 4: Using `free`**

It is very important to use `free` after you are done with the data structure. Otherwise there is a risk for memory leak. 