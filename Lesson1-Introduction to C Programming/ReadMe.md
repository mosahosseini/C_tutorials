# C Programming: Introduction and Setup

In this lesson, we will start with an introduction to C, discuss why it is important, learn how to set up a C compiler, explore the structure of a C program,get familiar with standard c libraries and finally, write our first program.

---

## Introduction

I am a visual learner, so I will refer to various sources that I find useful for learning C.

One great resource is **Fireship**, which provides a concise **100-second introduction to C**.

1. Fireship - [100 Seconds of C Programming](https://www.youtube.com/watch?v=U3aXWizDbQ4&ab_channel=Fireship)

### Key Points from the Video:
- C is the backbone of many operating systems such as Windows, macOS, and Linux, as well as databases like MySQL.
- It was created in **1972** by **Dennis Ritchie** at **Bell Labs** and was used to develop the UNIX operating system.
- C is known for its **efficiency** and **speed**. It is platform-dependent (e.g., `.exe` files are designed for specific operating systems).
- C compiles directly to machine code, making it one of the fastest programming languages.
- There is no built-in **garbage collection** in C, so developers need to manually manage memory.
- When a variable is created, it is assigned a memory address, which can be stored in another variable called a **pointer**.
- When a variable is no longer needed, we must manually **free** it using the `free(variable_name)` function to avoid **memory leaks**. Failure to free unused memory can lead to memory issues in the application.

---

## 1. Setting Up a C Compiler

Before we dive into programming, we need to set up a C compiler on our machine. Here's how you can get started:

### Windows Setup Using MinGW
To install a C compiler on Windows, we use **MinGW**. This allows us to compile and run C programs on a Windows machine.

- **Guide:** [How to Install MinGW on Windows](https://www.youtube.com/watch?v=Mmy7y8a-WdA&ab_channel=EverythingTech)

### VS Code Setup for C/C++
For writing and compiling C programs, **Visual Studio Code (VS Code)** is an excellent text editor. Here's how to set up VS Code for C/C++ development.

- **Guide:** [Setting Up VS Code for C/C++](https://www.youtube.com/watch?v=9VE7p-he4fA&ab_channel=CodeBear)

---

## 2. Structure of a C Program

Once the compiler is set up, the next step is understanding the structure of a basic C program.

C language contains a number of standard libraries that are usually is the first lines of code you write. Every C program must have at least a main method:
``` c
#include <name_of_the_library.h>
int main(){
    return 0;
}
```
### Naming conventions in C 

Naming conventions in C help improve code readability, maintainability, and consistency. Adhering to standard naming practices ensures that the code is understandable and organized, especially when working in large teams or on long-term projects. Below is an overview of the most common naming conventions used in C:

#### 1. Variable Names

- **Descriptive and meaningful**: Variable names should describe the purpose or role of the variable.
- **Lowercase letters**: Use lowercase letters for general variables.
- **Use underscores**: Use underscores (`_`) to separate words in a variable name (snake_case).

  **Example**:
  ```c
  int employee_count;
  float temperature_reading;
  ```

- **Avoid single-character names**: Except for loop counters or temporary variables, avoid names like `x`, `y`, `i`.

#### 2. Function Names

- **Verb-Noun combination**: Function names should be descriptive and typically include verbs that indicate the action being performed.
- **Lowercase letters**: Function names are generally written in lowercase.
- **Use underscores**: Similar to variables, underscores are used to separate words (snake_case).

  **Example**:
  ```c
  void print_report();
  int calculate_total();
  ```

- **Avoid overly long names**: Keep names concise but descriptive. For example, instead of `calculate_total_sales_for_the_month`, you could use `calculate_monthly_sales`.

#### 3. Constant Names

- **Uppercase letters**: Constants are written in uppercase letters.
- **Underscores between words**: Words in a constant name are separated by underscores.

  **Example**:
  ```c
  #define MAX_BUFFER_SIZE 1024
  const float PI = 3.14159;
  ```

- **Use `const` or `#define` for constants**: Use the `const` keyword or the `#define` preprocessor directive to define constant values.

#### 4. Struct Names

- **CamelCase or PascalCase**: Struct names are usually written in PascalCase (also known as UpperCamelCase), where each word starts with an uppercase letter.
- **Descriptive names**: The struct name should indicate the entity it represents.

  **Example**:
  ```c
  struct EmployeeDetails {
      int employee_id;
      char name[50];
  };
  ```

#### 5. Typedefs

- **CamelCase or PascalCase**: Typedefs follow similar conventions to struct names and are typically written in PascalCase.

  **Example**:
  ```c
  typedef struct EmployeeDetails Employee;
  ```

#### 6. Enumeration Names

- **PascalCase for Enum type**: Enum type names use PascalCase, starting with an uppercase letter.
- **Uppercase for Enum constants**: Enum constants should be in uppercase.

  **Example**:
  ```c
  enum Color {
      RED,
      GREEN,
      BLUE
  };
  ```

#### 7. Global Variables

- **Use of `g_` prefix**: Global variables may use a prefix like `g_` to indicate their global scope.
- **Descriptive names**: Global variable names should be descriptive and written in snake_case.

  **Example**:
  ```c
  int g_total_sales;
  ```

#### 8. Static Variables

- **Use of `s_` prefix**: Static variables within a function or file scope may use an `s_` prefix to indicate their limited scope.
- **Descriptive names**: Similar to global variables, use descriptive names.

  **Example**:
  ```c
  static int s_retry_count;
  ```

#### 9. Pointers

- **Use of `p_` prefix**: Pointers often have a prefix like `p_` to indicate that they are pointers.
- **Descriptive names**: The name should describe the entity to which the pointer refers.

  **Example**:
  ```c
  int *p_employee_id;
  char *p_buffer;
  ```

#### 10. Preprocessor Macros

- **Uppercase letters**: Macros are usually written in uppercase letters, similar to constants.
- **Underscores between words**: Use underscores to separate words in a macro name.

  **Example**:
  ```c
  #define MAX_USERS 100
  #define GET_MAX(a, b) ((a) > (b) ? (a) : (b))
  ```

#### 11. File Names

- **Lowercase letters**: File names are generally written in lowercase.
- **Use underscores**: If the file name contains multiple words, separate them using underscores.
- **C file extensions**: Use `.c` for source files and `.h` for header files.

  **Example**:
  ```
  employee_management.c
  employee_management.h
  ```

#### Summary Table

| Element           | Convention         | Example                        |
|-------------------|--------------------|--------------------------------|
| **Variables**      | lowercase, snake_case | `int total_count;`              |
| **Functions**      | lowercase, snake_case | `void process_data();`         |
| **Constants**      | UPPERCASE, snake_case | `#define MAX_LIMIT 100`        |
| **Structs**        | PascalCase         | `struct UserProfile`           |
| **Typedefs**       | PascalCase         | `typedef struct UserProfile`   |
| **Enums**          | PascalCase/UPPERCASE | `enum Status { ACTIVE, INACTIVE }` |
| **Global Variables**| `g_` prefix, snake_case | `int g_total_sales;`        |
| **Static Variables**| `s_` prefix, snake_case | `static int s_counter;`    |
| **Pointers**       | `p_` prefix        | `int *p_data;`                 |
| **Macros**         | UPPERCASE, snake_case | `#define BUFFER_SIZE 1024`   |
| **File Names**     | lowercase, snake_case | `user_input.c`               |

Following these naming conventions in C will help maintain consistent and easily understandable code.

--- 


## Most Useful C Libraries

This document provides an overview of some of the most essential libraries in C programming. These libraries are widely used for handling input/output, memory management, string manipulation, mathematical computations, and more.

---

## 3. Standard Libraries

### 3.1 `stdio.h` (Standard Input/Output Library)
The `stdio.h` library provides functions for performing basic input/output (I/O) operations such as reading from or writing to the console or files.

- **Common Functions**:
  - `printf()` - Prints formatted output to the console.
  - `scanf()` - Reads formatted input from the console.
  - `fopen()`, `fclose()` - Opens and closes files.
  - `fgets()`, `fputs()` - Reads or writes strings from/to a file.
  - `fread()`, `fwrite()` - Reads or writes binary data from/to a file.

Example:
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```
### 3.2 `stdlib.h` (Standard Library)
The `stdlib.h` library contains functions for memory management, process control, conversions, and random numbers.

Common Functions:
`malloc()`, `calloc()`, `realloc()`, free()` - Dynamic memory allocation and deallocation.
`exit()` - Terminates the program.
`atoi()`, `atof()` - Converts strings to integers or floats.
`rand()`, `srand()` - Generates pseudo-random numbers.
Example: 
``` c
#include <stdlib.h>

int main() {
    int *arr = malloc(10 * sizeof(int)); // Allocate memory for 10 integers
    if (arr == NULL) {
        exit(1); // Exit if memory allocation fails
    }
    free(arr); // Free allocated memory
    return 0;
}
```

### 3.3 `string.h` (String Manipulation Library)
The `string.h` library provides functions for manipulating and handling C strings (character arrays).

Common Functions:
`strlen()` - Returns the length of a string.
`strcpy()`, `strncpy()` - Copies a string.
`strcmp()` - Compares two strings.
`strcat()` - Concatenates two strings.
`memset()`, `memcpy()` - Sets or copies blocks of memory.
``` c
Example: 
#include <string.h>
#include <stdio.h>

int main() {
    char src[20] = "Hello, World!";
    char dest[20];
    
    strcpy(dest, src); // Copy the source string to destination
    printf("Copied string: %s\n", dest);
    
    return 0;
}
```

### 3.4 math.h (Mathematics Library)
The `math.h` library provides functions for mathematical operations including trigonometry, logarithms, and exponentiation.

Common Functions:
`sqrt()` - Returns the square root of a number.
`pow()` - Raises a number to a power.
`sin()`, cos(), tan() - Trigonometric functions.
`log()`, log10() - Returns the natural or base-10 logarithm of a number.
`ceil()`, floor() - Rounds a number up or down.
Example:
``` c
#include <math.h>
#include <stdio.h>

int main() {
    double result = sqrt(25.0); // Compute the square root of 25
    printf("Square root of 25 is %.2f\n", result);
    
    return 0;
}

```

### 3.5 `time.h`  (Date and Time Library)
The `time.h` library provides functions to manipulate and retrieve date and time information.

Common Functions:
`time()` - Returns the current calendar time.
`difftime()` - Computes the difference between two times.
`clock()` - Returns the processor time used by the program.
`strftime()` - Formats date and time as a string.

Example:

``` c
#include <time.h>
#include <stdio.h>

int main() {
    time_t current_time;
    time(&current_time); // Get the current time
    printf("Current time: %s", ctime(&current_time)); // Print the current time
    
    return 0;
}
``` 
## 4. External Libraries
4.1 `pthread.h` (POSIX Threads Library)
The `pthread.h` library provides functions for creating and managing threads for concurrent programming.

Common Functions:
`pthread_create()` - Creates a new thread.
`pthread_join()` - Waits for a thread to finish.
`pthread_mutex_lock()`, `pthread_mutex_unlock()` - Lock and unlock a mutex for thread synchronization.
`pthread_cond_wait()`, `pthread_cond_signal()` - Condition variables for thread coordination.

Example:
```c
#include <pthread.h>
#include <stdio.h>

void* thread_function(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL); // Create a thread
    pthread_join(thread, NULL); // Wait for the thread to finish
    
    return 0;
}

```

2.2 libcurl (Data Transfer via URL Syntax)
The libcurl library is used for making network requests using protocols such as HTTP, FTP, and more.

Common Functions:
`curl_easy_init()` - Initializes a CURL session.
`curl_easy_setopt()` - Sets options for the CURL transfer.
`curl_easy_perform()` - Performs the file transfer.
`curl_easy_cleanup()` - Cleans up the CURL session.

Example: 

```c
#include <curl/curl.h>
#include <stdio.h>

int main() {
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
        curl_easy_perform(curl); // Perform the request
        curl_easy_cleanup(curl); // Cleanup
    }
    return 0;
}
```

