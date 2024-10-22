#include <stdio.h>

int main(){
    struct car {
        char* name  ; 
        char* model;
        int year ;
    };

    struct car car1 ; 
    car1.name = "volvo";
    car1.model = "v70";
    car1.year  = 20;

    printf("the name of the car is: %s" ,car1.model );

    return 0;


}