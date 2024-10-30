
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

## How argv And argc Works
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

