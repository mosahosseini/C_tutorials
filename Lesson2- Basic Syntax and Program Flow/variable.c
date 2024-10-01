#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>



void printSizes(int argc, char** argv) {
   printf("CHAR_BIT    :   %d\n", CHAR_BIT);
   printf("CHAR_MAX    :   %d\n", CHAR_MAX);
   printf("CHAR_MIN    :   %d\n", CHAR_MIN);
   printf("INT_MAX     :   %d\n", INT_MAX);
   printf("INT_MIN     :   %d\n", INT_MIN);
   printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
   printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
   printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
   printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
   printf("SHRT_MAX    :   %d\n", SHRT_MAX);
   printf("SHRT_MIN    :   %d\n", SHRT_MIN);
   printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
   printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
   printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
   printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);

};


struct car {
 char name [50] ;
 char model[50];
 int year;
};



void string_pointers()
{
    char *ptr = "Hello World";
    int i = 0; 
    while (ptr[i] != '\0'){
        printf("Character stored at index %d is %c \n" , i , ptr[i]);
        i++;
    }

    printf("Character stored at index %d is \\0 \n" , i );   // the terminator character is not appearing in the printf therefore we print it manually. 


};


void format_specifier(){
    int age = 30;
    char firstLetter = 'M';
    printf("You are %d years old and your name starts with %c" ,   age , firstLetter);

};

void input_example(){
    int p_age;
    printf("Enter your age:");
    scanf("%d" , &p_age);
    printf("You are borned year: %d" , 2024-p_age );
};

int main()
{
    // Format specifier example
//format_specifier();

    // Input example:
//input_example();


return 0 ;
}
