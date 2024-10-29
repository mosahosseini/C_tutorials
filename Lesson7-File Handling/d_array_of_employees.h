#include <stdio.h>
#include <stdlib.h>
typedef struct  {
    int employee_id ; 
    char first_name [50];
    char last_name [50];
//    char date_of_birth [20];
//    char email [50];
//    char phone_number [20];
} employee;

typedef struct {
    employee * array ;
    int size ; 
    int capacity; 
    int initialized ; 

}dynamic_array;





void init_dyn_array(dynamic_array *dyn_arr , int capacity){
    dyn_arr -> array = (employee*) malloc(capacity* sizeof(employee));
    if (dyn_arr -> array == NULL){
        printf("\nMemory allocation failed\n");
        return; 
    }
    dyn_arr -> size = 0;
    dyn_arr -> capacity = capacity;
    dyn_arr -> initialized = 1;
    printf("\narray initiated...\n");

}


void append(dynamic_array *dyn_arr , employee *emp ){
    
    if (dyn_arr->size == dyn_arr-> capacity){
        dyn_arr-> array = (employee*) realloc(dyn_arr->array , dyn_arr->size * sizeof(employee));
        dyn_arr -> capacity  *=2;
        if (dyn_arr->array == NULL) {
        printf("Memory allocation failed\n");
        return;
        }

    }

    int last_pos = dyn_arr-> size;
    dyn_arr->array[last_pos] = *emp;
    dyn_arr-> size ++;
    
}

employee get(dynamic_array *dyn_arr ,int emp_id ){
    
    for (int i = 0 ; i<dyn_arr-> size ; i++){
        if (dyn_arr->array[i].employee_id == emp_id){
            return dyn_arr->array[i];
        }
    }
    
    printf("Employee with the employee id : %d does not exist in the database." ,emp_id  );
    exit(EXIT_FAILURE);
}


employee remove_element(dynamic_array *dyn_arr , int emp_id){
    employee emp;  
    for (int i = 0 ; i<dyn_arr->size ; i++){
        if (dyn_arr->array[i].employee_id== emp_id){   
            emp= dyn_arr->array[i];
            for (int j = i ; j<dyn_arr->size-1 ; j++){
                dyn_arr->array[j] = dyn_arr->array[j+1];
            }
            dyn_arr->size--;
            return emp;
        }
    }
    perror("Employee not found in the database!");
    return emp;
}

void free_array(dynamic_array *dyn_arr){
    free(dyn_arr);
    if (dyn_arr == NULL){
        printf("Successfully freed!");
    }
}

void print_array(dynamic_array *dyn_arr){
    for (int i = 0 ; i< dyn_arr-> size ; i++){
        employee emp = dyn_arr->array[i];
        printf("Employee ID: %d , First Name: %s , Last Name: %s\n" , emp.employee_id ,emp.first_name , emp.last_name);
    }

}



