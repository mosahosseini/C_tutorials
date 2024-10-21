# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int ** array;
    int row_size;
    int col_size;
} matrix;


typedef struct {
        int *arr;
        int size; 
    } modArray;



void initialize_matrix(matrix*mat , int row , int col , modArray* mod_arr){
    
    mat->col_size = col;
    mat -> row_size = row;

//////////////////// creating the matrix ////////////////////    
    //1. Creating a pointer  for each row. 
    mat -> array = (int**)malloc( row*sizeof(int*));

    // 2. for each row we allocate memory for each row. 
    for (int i = 0 ; i< row ; i++){
        mat -> array[i] = (int*) malloc(col*sizeof(int));
    } 

    int r = 0 ; 

    // obs , fix this so that the size of array is accessible.
    for (int i = 0 ; i< mod_arr->size ; i+=col){
//        for (int j = 0 ; j<col ; j++){
            mat-> array[r] = &(mod_arr-> arr[i]);
//        }
        r ++;
    }  
//    free(mod_arr->arr);

}

void print_matrix( matrix *mat ){
    int row = mat-> row_size;
    int col = mat -> col_size;
    printf("|");
    for (int i = 0 ; i< row ; i++){
        for (int j = 0 ; j<col ; j++){
            if (j == col-1){
            printf("%d" , mat->array[i][j]);               
            }
            else {
            printf("%d " , mat->array[i][j]);
            }
        }
        if (i == row-1){
            printf("|\n");
        }
        else{
            printf("|\n|");
        }

    }  
    free(mat->array);
}   


int** add_mat(matrix*a , matrix *b){

    int ** arr ; 
    int r = a-> row_size;
    int c = a-> col_size; 
    arr = (int**)malloc(r*sizeof(int*));

    for (int i = 0 ; i < r ; i++){
        arr[i] = (int*)malloc(c*sizeof(int));
        for (int j = 0 ; j <c ; j++){
            arr[i][j] = (a->array[i][j])+(b->array[i][j]);

        }
    }
    return arr;

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