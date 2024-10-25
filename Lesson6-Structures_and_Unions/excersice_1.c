#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
- Implement a structure to manage student records

*/

typedef struct {
    char name [50]  ; 
    int  id ;
    float grade; 
}student;

typedef struct{
    student * array; 
    int size; 
    int capacity;
}dynamic_array ;


void init_dyn_array(dynamic_array* dyn_arr , student * arr, int size){
    dyn_arr -> size = size;
    dyn_arr ->array = (student*) malloc(2*size* sizeof(student)); 
    dyn_arr -> capacity = 2*size; 

    for (int i = 0 ; i<size ; i++){
        dyn_arr->array[i] = arr[i];
    }
    

    printf("student 1 name : %s    student 1 id : %d    student 1 grade : %f \n" , dyn_arr->array[1].name ,dyn_arr->array[1].id , dyn_arr->array[1].grade  );

}


void dyn_arr_add(dynamic_array* dyn_aray , student st){
    int size = dyn_aray ->size;
    int capacity = dyn_aray->capacity;

    if (capacity == size){
        dyn_aray ->array = (student*)realloc(dyn_aray->array ,2*size* sizeof(student));
    }
    dyn_aray->array[size] = st;
    dyn_aray -> size ++;
}

int dyn_arr_get(dynamic_array* dyn_array , student st){
    int size = dyn_array -> size ; 
    for(int i = 0 ; i < size ; i++){
        student s = dyn_array->array[i];
        if (s.id == st.id){
            return i;
        }
    }
    return -1; 
}

void print_dyn_array(dynamic_array * arr){
    int size = arr->size;
    for (int i = 0 ; i < size ; i++){
        printf("Student name: %s   student id : %d    grade : %f\n" ,
         arr->array[i].name , arr->array[i].id , arr->array[i].grade);
    }

}


void print_student(student s){
        printf("Student name: %s   student id : %d    grade : %f\n" ,
         s.name , s.id , s.grade);
}

int main(){

student s1 = {"Mosa" , 0 , 21.6};
student s2 = {"Maria" , 1 , 19.1};
student s3 = {"Asta" , 2 , 20.18};
student s4 = {"Karl" , 3 , 21.63};
student array[3] = {s1,s2,s3};
dynamic_array dyn_arr;
init_dyn_array( &dyn_arr , &array[0] , 3);
dyn_arr_add(&dyn_arr , s4);

int ind = dyn_arr_get(&dyn_arr , s3);

print_dyn_array(&dyn_arr);

}