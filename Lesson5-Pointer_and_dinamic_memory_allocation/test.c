#include <stdio.h>
#include <stdlib.h>

void print_int_array(int * arr, int size){
    for (int i = 0 ; i< size ; i++){
        if (i==0){
            printf("[%d,", arr[i]);
        }
        else if (i == size-1){
            printf("%d]",arr[i]);
        }
        else{
            printf("%d,", arr[i]);
        }

    }

}

void print_char_array(char ** arr, int size){
    for (int i = 0 ; i< size ; i++){
        if (i==0){
            printf("[%s,", arr[i]);
        }
        else if (i == size-1){
            printf("%s]",arr[i]);
        }
        else{
            printf("%s,", arr[i]);
        }

    }

}


void test1(){
    int arr [] = {1,5,3,4,5,6,7};
    int index_last = (sizeof(arr)/sizeof(arr[0]) )-1;
    int * p_arr = &arr[index_last];


    printf("[");
    for (int i = 0  ; i <= index_last ; i++  ){
        if (i == index_last){
        printf("%d]", *(p_arr--));        
        }
        else{
        printf("%d,", *(p_arr--));
        }
    }

    printf("\n%d" , *(p_arr+1));
   
}

/*
int main(){
    int num = 10; 
    int * ptr = NULL; 
    if (ptr == NULL) {
    printf("The pointer is NULL" );
    }
}
*/




int main(){
    char** arr;
    int num_students ;
    printf("How many students do you have:");
    scanf("%d", &num_students);
    arr = (char**) malloc(num_students*sizeof(char*)); // first make an array of char pointers

    for (int i = 0 ; i< num_students ; i++){
        arr[i] = (char*) malloc(20 *sizeof(char)); // for each element allocate a fixt size
    }

    for (int i = 0 ; i< num_students ; i++){
        printf("Enter the name of student %d :" , i);
        scanf("%s", arr[i]);
    }

    print_char_array(arr , num_students);
    
    char yes_or_no ;
    printf("\n do you have any new students y/n:");
    scanf("%s" , yes_or_no);
    
    printf("\n%s\n",yes_or_no);


}