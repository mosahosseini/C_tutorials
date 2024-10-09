# Topics: Arrays
- Arrays: Single and Multi-dimensional
- String Manipulation (`strlen`, `strcpy`, `strcmp`)
- Array of Strings

# Table of Contents

1. **Introduction to Arrays**  
   1.1. [What is an Array](#11-what-is-an-array)  
   1.2. [Single Dimensional Arrays](#12-single-dimensional-arrays)  
   &nbsp;&nbsp;&nbsp;&nbsp;1.2.1. [Declaration](#121-declaration)  
   &nbsp;&nbsp;&nbsp;&nbsp;1.2.2. [Initializing an Array](#122-initializing-an-array)  
   &nbsp;&nbsp;&nbsp;&nbsp;1.2.3. [Accessing Array Elements](#123-accessing-array-elements)  
   &nbsp;&nbsp;&nbsp;&nbsp;1.2.4. [Array Size and Bound](#124-array-size-and-bound)  
   1.3. [Multi-Dimensional Arrays](#13-multi-dimensional-arrays)

2. **Common Operations on Arrays**  
   2.1. [Finding the Size of an Array](#21-finding-the-size-of-an-array)  
   2.2. [Copying Arrays](#22-copying-arrays)

3. **Strings**  
   3.1. [ String Manipulation](#31-string-manipulation-strlen-strcpy-strcmp)  
   3.1.1. [`strlen` - String Length](#311-strlen---string-length)  
   &nbsp;&nbsp;&nbsp;&nbsp;3.1.2. [`strcpy` – String Copy](#312--strcpy--string-copy)  
   &nbsp;&nbsp;&nbsp;&nbsp;3.1.3. [`strcmp` – String Comparison](#313-strcmp--string-comparison)

4. **Array of Strings**  
   4.1. [Declaring an Array of Strings](#41-declaring-an-array-of-strings)  
   &nbsp;&nbsp;&nbsp;&nbsp;  
   4.2. [Looping Through an Array of Strings](#42-looping-through-an-array-of-strings)  
   4.3. [Operations on Array of Strings](#43-operations-on-array-of-strings)  

5. **Limitations of Arrays**  
   5.1. [Limitations of Arrays](#5-limitation-of-arrays)  
---



# 1 Arrays 
Arrays are a fundamental data structure in the C programming language. They allow you to store multiple values of the same data type in a single, contiguous block of memory. 
This tutorial will introduce you to the concept of arrays, how to declare, initialize, and access them, and cover some common operations.

## 1.1 What is an Array
What is an Array?
An array in C is a collection of elements that are of the same data type (e.g., integers, characters, floats). The elements are stored in contiguous memory locations, and each element can be accessed using an index.

## 1.2 Single Dimensional Arrays

### 1.2.1 Declaration 
To declare an array in C, you need to specify the type of the elements, followed by the array name and the number of elements (i.e., the size of the array). The general syntax is:

```c
data_type array_name[array_size];
```

For Example: 

```c
int numbers[5];  // Declares an array of 5 integers
char letters[10];  // Declares an array of 10 characters
float values[3];   // Declares an array of 3 floats
```
### 1.2.2 Initializing an Array
You can initialize an array in C at the time of declaration. There are two ways to initialize arrays:

1. **Initialize all elements at once:** 
```c
int numbers[5] = {1, 2, 3, 4, 5};
```

2. **Let infer the size**

```c
int numbers[] = {1, 2, 3}; // C will automatically set the size to 3
```

OBS!!! 

If you don't initialize an array, its elements will contain garbage values (random values present in memory).

### 1.2.3 Accessing Array Elements
Array elements are accessed using an index. The index of the first element is 0, the second element is 1, and so on. The syntax to access an element is:
```c
array_name[index]
```
For Example: 
```c
int numbers[5] = {10, 20, 30, 40, 50};
printf("%d\n", numbers[0]);  // Outputs 10
printf("%d\n", numbers[2]);  // Outputs 30
```
You can also modify elements by using the index:
```c
numbers[1] = 25;  // Changes the second element to 25
```

### 1.2.4 Array Size and Bound 
The size of the array is fixed once it is declared. In the example below, the array numbers can only hold 5 elements:

```c
int numbers[5];
```
Accessing an index outside the range of the array (like numbers[5] or numbers[-1]) will lead to undefined behavior and may cause your program to crash.

## 1.2 Multi Dimensional Arrays
C allows you to create arrays with more than one dimension, such as a 2D array. A common example is representing a matrix or a table.

Syntax for 2D Array: 
```c
data_type array_name[rows][columns];
```

Example : 
```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```
You can access elements using two indices:

```c
printf("%d\n", matrix[0][1]);  // Outputs 2
printf("%d\n", matrix[1][2]);  // Outputs 6
```
---
# 2 Common Operations on Arrays

## 2.1 Finding the size of an array
You can find the total size of an array using the sizeof operator, which returns the size in bytes. You can divide this by the size of an individual element to get the number of elements.

Example: 
```c
int numbers[5] = {10, 20, 30, 40, 50};
int size = sizeof(numbers) / sizeof(numbers[0]);  // Array size is 5
printf("Array size: %d\n", size);
```

## 2.2 Copying arrays
To copy one array into another, you need to loop through the array and copy element by element.
```c
int source[5] = {1, 2, 3, 4, 5};
int destination[5];

for (int i = 0; i < 5; i++) {
    destination[i] = source[i];
}
```
# 3 Strings
Strings is an Array of characters. One thing to note is that char and string is not the same. 
Example. 
```c
char a [] ="M";
char b    = 'M';
printf("is the char of M and string of M the same ? %d" , a==b); // output: is the char of M and string of M the same ? 0 
```
This is because in the memory the string is an array and the way it is stored in the memory is that it has a pointer to the first character of the string and then after the last character it will add a special symbol `'\0'` so that it knows where the strings stops. So if we write: 
```c
char a = "M"
```
In the memory it will stored as `['M', '\0']`. 

---
# 3.1 String Manipulation (`strlen`, `strcpy`, `strcmp`) 
In C, strings are arrays of characters terminated by a null character (\0). String manipulation is commonly performed using functions from the <string.h> library. Some of the most frequently used string manipulation functions are `strlen`, `strcpy`, `strcmp`.

## 3.1.1 `strlen` - String Length
`strlen` is used to calculate the length of a string, excluding the null termination (`\0`).

**Syntax:**
```c
size_t strlen(const char *str);
```
- **Parameter**: The string `str` whose length is to be calculated.
- **Return Value**: Returns the number of characters in the string, not including the null character.

**Example:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    int len = strlen(str);
    printf("Length of string: %d\n", len);  // Outputs 13
    return 0;
}
```

## 3.1.2  `strcpy` – String Copy**

`strcpy` is used to copy one string into another.

**Syntax:**
```c
char *strcpy(char *destination, const char *source);
```

- **Parameter**: 
  - `destination`: The array where the string will be copied to.
  - `source`: The string that will be copied.
- **Return Value**: Returns a pointer to the destination string.

**Example:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, C!";
    char dest[20];  // Destination should have enough space
    strcpy(dest, src);
    printf("Copied string: %s\n", dest);  // Outputs "Hello, C!"
    return 0;
}
```

## 3.1.3 `strcmp` – String Comparison**

`strcmp` is used to compare two strings. It compares them lexicographically (alphabetical order).

**Syntax:**
```c
int strcmp(const char *str1, const char *str2);
```

- **Parameter**: 
  - `str1` and `str2` are the two strings to be compared.
- **Return Value**: 
  - `0` if both strings are equal.
  - A negative value if `str1` is lexicographically less than `str2`.
  - A positive value if `str1` is greater than `str2`.

**Example:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "apple";
    char str2[] = "banana";
    
    int result = strcmp(str1, str2);
    
    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("String 1 is less than String 2.\n");  // Outputs this
    } else {
        printf("String 1 is greater than String 2.\n");
    }
    
    return 0;
}
```

---
# 4 Array of Strings
An array of strings is essentially a two-dimensional array of characters. Each element of the array holds a string, where each string is itself an array of characters.

## 4.1 Declaring an Array of Strings

There are two common ways to declare an array of strings in C:

**a) Using a 2D Character Array**

In this method, you specify the number of strings and the maximum length of each string.

**Example:**
```c
#include <stdio.h>

int main() {
    // Declare an array of 3 strings, each with a max length of 20
    char fruits[3][20] = {"Apple", "Banana", "Cherry"};
    
    // Access individual strings
    printf("%s\n", fruits[0]);  // Outputs "Apple"
    printf("%s\n", fruits[1]);  // Outputs "Banana"
    printf("%s\n", fruits[2]);  // Outputs "Cherry"

    return 0;
}
```

In this example, `fruits[0]` gives access to the first string `"Apple"`, and `fruits[1]` gives access to `"Banana"`, and so on.

**b) Using an Array of Pointers to Strings**

In this method, you declare an array of pointers, where each pointer points to the first character of a string.

**Example:**
```c
#include <stdio.h>

int main() {
    // Declare an array of string pointers
    const char *fruits[] = {"pplAe", "Banana", "Cherry"};
    
    // Access individual strings
    printf("%s\n", fruits[0]);  // Outputs "Apple"
    printf("%s\n", fruits[1]);  // Outputs "Banana"
    printf("%s\n", fruits[2]);  // Outputs "Cherry"

    return 0;
}
```

Here, `fruits[0]` is a pointer to the string `"Apple"`, and you can use it like a regular string.

---

## 4.2 Looping Through an Array of Strings

Just like with any other array, you can loop through an array of strings.

**Example:**
```c
#include <stdio.h>

int main() {
    char fruits[3][20] = {"Apple", "Banana", "Cherry"};
    
    for (int i = 0; i < 3; i++) {
        printf("%s\n", fruits[i]);
    }

    return 0;
}
```

This will output:
```
Apple
Banana
Cherry
```

---

## 4.3 Operations on Array of Strings

**a) Copying a String into the Array**

You can use `strcpy` to copy a string into an array of strings.

**Example:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char fruits[3][20] = {"Apple", "Banana", "Cherry"};
    
    strcpy(fruits[1], "Mango");  // Copy "Mango" into the second string
    
    printf("%s\n", fruits[1]);  // Outputs "Mango"

    return 0;
}
```

#### **b) Comparing Strings in the Array**
You can use `strcmp` to compare strings in an array of strings.

**Example:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char fruits[3][20] = {"Apple", "Banana", "Cherry"};
    
    if (strcmp(fruits[0], "Apple") == 0) {
        printf("First fruit is Apple.\n");
    } else {
        printf("First fruit is not Apple.\n");
    }

    return 0;
}
```

#### **c) Finding String Lengths**
You can use `strlen` to find the length of individual strings in the array.

**Example:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char fruits[3][20] = {"Apple", "Banana", "Cherry"};
    
    printf("Length of Banana: %lu\n", strlen(fruits[1]));  // Outputs 6

    return 0;
}
```


# 5 Limitation of Arrays
While arrays are simple and efficient, they do have some limitations:

- **Fixed size:** Once declared, the size of an array cannot be changed dynamically.

- **Lack of bounds checking:** C doesn't automatically check if you're accessing elements outside the array bounds, which can lead to bugs or crashes.

- **No built-in array operations:** Operations like sorting, searching, or appending require manual implementation.
---

End of lesson 4