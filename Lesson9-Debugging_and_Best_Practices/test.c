#include <stdio.h>
#include <stdlib.h>

void print(float* x){
    if (*x <=10){
        printf("The number is less than or equal to 10"); }
    else{
        printf("The number is grater that 10");
    }
}



int main(){
    float w = 10 ; 
    print(&w);
    

}