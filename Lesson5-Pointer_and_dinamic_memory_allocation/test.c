#include <stdio.h>

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

int main(){
    int num = 10; 
    int * ptr = NULL; 
    if (ptr == NULL) {
    printf("The pointer is NULL" );
    }

}