#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include "matrix_operations.h"
// Exercises:
/*
- Implement dynamic arrays
- Matrix addition using pointers
- Use `malloc` to allocate memory for an array
*/





int main(){
    /*
    DynamicArray arr;
    initArray(&arr , 4);
    append(&arr , 1);
    append(&arr , 2);
    append(&arr , 4);
    print_array(&arr);
    freeArray(&arr);
    */

   int m [3][3] = {{1,1,1},{2,2,2},{3,3,3}};
    int row = sizeof(m)/sizeof(m[0]);
    int col = sizeof(m[0])/sizeof(m[0][0]);;
    int ** arr2d ; 
    arr2d = (int**) malloc(row * sizeof(int*));
    for (int i =0 ; i < row ; i++){
           arr2d[i] = (int*)malloc(col*sizeof(int)); 
           arr2d[i] = &(m[i][0]);
    }
    
    matrix mat_a ; 
    mat_a.array = arr2d;
    mat_a.col_size = col;
    mat_a.row_size = row;
    print_matrix(&mat_a);


//////////////////////////matrix b 
   int m_b [3][3] = {{3,3,3},{2,2,2},{1,1,1}};
    int row_b = sizeof(m_b)/sizeof(m_b[0]);
    int col_b = sizeof(m_b[0])/sizeof(m_b[0][0]);;
    int ** arr2d_b ; 
    arr2d_b = (int**) malloc(row_b * sizeof(int*));
    for (int i =0 ; i < row_b ; i++){
           arr2d_b[i] = (int*)malloc(col_b*sizeof(int)); 
           arr2d_b[i] = &(m_b[i][0]);
    }

    matrix mat_b ; 
    mat_b.array = arr2d_b;
    mat_b.col_size = col_b;
    mat_b.row_size = row_b;
    print_matrix(&mat_b);
    
    printf("\n\n");

    int** r2d = add_mat(&mat_a ,&mat_b);
    matrix matc; 
    matc.array = r2d;
    matc.col_size=3;
    matc.row_size=3;

    print_matrix(&matc);
/*
    modArray md_arr;
    md_arr.arr = vec;
    md_arr.size = sizeof(vec)/sizeof(int);    

    int col = 4;
    int row = 3;
    
    initialize_matrix(&mat, row, col , &md_arr);
    print_matrix(&mat , row, col);

    printf("|");
    for (int i = 0 ; i< sizeof(arr)/sizeof(int) ; i += col){
        for (int j = 0 ; j<col ; j++){
            printf("%d " , arr[i+j]);
        }
            printf("|\n|");

    }  

*/   

   
    return 0;
}