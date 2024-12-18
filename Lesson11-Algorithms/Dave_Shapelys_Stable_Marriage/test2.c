#include <stdio.h>

int main(){
    int temp[4]= {1,2,3,4};
    int* p_temp = &temp;
    printf("size of pointer to an array is : %d " , sizeof(p_temp)/sizeof(p_temp[0]));
}