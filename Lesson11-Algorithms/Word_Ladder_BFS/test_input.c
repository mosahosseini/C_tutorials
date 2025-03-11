#include <stdio.h>
#include <stdlib.h>
#define WORD_LENGTH 5


typedef struct g_node{
    int node_num;
    char  value [5]; 
}G_node;





// FILE *file = fopen("data.txt", "r");
// if (file == NULL) {
//     perror("File opening failed");
//     return 1;
// }
// char name[50];
// int age;
// float gpa;
// fscanf(file, "Name: %s, Age: %d, GPA: %f", name, &age, &gpa);
// printf("Name: %s, Age: %d, GPA: %.2f\n", name, age, gpa);
// fclose(file);

int main(){

    FILE *file;
    file = fopen("1.txt", "r"); // Opens file in read mode

    if (file == NULL) {
    perror("File opening failed");
    return 1;
    }
    
    int n ; 
    int q ; 
    char word[5];

    fscanf(file , "%d %d" , &n , &q);

    //printf("n = %d , q = %d " , n , q);
    G_node  graph [n];

    for (int i = 0 ; i < n ; i++) {
        graph[i].node_num = i ; 
        fscanf(file,"%s" , word);
        graph[i].value = word; 
    }

    

    for (int i = 0 ; i < n ; i++) {
        printf("\nNode number:    %d    value: %s" , graph[i].node_num , graph[i].value );
    }




return 0;


}