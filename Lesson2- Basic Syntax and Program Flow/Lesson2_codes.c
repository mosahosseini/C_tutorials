#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>



void data_types_and_Sizes() {
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


void arithmetic_operators(int a , int b){
    printf("Addition of %d and %d is : %d" ,a,b, a+b);
    printf("\nSubtraction of %d and %d is : %d" ,a,b, a-b);
    printf("\n Division of %d and %d is : %.2f" ,a,b ,(float)a/b);
    printf("\n Multiplication of %d and %d is: %d" , a,b,a*b);
    printf("\n %d modulus %d is: %d" , a,b, a%b);
};

void relational_operators(int a, int b){
    printf("\n Is %d equal to %d?                 %d" , a , b , a == b );
    printf("\n Is %d not equal to %d?             %d" , a , b , a != b);
    printf("\n Is %d greater than %d?             %d" , a , b , a > b);
    printf("\n Is %d less than %d?                %d" , a , b , a < b);
    printf("\n Is %d greater than or equal to %d? %d" , a , b , a >= b);
    printf("\n Is %d less than or  equal to %d?   %d" , a , b , a >= b);
};

void logical_operator(int a , int b){
    printf("(a > 5 and b < 30): %d \n" , (a > 5 && b<30));
    printf("(a > 5 || b < 30):  %d \n" , (a > 5 || b < 30));
    printf("!(a == b):          %d\n" , !(a == b));

    
};

void if_statement(int a){
if (a > 10){
  printf("The number is larger than 10");
} 
else{
  printf("the number is smaller than or equal to 10");
}
};

void switch_case(int a){
    switch (a)
    {
    case 0:
        printf("You entered 0");
        break;
    case 1/* constant-expression */:
        /* code */
        printf("You entered 1");
        break;
    case 2:
        printf("You entered 2");
        break;
    default:
        printf("You entered another number");
        break;
    }
}

void for_loop(int reps , int method ){

    if (method == 0 ){
    for(int i=1 ; i <= reps ; i++){
        printf("i : %d \n" , i);
    }
    }else{
    for(int i=reps ; i >=1 ; i--){
        printf("i : %d \n" , i);
    }
    };
}

void while_loop(int reps){
    int safty = 0;
    while (reps>=1 || safty == 1000 ){
        printf("i: %d \n" , reps);
        reps--;
        safty ++;  
    }
    if (safty == 1000){
        printf("Safety activated: Something is wrong with the condition");
    }

}

void do_while_loop(int reps){
 
    do {
        printf("i: %d \n" , reps); 
        reps --;

    }while( reps >= 1);
}





int main()
{
    //1.3.1 Data types and their sizes
//data_types_and_Sizes();

    //2.1.1 Format specifier example
//format_specifier();

    //2.2 Input example:
//input_example();

    //3.1 Arithmetic operators
//arithmetic_operators(7,5);

    //3.2 Realational operators
//relational_operators(1 , 2);

    //3.3 logical operators
//logical_operator(10,10); 
    
    
    // 4.1.1 Conditional Statements if else: 
//if_statement(11);

    // 4.1.1 Conditional Statements switch case:
//switch_case(0);

    // 4.2.1 For loop
//for_loop(10 , 1); // prints the counters value for_loop(reps, method) , method=0 for accending , method !=0 for decending 

    // 4.2.2 While and do-while
//while_loop(10);
//do_while_loop(10);
return 0 ;
}
