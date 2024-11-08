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
    // 1. Dynamic array
    
    DynamicArray arr;
    initArray(&arr , 4);
    append(&arr , 1);
    append(&arr , 2);
    append(&arr , 4);
    print_array(&arr);
    freeArray(&arr);
    


   /* 2. Matrix addition using pointer Alternative 1: 


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
    printf("a=\n");
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
    printf("\nb=\n");
    print_matrix(&mat_b);
    
    printf("\n\n");

    int** r2d = add_mat(&mat_a ,&mat_b);
    matrix matc; 
    matc.array = r2d;
    matc.col_size=3;
    matc.row_size=3;
    printf("a+b= \n");
    print_matrix(&matc);
 */

/*

    // Matrix addition using pointer altertative 2 (matrix from array)
    int row = 3;
    int col = 3;   
    int arr_a[] =   {1,2,3,
                     4,5,6,
                     7,8,9};


    modArray m_arr_a ;
    m_arr_a.arr = arr_a;
    m_arr_a.size = 9;
    matrix m_a ; 
    initialize_matrix(&m_a , row , col , &m_arr_a);
    printf("a=\n");
    print_matrix(&m_a);


    int arr_b[] =   {9,8,7,
                     6,5,4,
                     3,2,1};
    modArray m_arr_b;
    m_arr_b.arr = arr_b; // an array is already a reference to the first element 
    m_arr_b.size = 9;
    matrix m_b;
    initialize_matrix(&m_b , row,col, &m_arr_b);
    printf("\nb=\n");
    print_matrix(&m_b);

    matrix c ; 

    c.array = add_mat(&m_a , &m_b);
    c.col_size = col ;
    c.row_size = row ;

    printf("\na+b=\n");
    print_matrix(&c);
    return 0;
    */
}