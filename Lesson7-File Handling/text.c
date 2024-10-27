#include <stdio.h>

int main(){
    FILE* file = fopen("data.txt", "r");

    if (file == NULL){
        perror("File opening failed");
        return 1;
    };

    char name[50];
    int age ;
    float gpa; 

    fscanf(file, "Name:%s , Age: %d, GPA: %f", name, &age, &gpa);

    printf("Name: %s , Age: %d, GPA: %.02f\n", name , age, gpa);
}
