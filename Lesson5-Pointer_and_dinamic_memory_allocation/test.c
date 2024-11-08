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

typedef struct {
    char * name ; 
    int  miles ; 
    int  year ; 
}car; 



#include <stdio.h>
#include <stdlib.h>

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
