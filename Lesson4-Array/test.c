#include <stdio.h>


int  binary(int* array ,int element ,int start, int end){
    int mid = (int) (end+start)/2;
    printf("start: %d , mid: %d  , end: %d  \n " , start ,mid , end);
    if (start==mid || end == mid){
        printf("element %d is in index: %d" , element , mid);
        return mid ;
    }
    else{
    if (element >= array[start] && element< array[mid]){
        return binary(array , element , start , mid);
    }
    if (element >= array[mid] && element <= array[end] ){
        return binary(array , element , mid , end);
    }

/* 

    printf("start= %d  , mid = %d  , end = %d\n", array[start] , array[mid] , array[end]);
    binary(array, start , mid);
*/
    }
}

int main(){
    int array[] = {1,2,3,6,8,9};
    int start = 0;
    int end = sizeof(array)/sizeof(array[0])-1;
    int ind = binary(array , 3,start , end);
    printf("index of 3 is : %d ", ind);
    return 0;
}