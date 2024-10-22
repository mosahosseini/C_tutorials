# Functions and Modular Programming
**Duration:** 2-3 weeks

### Topics:
- Functions: Definition, Declaration, and Calling
- Function Prototypes, Parameters, and Return Types
- Recursion
- Variable Scope (Local, Global, Static)

# Table Of Content
- [Functions: Definition, Declaration, and Calling](#1-functions-definition-declaration-and-calling)
- [Function Prototypes](#2-function-prototype)
- [Recursion](#6-recursion)
- [Variable Scope (Local , Global , Static)](#4-variable-scope-local--global--static)

# 1 Functions: Definition, Declaration, and Calling

Unlike programming languages like `c++` and `java`which are object oriented programming languages , `C` is a procedual programming language  which means it has functions instead of classes. 

Functions in C are blocks of code that perform a specific task. They help in organizing your code, improving readability, and reusability.


The basic syntax of function deffinition in C is:
```c
return_type function_name(parameter_list){
    // function body
    // retur statement (if return type is not void)
}
```

- **return_type:**  The data type of the value the function returns. Use `void` if it doesn't return anything.
- **function_name:** A valid identifier for the function
- **parameter_list:** A comma-seperated  list of parameters with their data types. It can be empty if there are no parameters.

Example of a Function:

```c
#include <stdio.h>

int add(int a , int b);

int main(){
    int num1 = 5 , num2 = 18;
    printf("The sum of %d  and %d is: %d", num1 , num2 , add(num1 , num2));
}

int add(int a, int b){
    return a+b;
}
```

**Steps Explained**
1. **Function Prototype:** 
Before the main function, we declare the function prototype: int add(int a, int b);
This tells the compiler about the function’s name, return type, and parameters.

2. **Function Call:**
Inside main, we call the function using add(num1, num2);

3. **Function Definition**:
   - After the `main` function, we define the function: 
     ```c
     int add(int a, int b) {
         return a + b;
     }
     ```
   - This is where the actual logic of adding two integers takes place.


You can also create functions that do not take parameters or do not return a value. Here’s an example:

```c
#include <stdio.h>

// Function prototype
void greet();

int main() {
    greet(); // Calling the function
    return 0;
}

// Function definition
void greet() {
    printf("Hello, World!\n");
}
```

# 2 Function Prototype
In C, you can declare a function and provide the deffinition later on. This declaration of function is called function prototype. 

```c
int add(int a , int b);  // this is function prototype

int main(){
    int a=5,b=2;
    printf("the sum of %d and %d is: %d" , a, b, add(a,b) );
    return 0;
}

int add(int a , int b){
    return a+b;
}
```

# 3 Recursion

A function can also call itself, which is known as recursion. Here’s a simple example of a recursive function to calculate factorial:

```c
#include <stdio.h>

int factorial(int n);

int main() {
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}

int factorial(int n) {
    if (n <= 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive call
}
```
# 4 Variable Scope (Local , Global , Static)

Variable scope in C refers to the visibility and lifetime of a variable within a program. Understanding scope is crucial for managing variables effectively and avoiding naming conflicts. Here’s a breakdown of the different types of scopes in C:

## 4.1 Types of Variable Scope

1. **Block Scope**
   - Variables declared within a pair of braces `{}` have block scope. They are only accessible within that block.
   - **Example:**

   ```c
   #include <stdio.h>

   int main() {
       int x = 10; // x has block scope
       if (x > 5) {
           int y = 20; // y has block scope
           printf("Inside if: x = %d, y = %d\n", x, y);
       }
       // printf("%d", y); // Error: y is not accessible here
       return 0;
   }
   ```

2. **Function Scope**
   - Variables declared within a function (including parameters) are accessible throughout the function.
   - **Example:**

   ```c
   #include <stdio.h>

   void myFunction(int a) { // a has function scope
       int b = 5; // b has function scope
       printf("Inside function: a = %d, b = %d\n", a, b);
   }

   int main() {
       myFunction(10);
       // printf("%d", a); // Error: a is not accessible here
       return 0;
   }
   ```

3. **File Scope (Global Scope)**
   - Variables declared outside of all functions have file scope. They can be accessed by any function in the same file.
   - **Example:**

   ```c
   #include <stdio.h>

   int globalVar = 100; // Global variable

   void printGlobal() {
       printf("Global variable: %d\n", globalVar);
   }

   int main() {
       printGlobal();
       return 0;
   }
   ```

4. **Static Scope**
   - Variables declared with the `static` keyword inside a function maintain their value between function calls but are only accessible within that function.
   - **Example:**

   ```c
   #include <stdio.h>

   void counter() {
       static int count = 0; // Static variable
       count++;
       printf("Count: %d\n", count);
   }

   int main() {
       counter(); // Count: 1
       counter(); // Count: 2
       counter(); // Count: 3
       return 0;
   }
   ```

### 4.2 Summary of Variable Lifetime

- **Automatic Variables**: Default for local variables. Created when a block is entered and destroyed when it exits.
- **Static Variables**: Created when the program starts and destroyed when the program ends. Retain their value across function calls.
- **Global Variables**: Created when the program starts and destroyed when the program ends. Accessible from anywhere in the file.

