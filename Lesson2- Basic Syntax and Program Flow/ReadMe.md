In this tutorial we are introducing datatypes in C. 

| Types | Describtion | Datatypes |
|----------|----------|----------|
| Primitive data types   | Primitive data types are the most basic data types used to represent simple values ​​like integer, float, character, etc.   | int, char, float, double, void   |
| Derived types    | The data types that are derived from the primitive or built-in data types are called derived data types.   | array, pointer, function   |
| User-defined data types    | The user-defined data types are defined by the user himself.   | structure, union, enum   |

## Primitive Data Type: 
 Primitive data types are the most basic data types used to represent simple values ​​like integer, float, character, etc.
 In C programming we have int , char float , double and void.The storage size and value range are describe 
 
| Type | Storage size |	Value range|
|----------|----------|----------|
| char	        | 1 byte        |   -128 to 127 or 0 to 255                              |
| unsigned char	| 1 byte        |    0 to 255                                            |
| signed char	| 1 byte        |	-128 to 127                                          |
| int           | 2 or 4 bytes  |	-32,768 to 32,767 or -2,147,483,648 to 2,147,483,647 |
| unsigned int  | 2 or 4 bytes  |	0 to 65,535 or 0 to 4,294,967,295                    |
| short	        | 2 bytes       |   -32,768 to 32,767                                    |
| unsigned short| 2 bytes	    |   0 to 65,535                                          |
| long	        | 8 bytes	    |   -9223372036854775808 to 9223372036854775807          |
| unsigned long	| 8 bytes	    |   0 to 18446744073709551615                            |

Runing the code below will print values for 
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
### How to Declare Primitive Data Types

```c
int integerName = 12 ;
float  floateName = 12.2;
char charName = 'h';
char stringName[50] = "Hello World!";
```
$${\color{green}Note that string lateral and charachter constant is Not the same, Which means that "H" and 'H' are NOT Equal}$$

## Drived Data Type:
The data types that are derived from the primitive or built-in data types are called derived data types.  
### Arrays Data Type in C
An array is a collection of multiple values of same data type stored in consecutive memory locations. The size of array is mentioned in square brackets []. Note that array's size can vary depends on how many elements and data type of the elements of the array. 

```c
int variable_name[size_of_array];
```
Array can be initialized at time of declaration. The values to be assigned are put in parentheses. 
``` c
int variable_name[] = {50, 56, 76 , 67 , 43} ;
```

### Strings

So strings are a little bit different in C. When you declare a string, it will get stored in read only memore, That means you can not change it. Lets say you want to store "Hello" in the memore. It will get stored as 
`['H','e','l','l','o','/0']`. The end charachter `\0` marks that end of string.  

```c
char string [50] = "myString" // string with max length 50 charachter
```


Note that there is no string datatype in C. Instead , a string is considererd an array of chars. 

# $${\color{green}Important note}$$:
You can initialize a string by using: 
```c
char string [50] = "myString" // string with max length 50 charachter
```
$${\color{red} But the important part is that assigning a string to an array can couse syntax error. the following code couse error.}$$:

```c
#include <stdio.h>

int main()
{
    char text [50];
    text = "hi how are you"
    printf(text);
    return 0;
}
```



### Pointer Data Type in C
A pointer is a special variable that stores address or reference of another variable/object in the memory. The name of pointer variable is prefixed by asterisk (*). The type of the pointer variable and the variable/object to be pointed must be same. If you want a pointer to point to an object , you must use "&" before the objects name. Here is an example: 

```c
int x;  
int *y;  
y = &x;
```


Just a quick recap of strings:  If we use a pointer variable for a string. The pointer will store the address of the first charachter in the string lateral. Because the end of every string is marked with `/0` we have the address of the entire string. For more information i will reffer you (Basic of string lateral by Nesso Academy)[https://www.youtube.com/watch?v=IlqiTmcK1Eg&list=PLBlnK6fEyqRhwQbYrTDZYJaB4z1YgsAPW&index=1&ab_channel=NesoAcademy]

```c
int main()
{
char *ptr = "Hello World";
printf("%c" , *ptr);
return 0 ;
} // output: H
```

$${\color{green} Important:  Note that because string pointer is pointing to the address of a specific string, you can not modify it after it is pointing to an object.}$$
$${\color{red} The following code will give error }$$ 

```c
char *ptr = "Hello World"
ptr[0] = 'M' 

```



## User-defined data types 
The user-defined data types are defined by the user himself. Example of such Data types are structure, union, enum.

### Struct 
Note that C is not an object origented programming language. Hence there is no classes in C. Instead we can use struct. 

Example: 

```c 
struct car
{
    char name[50]; //you have to provide the size of 
    char model[50];
    int year ;
}; 
```








