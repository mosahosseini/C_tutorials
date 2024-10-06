#include <stdio.h>

int add(int a , int b );

int main(){
    int a = 5 , b= 40;
    printf("Sum of %d and %d is: %d", a, b, add(a,b));
}

int add(int a, int b ){
    return a+b;
}