#include <stdio.h>
#include <stdlib.h>
#include "d_array_of_employees.h"
/*
### Exercises:
- Count lines, words, and characters in a file
- Build a file-based employee management system
*/


// excersice 1 
int  count_words(char* data){
    int word_count = 0;
    FILE *file = fopen(data , "r");
    if (file == NULL){
        perror("File opening failed. Make sure the file exist in directory");
        return 1;
    }
    int res = 1;

    while(res != EOF){
    char str [50] ;
    res  = fscanf(file, "%s" ,str);
    if (res == EOF ){
        printf("\n!!! End of file reached !!! \n");
    }
    else {
    printf("%s\n" , str);
    word_count++;
    }
    }
    
    return word_count;
}


int count_line(char * data){
 
    FILE *file = fopen(data, "r");
    int line_count = 0;

    if (file == NULL){
        perror("Opening file failed!");
        return 1;
    }
    char buffer [100]; 

    while (fgets(buffer , 100 , file) != NULL){
        printf("%s" , buffer); 
        line_count++;           
    }
    
    return line_count;


}
// excersice 2 

void read_employee_data(char * data , dynamic_array * emp_arr){
    FILE* file = fopen(data , "r");
    if (file == NULL){
        perror("Opening file failed!");
        return ; 
    }


    int result = 1; 
    employee emp;
    while (1){
        result = fscanf(file , "First_name: %s , Last_name: %s , id: %d ", emp.first_name , emp.last_name, &emp.employee_id);


        if (result == EOF){
            return; 
        }else{
//            printf("\nFirst_name:%s, Last_name: %s, id: %d\n" , emp.first_name , emp.last_name,emp.employee_id );
            append(emp_arr , &emp); 
//            printf("emp_arr size:%d , emp_arr capacity : %d\n " ,  emp_arr-> size , emp_arr-> capacity);
        }
    }
}




int main(){
/*
 // excercise 1 a
    int word_count ; 
    char file []="data_exercise_1a.txt" ;
    word_count = count_words(file);
    printf("Number of words is %d" , word_count);

/*

// excercise 1 b uncomment this part if you want to run. 
    char file[] = "data_excercise_1b.txt";
    int line_count;
    line_count = count_line(file);
    printf("Number of lines is %d", line_count);
*/

/*
    excersice 2 file based employee managements system. 
*/

char data [50] = "data_lesson_7_excercise_2.txt";
dynamic_array emp_arr ; 
init_dyn_array(&emp_arr , 2);
read_employee_data( data , &emp_arr);
print_array(&emp_arr);

employee em = remove_element(&emp_arr , 2);
//employee em = {1, "Brah" , "Bro"};
printf("removed_employee : Emp_id: %d , first name: %s ,last name: %s" , em.employee_id , em.first_name , em.last_name);

print_array(&emp_arr);
//free_array(&emp_arr);




}

