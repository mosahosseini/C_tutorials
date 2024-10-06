#include <stdio.h>



// Excersice 1: Write a simple calculator
void calc(){
    printf("!!!Wellcome to your simple calculator!!! \n");
    char state = 'c';
    int a;
    int  b;
    char operator ;
    while (state != 'e'){
        printf("\nEnter the first number: ");
        scanf("%d" , &a);
        printf("Now enter the operator you want to perform on those two number choose between (/,*,-,+):");
        scanf(" %c", &operator);

        printf("Great, now enter the second number: ");
        scanf("%d" , &b);

        switch (operator)
        {
        case '+':
            printf("The addition of %d and %d is: %d" , a, b , a+b );
            printf("\nPlease press \"e\" or any key to continue: ");
            scanf(" %c", &state);            
            break;
        
        case '-':
            printf("The subtraction of %d and %d is: %d" , a, b , (float)a-b );
            printf("\nPlease press \"e\" or any key to continue: ");
            scanf(" %c", &state);            
            break;

        case '/':
            printf("The devision of %d and %d is: %.5f" , a, b , (float)a/b );
            printf("\nPlease press \"e\" or any key to continue: ");
            scanf(" %c", &state);            
            break;
        
        case '*':
            printf("The Multiplication of %d and %d is: %d" , a, b , a*b );
            printf("\nPlease press \"e\" or any key to continue: ");
            scanf(" %c", &state);            
            break;
            
        
        default:
            printf("Invalid operator!");
            printf("\nPlease press \"e\" or any key to continue: ");
            scanf(" %c", &state);
            printf("states value is: %c\n" , state);
            break;
        }
    }
    printf("The loop is terminated successfully!!");
}


// Exercise2 : Print patterns (e.g., triangle of stars)

void print_patterns(char shape , char pattern , int size ){
    /*This function can print shape of the given pattern
    shape: 
        triangle : 't'
        squares  : 's'
        rectangle : 'r'
    */

   switch (shape)
   {
   case 'r':
        printf("\n");
        for (int i = 1 ; i <= size-1 ; i++){
            for (int j = 1 ; j<= size ; j++ ){
                printf("%c" , pattern);
            }
            printf("\n");

        }
        break;
    case 's':
        printf("\n");
        for (int i = 1 ; i <= size-1 ; i++){
            for (int j = 1 ; j<= size ; j++ ){
                printf("%c" , pattern);
                }
            printf("\n");
        }
        break;

    case 't':
        printf("\n");
        for(int i = 1 ; i<= size ; i++){
            for (int j = size-i ; j>=1 ; j--){
                printf("%c" , ' ');

            }
            for (int k = 1; k<=i ; k++){
                printf("%c" , pattern);
            }

            for (int k = 1; k<=i-1 ; k++){
                printf("%c" , pattern);
            }
            printf("\n");

        }
  
        break;


   default:
    break;}

}


void triangles(int n){
    if (n==0)
        return ;
    else{
        for (int i=1 ; i<=n ; i++){
            printf("%c" , '*');
        }
        printf("\n");
        triangles(n-1);
    }
}

int main(){

    //calc();
    
    //print_patterns('t', 'ö' , 30); //print_pattern(shape , pattern , size)
    printf("\n");
    triangles(3);
    return 0;

}