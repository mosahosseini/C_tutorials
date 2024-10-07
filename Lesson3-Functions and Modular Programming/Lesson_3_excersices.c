#include <stdio.h>
#include <limits.h>
//### Exercises:
//Implement factorial using both loops and recursion
//Fibonacci series with functions
//Write reusable functions for array operations (sum, average, etc.)

int factorial_loop(int n);
int factorial_recursion(int n);
int fibonacci(int n);

int main(){
    int n = 3;
    //printf("Factorial of %d is: %d", n ,factorial_loop(n));
    //printf("\n\nFactorial of %d is: %d\n\n", n , factorial_recursion(n));
    printf("\n\n Fibbonacci series of %d is: ", n);
    fibonacci(n);
}

int factorial_loop(int n){
    if (n ==0){
        return 1;
    }

    int fact = 1;
    for (int i=1 ; i<= n ; i++){
        fact = fact*i;
    }
    return fact;
}

int factorial_recursion(int n){
    if (n==1 || n== 0 ){
        return 1;
    }
    else {
        return n*factorial_recursion(n-1);
    }
}


void print_array(int serie [] , int size){
    printf("[");
    for (int i= 0 ; i<= size-1 ; i++){
        if (i==size-1){
            printf("%d", serie[i]);
        }else{
            printf("%d,", serie[i]);            
        }

    }
    printf("]");
}   

int fibonacci(int n){
    int  series [n];
    if (n==1){
        series[0]= 1;
    }
    else if (n>=2)
    {
        series[1]= 2;
        series[0]= 1;
    }


    for (int i = 2  ; i<=n ; i++){
        series[i] = series[i-1]+series[i-2];

    }
    print_array(series, n);
}


float get_array_length( float a [ ] ){
    return sizeof(a)/sizeof(a[0]);
}



//Write reusable functions for array operations (sum, average, etc.)
float array_op(float  a []  , char operation []){
    /* array_op take two float array as input and perform the specified operation 
    operation : ('s', 'a' , 'm')   
    */
   int length_a = get_array_length(a);
   if ( operation == "sum"){
    double sum = 0;
    for (int i = 0 ; i < length_a ; i++){
        sum = sum + a[i];
    }
    return sum;
   }
   else if (operation == "avg" || operation == "mean")
   {
    double sum = 0;

    for (int i = 0 ; i < length_a ; i++){
        sum = sum + a[i];
    }
    return sum/length_a;
   }

   else if (operation == "max")
   {
    double max = LONG_MIN; 
    for (int i = 0 ; i<= length_a ; i++)
    {
        if (a[i]> max )
        {
            max = a[i];
        }
    }
    return max;
   }
   else if (operation == "min")
   {
    double min = LONG_MAX; 
    for (int i = 0 ; i<= length_a ; i++)
    {
        if (a[i]< min )
        {
            min = a[i];
        }
    }
    return min;
   }
return 0;
}

