#include <stdio.h>
#include <stdlib.h>

// void print_matrix(int** matrix , int n ){
//     for (int i = 0 ; i <2*n ; i++){
//         printf("[");
//         for (int j = 0; j<n+1 ; j++){
//             printf(" %d " , matrix[i][j] ); 
//         }
//         printf("]");

//         printf("\n");
//     }
// }


// void free_mat(int ** matrix , int rows){
//     for (int i = 0; i <rows ; i++){
//         free(matrix[i]);
//     }
// }


int main(){

    // int n; //Number of pairs
    // FILE* file = fopen("data/sample/1.txt", "r") ;
    // if(file == NULL){
    //     perror("File opening failed");
    //     return 1 ; 
    // }

    // fscanf(file,"%d" , &n);
    int n = 2; 
    printf("the value of n is: %d" , n);
    // int rows = 2*n;
    // int cols = n+1; 
    // int** matrix = (int **) malloc(sizeof(int*)*rows); 
    // for (int i = 0 ; i<2*n ; i++){
    //     matrix[i] = (int*) malloc(sizeof(int)*cols);
    // }

    // int test ;    
    // for (int i = 0 ; i <2*n ; i++){
    //     for (int j = 0; j<n+1 ; j++){
    // //        fscanf(file ,"%d" ,  &test ); 
    //         matrix[i][j] = i+j;
    //         printf("\n%d" , matrix[i][j]);
    //     }
    // }
    // printf("\n this is a test ");
    // printf("%d" , matrix[0][0]);
    // printf("%d" , matrix[1][1]);
    // free_mat(matrix ,rows);
    //print_matrix(matrix ,n);



}