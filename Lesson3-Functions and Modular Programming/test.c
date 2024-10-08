#include <stdio.h>


int main(){
    int arr = {1,3,4,5};
    char a [] ="max";
    char b [] = a[0..-1];
    int al = array_length(arr);
    printf("length of array is : %d" , al);
    return 0;
}