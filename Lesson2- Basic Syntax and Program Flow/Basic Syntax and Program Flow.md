## Lesson 2:  Basic Syntax and Program Flow
- Variables and Data Types (`int`, `float`, `char`, etc.)
- Input and Output (`printf`, `scanf`)
- Operators (Arithmetic, Relational, Logical)
- Control Flow:
  - Conditional Statements (`if`, `else`, `switch`)
  - Loops (`for`, `while`, `do-while`)


## Table of Contents
1. [Variables and Datatypes](#1variables-and-datatypes)
   - [1.1 What is Datatype](#11-what-is-datatype)
   - [1.2 What is a Variable](#12-what-is-a-variable)
   - [1.3 Datatypes in C](#13-datatypes-in-c)
     - [1.3.1 Primitive Data Type](#131-primitive-data-type)
     - [1.3.2 Derived Data Types](#132-derived-data-types)
       - [1.3.2.1 Arrays Data Type in C](#1321-arrays-data-type-in-c)
       - [1.3.2.2 Strings](#1322-strings)
       - [1.3.2.3 Pointer Data Type in C](#1323-pointer-data-type-in-c)
     - [1.3.3 User-defined Data Types](#133-user-defined-data-types)
       - [1.3.3.1 Struct](#1331-struct)
   - [1.4 Understanding Signed and Unsigned Types in C](#14-understanding-signed-and-unsigned-types-in-c)
     - [1.4.1 Range and Representation](#141-range-and-representation)
     - [1.4.2 When to Use Unsigned and Signed](#142-when-to-use-unsigned-and-signed)
     - [1.4.3 Memory Efficiency](#143-memory-efficiency)
     - [1.4.4 Type-Safety and Explicit Intent](#144-type-safety-and-explicit-intent)
     - [1.4.5 Special Considerations with char](#145-special-considerations-with-char)
2. [Input and Output](#2-input-output)
   - [2.1 Output](#21-output)
     - [2.1.1 Format Specifiers](#211-format-specifiers)
     - [2.1.2 Different Format Specifiers](#212-different-format-specifiers)
     - [2.1.3 How to Use Format Specifiers](#213-how-to-use-format-specifiers)
   - [2.2 User Input](#22-user-input)
   - [2.3 scanf vs printf Behavior](#23-scanf-vs-printf-behavior)
3. [Operators (Arithmetic, Relational, Logical)](#3-operators-arithmetic-relational-logical)
  - [3.1 Arithmetic Operators](#31-arithmetic-operators)
  - [3.1.1 Strange Behavior output of division with rest ](#311-strange-behavior-of-division-with-decimals)
  - [3.2 Relational Operators](#32-relational-operators-in-c)
  - [3.3 Logical Operators](#33-logical-operators-in-c)
  - [3.3.1 Break Down of Logical Operations](#331-breakdown-of-logical-operators)

4. [Control Flow](#4-control-flow)
    - [4.1 Conditional Statements (if else switch )](#41-conditional-statements-if-else-switch)
      -[4.1.1 If and Else Statements](#411-if-and-else) 
      -[4.1.2 Switch case](#412-switch-case)
    - [4.2 Loops (for, while , do-while )](#42-loops-for-while-do-while)
      - [4.2.1 For Statement](#421-for-loop)
      - [4.2.2 While and do-while](#421-while-and-do-while-in-c)
---

## 1. Variables and Datatypes

### 1.1 What is Datatype
A data type defines the type of data that can be stored in a variable or used in an expression. It determines the size of the data in memory, the range of values that can be stored, and the operations that can be performed on that data.

### 1.2 What is a Variable
A variable is a named storage location in memory that holds data of a specific type. A variable must be declared with a data type before it can be used, which tells the compiler what kind of data the variable will store.

### 1.3 Datatypes in C

| Types                  | Description                                                                                                                                 | Datatypes                              |
|------------------------|---------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------|
| Primitive data types    | The most basic data types used to represent simple values like integers, floats, characters, etc.                                        | int, char, float, double, void        |
| Derived types           | Data types that are derived from the primitive or built-in data types.                                                                     | array, pointer, function               |
| User-defined data types | Data types that are defined by the user themselves.                                                                                      | structure, union, enum                 |

#### 1.3.1 Primitive Data Type
Primitive data types are the most basic data types used to represent simple values like integers, floats, characters, etc. In C programming, we have:

| Type               | Storage Size | Value Range                                              |
|--------------------|--------------|----------------------------------------------------------|
| char               | 1 byte       | -128 to 127 or 0 to 255                                  |
| unsigned char      | 1 byte       | 0 to 255                                                 |
| signed char        | 1 byte       | -128 to 127                                             |
| int                | 2 or 4 bytes | -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647    |
| unsigned int       | 2 or 4 bytes | 0 to 65,535 or 0 to 4,294,967,295                       |
| short              | 2 bytes      | -32,768 to 32,767                                       |
| unsigned short     | 2 bytes      | 0 to 65,535                                            |
| long               | 8 bytes      | -9223372036854775808 to 9223372036854775807             |
| unsigned long      | 8 bytes      | 0 to 18446744073709551615                               |

Run the code below to print values:

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, char** argv) {
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
   return 0;
}
```

How to declare a primitive data type:

```c
int integerName = 12;
float floatName = 12.2;
char charName = 'h';
char stringName[50] = "Hello World!";
```

**Note:** String literals and character constants are NOT the same. This means that "H" and 'H' are NOT equal.

#### 1.3.2 Derived Data Types
Derived data types are those that are derived from primitive or built-in data types.

##### 1.3.2.1 Arrays Data Type in C
An array is a collection of multiple values of the same data type stored in consecutive memory locations. The size of the array is mentioned in square brackets []. The array's size can vary depending on how many elements and the data type of the elements.

```c
int variable_name[size_of_array];
```

Arrays can be initialized at the time of declaration:

```c
int variable_name[] = {50, 56, 76, 67, 43};
```

##### 1.3.2.2 Strings
Strings in C are stored in read-only memory, meaning you cannot change them. For instance, when you store "Hello", it is stored as `['H','e','l','l','o','\0']`, where the '\0' character marks the end of the string.

```c
char string[50] = "myString"; // string with max length 50 characters
```

**Note:** There is no string datatype in C; a string is considered an array of chars.

You can initialize a string like this:

```c
char string[50] = "myString"; // string with max length 50 characters
```

**Important:** Assigning a string to an array can cause syntax errors. For example:

```c
#include <stdio.h>

int main() {
    char text[50];
    text = "hi how are you"; // This line will cause an error
    printf("%s", text);
    return 0;
}
```

##### 1.3.2.3 Pointer Data Type in C
A pointer is a special variable that stores the address of another variable or object in memory. The name of a pointer variable is prefixed by an asterisk (*). The type of the pointer variable and the variable/object it points to must be the same. Use the '&' operator to assign the address.

```c
int x;  
int *y;  
y = &x;
```

If you use a pointer variable for a string, it will store the address of the first character in the string literal:

```c
int main() {
    char *ptr = "Hello World";
    printf("%c", *ptr); // Output: H
    return 0;
}
```

<font color=green>**Important:** Note that because a string pointer points to a specific string's address, you cannot modify it after pointing to an object. The following code will give an error:</font>

```c
char *ptr = "Hello World";
ptr[0] = 'M'; // This will cause an error
```

#### 1.3.3 User-defined Data Types
User-defined data types are defined by the user. Examples include structures, unions, and enums.

##### 1.3.3.1 Struct
C is not an object-oriented programming language; hence,

 there are no classes. Instead, we use structs.

Example:

```c
struct car {
    char name[50]; // You must provide the size
    char model[50];
    int year;
};
```

### 1.4 Understanding Signed and Unsigned Types in C
In C, both **signed** and **unsigned** versions of data types like char and int exist to give programmers control over how numbers are stored and interpreted.

#### 1.4.1 Range and Representation
- **Signed Types** (char, int, etc.):
  - Can store both positive and negative values.
  - The most significant bit (MSB) is used as the **sign bit**: 0 for positive and 1 for negative (using two's complement representation).
  - Example ranges:
    - signed char: -128 to 127 (for 8-bit characters)
    - signed int: -2,147,483,648 to 2,147,483,647 (for 32-bit integers)

- **Unsigned Types** (unsigned char, unsigned int, etc.):
  - Used for non-negative values only.
  - All bits represent the value, providing a **larger positive range** than the signed equivalent.
  - Example ranges:
    - unsigned char: 0 to 255 (for 8-bit characters)
    - unsigned int: 0 to 4,294,967,295 (for 32-bit integers)

#### 1.4.2 When to Use Unsigned and Signed
- **unsigned char**: Used for data that is always positive (e.g., pixel values).
  
```c
unsigned char pixel_value = 200; // Pixel values range from 0 to 255
```

- **signed char**: Used for small numbers that can be positive or negative.

```c
signed char temperature = -30; // Temperature in Celsius
```

- **unsigned int**: Ideal for representing counts or any value guaranteed to be non-negative.

```c
unsigned int items_in_inventory = 10000; // Always positive count
```

- **signed int**: Suitable for values that can be both positive and negative.

```c
signed int balance = -500; // Negative balance in a bank account
```

#### 1.4.3 Memory Efficiency
Unsigned types maximize the use of available bits. For instance, an 8-bit unsigned char can hold values from 0 to 255, while an 8-bit signed char can only hold values between -128 and 127.

#### 1.4.4 Type-Safety and Explicit Intent
Choosing between signed and unsigned types clarifies the code:
- **Unsigned types** indicate that the value will not be negative.
- **Signed types** indicate that the variable can hold both positive and negative numbers.

For instance, loop counters, array indices, and object counts should be declared as unsigned for clarity and correctness.

#### 1.4.5 Special Considerations with char
The char type in C can be either signed or unsigned depending on the compiler and platform. It’s best practice to explicitly use signed char or unsigned char when you need a specific range to avoid ambiguity.

---

## 2. Input and Output

### 2.1 Output
To output data, first include the `stdio.h` library. Like Java, C is also a brace-delimited language, meaning you must put a semicolon at the end of statements.

```c
#include <stdio.h>

int main() {
    printf("Hello World!");
    return 0;
}
```

#### 2.1.1 Format Specifiers
Functions like `printf()` require format specifiers to tell the compiler how to format and display the corresponding arguments.

### Handling Multiple Data Types:

```c
#include <stdio.h>

int main() {
    int age = 12;
    char first_letter = 'M';
    printf("Your age is: ? and your name starts with: ? ");
}
```

#### 2.1.2 Different Format Specifiers

| Data Type               | Format Specifier   |
|-------------------------|---------------------|
| Signed integers (int)   | %d                  |
| Unsigned integers        | %u                  |
| Floating-point numbers   | %f                  |
| Characters (char)       | %c                  |
| Strings (arrays of chars)| %s                  |

#### 2.1.3 How to Use Format Specifiers

Here’s how to use format specifiers:

```c
#include <stdio.h>

int main() {
    int age = 12;
    char first_letter = 'M';
    printf("Your age is: %d and your name starts with: %c", age, first_letter); // Output: Your age is: 12 and your name starts with: M
    return 0;
}
```

**Note:** The order of variables in `printf` is important. Changing the placement of `age` and `first_letter` will produce incorrect output.

### 2.2 User Input
To get input from the user, use the `scanf()` function from the `stdio.h` library. The `scanf()` function requires format specifiers and the memory address of the variable.

```c
#include <stdio.h>

int main() {
    int p_age;
    printf("Enter your age: ");
    scanf("%d", &p_age);
    printf("You were born in the year: %d", 2024 - p_age);
    return 0;
}
```

### 2.3 scanf vs printf Behavior
- **scanf**: Modifies the values of variables; requires the **address** of the variables to write user input directly into memory.
- **printf**: Reads and displays values stored in variables; requires the **value** of the variable, not its address.

---


# 3. Operators (Arithmetic, Relational, Logical)

Operators are symbols that perform operations on variables and values. In C programming, operators are classified into several categories based on the type of operation they perform. In this tutorial, we'll cover three main types of operators:

## 3.1 Arithmetic Operators 
Arithmetic operators are used to perform basic mathematical operations.

| Operator | Symbol | Description               | Example               |
|----------|--------|---------------------------|-----------------------|
| Addition | `+`    | Adds two operands          | `a + b`               |
| Subtraction | `-` | Subtracts second operand from first | `a - b`      |
| Multiplication | `*` | Multiplies two operands  | `a * b`               |
| Division | `/`   | Divides first operand by second | `a / b`           |
| Modulus | `%`    | Returns remainder of division | `a % b`            |


```c
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    
    printf("Addition: %d\n", a + b);       // Outputs 30
    printf("Subtraction: %d\n", b - a);    // Outputs 10
    printf("Multiplication: %d\n", a * b); // Outputs 200
    printf("Division: %d\n", b / a);       // Outputs 2
    printf("Modulus: %d\n", b % a);        // Outputs 0

    return 0;
}
```

### 3.1.1 Strange Behavior of division with decimals
Something strange happens when the result of the devision of two integers have decimals. The decimals will be truncated.

In C programming, when you perform the division 1 / 2, the result will be 0 because both 1 and 2 are integers, and integer division in C truncates the decimal part, leaving only the integer part of the result.

To print the result of 1 / 2 as a decimal (e.g., 0.5), you need to perform floating-point division by ensuring that at least one of the operands is a float or double. You can do this in several ways:

- Using typecasting: Convert one of the integers to float or double before performing the division.

- Using floating-point literals: Write the numbers as 1.0 and 2.0.

```c
#include <stdio.h>
int main(){
  printf("Incorrect: The devision of 1 by 2 is : %f \n" , 1/2); //output: 0
  printf("Alternative 1: The devision of 1 by 2 is : %.2f \n" , (float) 1/2); //output: 0.50
  printf("Alternative 2: The devision of 1 by 2 is : %.2f \n" , 1.0/2.0); //output: 0.50

  return 0;
}
```


## 3.2 Relational Operators in C
Relational operators are used to compare two values or variables. They return either `1` (true) or `0` (false) based on the comparison.

| Operator | Symbol | Description                     | Example     |
|----------|--------|---------------------------------|-------------|
| Equal to | `==`   | Returns true if both operands are equal | `a == b`   |
| Not equal to | `!=` | Returns true if operands are not equal | `a != b`   |
| Greater than | `>` | Returns true if first operand is greater than second | `a > b` |
| Less than | `<` | Returns true if first operand is less than second | `a < b` |
| Greater than or equal to | `>=` | Returns true if first operand is greater than or equal to second | `a >= b` |
| Less than or equal to | `<=` | Returns true if first operand is less than or equal to second | `a <= b` |

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20;

    printf("a == b: %d\n", a == b);    // Outputs 0 (false)
    printf("a != b: %d\n", a != b);    // Outputs 1 (true)
    printf("a > b: %d\n", a > b);      // Outputs 0 (false)
    printf("a < b: %d\n", a < b);      // Outputs 1 (true)
    printf("a >= b: %d\n", a >= b);    // Outputs 0 (false)
    printf("a <= b: %d\n", a <= b);    // Outputs 1 (true)

    return 0;
}
```

## 3.3 Logical Operators in C
Logical operators are used to perform logical operations between expressions or conditions. The result is either `true` (1) or `false` (0).

| Operator | Symbol | Description                                   | Example          |
|----------|--------|-----------------------------------------------|------------------|
| Logical AND | `&&` | Returns true if both conditions are true      | `(a > 5) && (b < 30)` |
| Logical OR | `\|\|` | Returns true if at least one condition is true | `(a > 5) \|\| (b < 10)` |
| Logical NOT | `!`  | Reverses the logical state of its operand      | `!(a == b)`      |

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20;

    printf("(a > 5 && b < 30): %d\n", (a > 5 && b < 30));  // Outputs 1 (true)
    printf("(a > 15 || b < 10): %d\n", (a > 15 || b < 10)); // Outputs 0 (false)
    printf("!(a == b): %d\n", !(a == b));                  // Outputs 1 (true)

    return 0;
}
```

### 3.3.1 Breakdown of Logical Operators:

1. **Logical AND (`&&`)**:
   - It returns `true` if **both** conditions are true.
   - Example: `(a > 5 && b < 30)` evaluates to `true` if both `a > 5` and `b < 30` are true.

2. **Logical OR (`||`)**:
   - It returns `true` if **at least one** of the conditions is true.
   - Example: `(a > 15 || b < 10)` evaluates to `true` if either `a > 15` or `b < 10` is true.

3. **Logical NOT (`!`)**:
   - It negates the condition.
   - Example: `!(a == b)` evaluates to `true` if `a` is **not equal** to `b`.

---

### 3.4 Summary of Operators
In this tutorial, we covered three main types of operators in C:

1. **Arithmetic Operators** for mathematical calculations like addition, subtraction, etc.
2. **Relational Operators** for comparing values, returning true or false.
3. **Logical Operators** for performing logical operations on conditions.



# 4. Control Flow

## 4.1 Conditional Statements (`if`, `else`, `switch`)
Conditional statements are the most important part of any progamming language. 
### 4.1.1 if and else 
If statement is very easy in C we declare if statement with a condition.
```C
void if_statement(int a){
if (a > 10){
  printf("The number is larger than 10");
} 
else{
  printf("The number is smaller than or equal to 10");
}};
```
### 4.1.2 Switch case
In C, a switch statement allows you to execute different blocks of code based on the value of an expression, typically an integer or character. It can be more readable than a series of if-else statements, especially when dealing with multiple conditions. 

The switch statement in C doesn't support relational conditions like >=, <=, or any other comparison operators directly. It only matches specific values (like exact integers or characters) against the expression you provide.

```C
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
```
## 4.2 Loops (`for`, `while`, `do-while`)
Loops are fundamental constructs that allow you to execute a block of code multiple times based on a condition. 
### 4.2.1 For Loop
For loop in c need a counter , how long should counter do "stop condition" and the increment for example ´for (int i = 0 , i <=10 , i++)´.  
```c 
void for_loop(int reps){
for (int i , i <= 10, i++){
  printf("i : %d" , i);
}}
```
### 4.2.1 While and do-while in C
The while and do-while loops are two common types of loops in C. The difference is that in while loop the condition is checked first and the code will get excecuted only if the condition is true. In orther words while loops checks the condition first, then runs the code. OBS! Make sure that the condition will be met, otherwise the code will get stuck in infinite loop and your IDE will crach. 

```c
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
```

Do while loop is the opposite , it will run the code block then checks the condition. 

```c
void do_while_loop(int reps){
 
    do {
        printf("i: %d \n" , reps); 
        reps --;

    }while( reps >= 1);
}
```






