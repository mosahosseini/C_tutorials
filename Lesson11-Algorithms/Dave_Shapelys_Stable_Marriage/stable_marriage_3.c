#include <stdio.h>
#include <stdlib.h>

void print_matrix(int** matrix , int n ){
    printf("\n");
    for (int i = 0 ; i <2*n ; i++){
        printf("[");
        for (int j = 0; j<n+1 ; j++){
            printf(" %d " , matrix[i][j] ); 
        }
        printf("]");

        printf("\n");
    }
}


// void encode_matrix_index(int ** matrix , int rows ){
//     int * arr = (int * ) malloc(sizeof(int)*rows);
//     for (int i = 0 ; i < rows/2 ; i++){
//         if (i<)
//         matrix[i][0]
//     }
// }

void free_mat(int ** matrix , int rows){
    for (int i = 0; i <rows ; i++){
        free(matrix[i]);

    }
}


int main(){

    int n; //Number of pairs
    FILE* file = fopen("data/sample/2.in", "r") ;
    if(file == NULL){
        perror("File opening failed");
        return 1 ; 
    }

    fscanf(file,"%d" , &n);

    int rows = 2*n;
    int cols = n+1; 
    int** matrix = (int **) malloc(sizeof(int*)*rows); 
    for (int i = 0 ; i<2*n ; i++){
        matrix[i] = (int*) malloc(sizeof(int)*cols);
    }

    int test ;    
    for (int i = 0 ; i <2*n ; i++){
        for (int j = 0; j<n+1 ; j++){
            fscanf(file ,"%d" ,  &test ); 
            matrix[i][j] = test; 

        }
    }

    print_matrix(matrix ,n);

    free_mat(matrix ,rows);


}