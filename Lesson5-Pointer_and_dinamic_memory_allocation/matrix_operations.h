# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int ** array;
    int row_size;
    int col_size;
} matrix;


void initialize_matrix(matrix*mat , int row , int col , int * arr){
    mat->col_size = col;
    mat -> row_size = row;

//////////////////// creating the matrix ////////////////////    
    //1. Creating a pointer  for each row. 
    mat -> array = (int**)malloc( row*sizeof(int*));

    // 2. for each row we allocate memory for each row. 
    for (int i = 0 ; i< row ; i++){
        mat -> array[i] = (int*) malloc(col*sizeof(int));
    } 

/*

    int row = 0 ; 
    for (int i = 0 ; i< sizeof(arr)/sizeof(int) ; i+col){
        for (int j = 0 ; j<col ; j++){
            mat-> array[row , j] = arr[i+j];
        }
        row ++;
    }       
*/



}















matrix matrix_add( matrix *a , matrix*b ){
    matrix result_mat ;
    result_mat.col_size = a ->col_size;
    result_mat.row_size = a -> row_size;



    if ( a -> row_size == b -> row_size && a-> col_size == b -> col_size){
    


    for( int i = 0 ; i< a ->row_size ; i++ ){
        for(int j = 0 ; j< a ->col_size ; j++){
            result_mat.array[i][j] = a->array[i][j]+ b->array[i][j];
        }

    }

    return result_mat;

    }else{
        printf("\nThe dimension of the matrices must agree!\n");
        exit(EXIT_FAILURE);

    }

}