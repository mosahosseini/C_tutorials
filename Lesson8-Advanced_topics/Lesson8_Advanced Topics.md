
### Topics:
- Command Line Arguments
- Preprocessor Directives (`#define`, `#include`, `#ifdef`)
- Bit Manipulation (Shifting, Masking, Bitwise Operators)
- Data Structures (Linked Lists, Stacks, Queues, Trees)



# 1. Command Line Arguments 
If we want to take input from user we can use `scanf()` in the main function look at example below: 

```c
#include <stdio.h>

int main() {

   int a;
   scanf("%d", &a);
   printf("%d", a);
   return 0;
}
```

Instead of using `scanf` it is possible to provide the arguments directly in the command line to the main function. This values are called command line arguments. 


Command line arguments are important for your program, especially when you want to control your program from outside, instead of hard coding those values inside the code.

Let us suppose you want to write a C program "hello.c" that prints a "hello" message for a user. Instead of reading the name from inside the program with scanf(), we wish to pass the name from the command line as follows 

```c
C:\users\user>hello Alex
``` 

## 1.2 argc and argv
To facilitate the main() function to accept arguments from the command line, you should define two arguments in the main() function – argc and argv[].

argc refers to the number of arguments passed and argv[] is a pointer array that points to each argument passed to the program.

```c
int main(int argc, char *argv[]) { 
	... 
	...

	return 0;
}
```

The argc argument should always be non-negative. The argv argument is an array of character pointers to all the arguments, `argv[0]` being the name of the program. After that till "argv [argc - 1]", every element is a command-line argument.

Open any text editor and save the following code as `hello.c` −

```c
#include <stdio.h>

int main (int argc, char * argv[]){
   printf("Hello %s", argv[1]);
   return 0;
}
```

Save the code above as `hello.c` and follow the code below: 

1. open `cmd` and change direcotory to where the code is using `cd`, you can use `ls` to see the files and folders in the current directory. 
2. run the code below: 
```c
gcc -c hello.c -o hello.o
```

3. build the executable file using the command below: 
```c
gcc -o test.exe test.o
```
4. you can now run the code using `file_name argument`:
```c 
hello Alex  
```
5. output will be: 
```c
Hello Alex
```

## 1.3 How argv And argc Works
The `argc` parameter is telling main function how many commandline arguments are expected. 

The `argv[]` paramenter is containing command line arcuments. 

**Note that: `argv[]` is an array that also contains the name of the function**

This means that when you write: 
```c
hello Alex
```
The `argv[]` paramenter contains: 
```c
argv[] = {"hello" , "Alex"}
``` 
Therefore we print only the second element in `argv`. 

## 2. Preprocessor Directives. 
Preprocessors are programs that process the source code before compilation. Several steps are involved between writing a program and executing a program in C. Let us have a look at these steps before we actually start learning about Preprocessors.

![Source: Geek For Geeks ](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Preprocessor-In-C.png)



You can see the intermediate steps in the above diagram. The source code written by programmers is first stored in a file, let the name be “program.c“. This file is then processed by preprocessors and an expanded source code file is generated named “program.i”. This expanded file is compiled by the compiler and an object code file is generated named “program.obj”. Finally, the linker links this object code file to the object code of the library functions to generate the executable file “program.exe”. 

Preprocessor programs provide preprocessor directives that tell the compiler to preprocess the source code before compiling. All of these preprocessor directives begin with a ‘#’ (hash) symbol. The ‘#’ symbol indicates that whatever statement starts with a ‘#’ will go to the preprocessor program to get executed. We can place these preprocessor directives anywhere in our program.

what we know so far about preprocessor: 
* preprocessors are excecuted before the code is compiled. 
* Preprocessor directives tells the compiler to preprocess the source code before compiling.
* Each preprocessor directives start with `#` and can be placed anywehere in the code. 

Examples of some preprocesssor directives are `#include` , `#define` , `#ifndef`.

Remember that the # symbol only provides a path to the preprocessor, and a command such as include is processed by the preprocessor program. For example, #include will include the code or content of the specified file in your program.

|**Perprocessor Directives**|**Describtion**         |
|---------------------------|---------------         |
|#define                    |Used to define macro    |
|#undef                     |Used to undefine a macro| 
|#include                   |Used to include a file in the source code programm|
|#ifdef                     |Used to include a section of code if a certain macro is not defined by #define|
|#if                        |check for the specified condition|
|#else                      |Alternate code that executes when #if fails|
|#elif                      |Combined else and if for another condition check|
|endif                      |Used to mark the end of #if, #ifdef, and ifndef|


## 2.1 Macors 
In C, Macros are piece of code in a program that is given some name. Whenever this name encountered by compiler, the compiler replaces the name with the actual piece of code. To define a macro we use the preprocessor directive `#define`. 
Example: 

```c
#include <stdio.h>
#define PI  3.14
int main(){
printf("The value of pi appoximately is: %f",PI );
}
```

### 2.1.1 Macros with argument
In example above we used macros to declare a constant value. It is also possible to use macros as a function with arguments. 

```c
#include <stdio.h>
#include <math.h>
//#define root(x) sqrt(x)

int main(){
int x = 2; 
printf("root of %d is: %.3f" ,x, root(x) );
}
```
## 2.2 File Inclusion

This type of preprocessor directive tells the compiler to include a file in the source code program. The `#include` preprocessor directive is used to include the header files in the C program.

**There are two types of files that can be included by the user in the program:**

### 2.2.1 Standard Header File
The standard header files contain definitions of pre-defined functions like `printf()`, `scanf()`, etc. These files must be included to work with these functions. Different functions are declared in different header files.

**Syntax**
```c
#include <file_name>
```
where file_name is the name of the header file to be included. The ‘<‘ and ‘>’ brackets tell the compiler to look for the file in the standard directory.

### 2.2.2 User-defined Header Files
When a program becomes very large, it is a good practice to divide it into smaller files and include them whenever needed. These types of files are user-defined header files.

**Syntax**
```c
#include "filename"
```
The double quotes ( ” ” ) tell the compiler to search for the header file in the source file’s directory.

