#include <stdio.h>

int main(){
typedef struct person {
    char * name ; 
    char * address ; 
} person;

person person1; 
person1.name = "Alan Turing";
person1.address = "West minister abby 2C";

printf("Name : %s\n" , person1.name);
printf("Address: %s" , person1.address);
}