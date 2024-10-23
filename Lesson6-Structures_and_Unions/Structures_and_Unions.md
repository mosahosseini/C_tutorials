## 6. Structures and Unions
**Duration:** 1-2 weeks

### Topics:
- Structures: Definition, Initialization, Access
- Array of Structures
- Nested Structures
- Unions and their usage
- Typedef and Enum

# Table Of Content
# Table of Contents

1. [Structures: Definition, Initialization, Access](#1-structure-deffinition--initialization--access)
   - [1.1 Definition](#11-deffinition)
   - [1.2 Declaring Structure Variables](#12-declaring-structure-variables)
   - [1.3 Accessing a Member of Structure](#13-accessing-a-member-of-structure)
   - [1.4 Passing Structures to Functions](#14-passing-structures-to-functions)
   - [1.5 Pointer to Array](#15-pointer-to-array)

2. [Array of Structures](#2-array-of-structures)
   - [2.1 Accessing Members of Structures in an Array](#21-accessing-members-of-structures-in-an-array)
   - [2.2 Looping Through an Array of Structures](#22-looping-through-an-array-of-structures)
   - [2.3 Example: Updating Structure Members](#23-example-updating-structure-members)
   - [2.4 Passing Arrays of Structures to Functions](#24-passing-arrays-of-structures-to-functions)

3. [Nested Structures](#3-nested-structures)
   - [3.1 Defining Nested Structures](#31-defining-nested-structures)
   - [3.2 Initialization](#32-initialization)
   - [3.3 Accessing The Nested Member](#33-accessing-the-nested-member)

4. [Unions and Their Usage](#4-unions-and-their-usage)
   - [4.1 Definition](#41-deffinition)
   - [4.2 Deciding the Size of the Union](#42-deciding-the-size-of-the-union)
   - [4.3 Initialization](#43-initialization)
   - [4.4 Accessing Union Members using Pointers](#44-accessing-the-members-of-the-unions-using-pointers)

5. [Typedef and Enum](#5-typedef-and-enum)
   - [5.1 Typedef Definition](#51-typedef-deffinition)
   - [5.2 Typedef Usage](#52-typedef-usage)
   - [5.3 Enum](#53-enum)
   - [5.4 Definition of Enum](#54-deffinition)
   - [5.5 Difference between Enum and #define](#55-difference-between-enum-and-define)
   - [5.6 Typical Mistakes](#56-typical-mistakes)

# 1. Structure: Deffinition , Initialization , Access
As I explained in Lesson 3 , C is a procedural language , meaning that it has no classes, hence it doesn't support classes , inharetance , encapsulation and object. Instead of objects in C we have struct which reminds us of objects.

## 1.1 Deffinition 
A structure can be considered as an contrainter for a number variable. For example we can have a book structs 
which holds a string variable for name of the book , another string variable for author and an int variable for year and a float variable for price. 
For defining an structure we use the keyword `struct` followed by identifier and curly brackets.


In  other words  a structure is a user-defined data type that allows you to group variables of different types under a single name. Structures are useful for organizing complex data and can contain different data types, such as integers, floats, arrays, and even other structures.

```c
struct book {
    char name[50] ;
    char author[50] ;
    int year;
    float price;  
}
```
## 1.2 Declaring Structure Variables 
 To create instances of book we use `struct identifier name` for example:
 
```c
struct book book1 = {"Lord of the rings" , "J.R.R Tolkien" , 1996 , 24.2};
```
or 
```c
struct book book1 ;
book1.name  = "Lord of the rings";
book1.author = "J.R.R Tolkien";
book1.year  = 1996; 
book1.price = 24.2
```

## 1.3 Accessing a Member of Structure

You can access the members of a structure using the dot operator (`.`):

```c
book1.title  // Accesses the title of book1
book1.author // Accesses the author of book1
```



## 1.4 Passing Structures to Functions

Structures can be passed to functions either by value or by reference:

1. **By Value**: A copy of the structure is passed.
2. **By Reference**: A pointer to the structure is passed, allowing modification.

**Example of passing by reference:**

```c
void printBook(struct Book *b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
}

int main() {
    struct Book book1 = {"C Programming", "Dennis Ritchie", 1978, 29.99};
    printBook(&book1); // Pass the address of book1
    return 0;
}
```

## 1.5 Pointer To Array
You can also create pointers to structures. Use the arrow operator (`->`) to access members through a pointer:

```c
struct Book *ptr = &book1; // Create a pointer to book1

printf("Title: %s\n", ptr->title); // Access via pointer
```

# 2. Array of Structures 
Let’s extend the `Book` structure from the previous example and create an array of `Book` structures.


```c
#include <stdio.h>
#include <string.h>

// Define the structure
struct Book {
    char title[50];
    char author[50];
    int year;
    float price;
};

int main() {
    // Declare an array of 3 Book structures
    struct Book library[3];

    // Initialize the first book
    strcpy(library[0].title, "C Programming");
    strcpy(library[0].author, "Dennis Ritchie");
    library[0].year = 1978;
    library[0].price = 29.99;

    // Initialize the second book
    strcpy(library[1].title, "The C Programming Language");
    strcpy(library[1].author, "Brian Kernighan and Dennis Ritchie");
    library[1].year = 1988;
    library[1].price = 39.99;

    // Initialize the third book
    strcpy(library[2].title, "Computer Networks");
    strcpy(library[2].author, "Andrew S. Tanenbaum");
    library[2].year = 2010;
    library[2].price = 59.99;

    // Print details of all books
    for (int i = 0; i < 3; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("Price: $%.2f\n\n", library[i].price);
    }

    return 0;
}
```

## 2.1  Accessing Members of Structures in an Array
You can access members of each structure in the array using the index operator (`[]`) along with the dot operator (`.`).

## 2.2 Looping Through an Array of Structures
Using a loop (like a `for` loop), you can iterate through the array and access each structure's members.

## 2.3 Example: Updating Structure Members
You can also update members of the structures in the array:

```c
library[1].price = 34.99; // Update the price of the second book
```

## 2.4 Passing Arrays of Structures to Functions

You can pass an array of structures to a function, typically by passing a pointer to the first element of the array. Here’s an example function that prints the details of the books:

```c
void printLibrary(struct Book *lib, int size) {
    for (int i = 0; i < size; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", lib[i].title);
        printf("Author: %s\n", lib[i].author);
        printf("Year: %d\n", lib[i].year);
        printf("Price: $%.2f\n\n", lib[i].price);
    }
}

int main() {
    struct Book library[3] = {
        {"C Programming", "Dennis Ritchie", 1978, 29.99},
        {"The C Programming Language", "Brian Kernighan and Dennis Ritchie", 1988, 39.99},
        {"Computer Networks", "Andrew S. Tanenbaum", 2010, 59.99}
    };

    printLibrary(library, 3); // Pass the array and its size
    return 0;
}
```


# 3. Nested Structures 

In C, nested structures allow you to create complex data types by embedding one structure within another. 
This can help organize related data efficiently. Here’s how you can define and use nested structures in C:

## 3.1 Defining Nested Structures
Here’s an example of how to define nested structures:
```c
#include <stdio.h>

// Define a structure for Address
struct Address {
    char street[50];
    char city[30];
    char state[20];
    int zip;
};

// Define a structure for Person that contains Address
struct Person {
    char name[50];
    int age;
    struct Address address; // Nested structure
};

int main() {
    // Create an instance of Person
    struct Person person;

    // Assign values to the person structure
    snprintf(person.name, sizeof(person.name), "John Doe");
    person.age = 30;
    
    // Assign values to the nested address structure
    snprintf(person.address.street, sizeof(person.address.street), "123 Main St");
    snprintf(person.address.city, sizeof(person.address.city), "Anytown");
    snprintf(person.address.state, sizeof(person.address.state), "CA");
    person.address.zip = 12345;

    // Print person information
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Address: %s, %s, %s %d\n", 
           person.address.street, 
           person.address.city, 
           person.address.state, 
           person.address.zip);

    return 0;
}
```

## 3.2 Initialization 
In the `main` function, we create an instance of `Person` and populate it with data, including the nested `Address`.
## 3.3 Accessing The Nested Member
You access the members of the nested structure using the dot operator (`.`). For example, `person.address.street` accesses the street within the person's address.

# 4. Unions and Their Usage 
Union is a user define datatype but unlike structure, union members shares the same memory location. Lets check wether structure members have the same memory location. 

```c
#include <stdio.h>

int main(){
    struct book {
        char* name  ; 
        char* author;
        int year ;
        float price ; 
    };

    struct book book1 ; 
    book1.name   = "Lord of the rings";
    book1.author = "J.R.R Tolkien";
    book1.year   = 1924;
    book1.price  = 20.4;

    printf("The memory location of name of the book1 is : %p \n" ,book1.name );
    printf("The memory location of the Author of the book1 is: %p" , book1.author);

    return 0;

}
/*
output:
The memory location of name of the book1 is :      00007FF620734000 
The memory location of the Author of the book1 is: 00007FF620734012
*/
```
## 4.1 Deffinition
To define a union, we use `union` keyword followed by `name`.
```c
union book
{
    char* name ; 
    char* author;
    int year ; 
    float price;
}
```
Let us now check the addresses of the members of the union. 

```c
 #include <stdio.h>

int main(){
    union book {
        char* name  ; 
        char* author;
        int year ;
        float price ; 
    };

    union book book1 ; 
    book1.name   = "Lord of the rings";
    book1.author = "J.R.R Tolkien";
    book1.year   = 1924;
    book1.price  = 20.4;

    printf("The memory location of name of the book1 is :      %p\n" ,book1.name );
    printf("The memory location of the Author of the book1 is: %p" , book1.author);

    return 0;
}
/*
output: 
The memory location of name of the book1 is :      00007FF741A33333
The memory location of the Author of the book1 is: 00007FF741A33333
*/
```
This means that union memebers shares the same memory location. 

## 4.2 Deciding the size of the union
The size of union is taken according to the size of the largest member of the union.
## 4.3 Initialization: 
Initialization of union is similar to the one of structures. But something strange happens when we try to change members of unions. Here is an example: 

```c
#include <stdio.h>

int main(){
    union abc {
        int a ;
        char b;
    }  ;

    union abc var ; 
    var.a = 65;

    printf("The value of a is : %d\n" ,var.a );
    printf("The value of b is : %c" , var.b);

    return 0;
}
/*
output: 
The value of a is : 65
The value of b is : A               Note that we havent initialized b member in the code. 
*/
```
We see that even if we did not initialized `b`, it was automatically assigned the value A. It is because in "ASCCI" the value of the character "A" is 65 and because both member share the same memory location , the second member will automatically be assigned value of the first member. 

In other words in c , changing the value of one member in union will reflect to other members aswell. 

## 4.4 Accessing the Members of the unions using pointers 
If we have a pointer to a unoin,  can access the members of the union usiong `->`.

# 5. Typedef and Enum

## 5.1 Typedef deffinition
Typedef allows us to create new datatype from existing ones `typedef existing_data_type  new_data_type`. For example you can replace the int datatype with INTEGER. 

```c
typedef int INTEGER;
```

## 5.2 Typedef Usage

It is very usefull if we want to write a shorter code , we can replace the user defined datatype with new datatype. So let's create an struct datatype. 

```c


int main(){
struct person {
    char * name ; 
    char * address ; 
};

struct person person1;
person1.name = "Alan Turing";
person1.address = "West minister abby 2C"
}
```

Note that every time we want to create an instance of person we need to use`struct person unique_identifier`. Using typedef we can write it shorter as: 

```c
int main(){
typedef struct person {
    char * name ; 
    char * address ; 
} person;


person person1; 
person1.name = "Alan Turing";
person1.address = "West minister abby 2C"

printf("Name : %s\n" , person1.name);
printf("Address: %s" , person1.address);

}
```

## 5.3 Enum
Enums, like structures and unions are user defined datatypes and the main goal of the enum is to assign names to integral constants because names are easier to handle in program. 

## 5.4 Deffinition
The deffinition of enums are similar to struct and union. We use keword `enum` followed by name and members: 

```c
enum name_of_the_datatype {members} 
```
example: 
```c
enum Bool {False ,True} 
```
There are some important facts about enums that we have pay attention to: 
    - If the integer are not assigned to the names , c will automatically assign integer from 0 starting from left to write. 
    - You can have dublicated names and values in enums. 
    - If we have un assigned names in enum , it will automatically be assigned the 1 value higher than previouse deffined member. 
**Example 1**
```c
enum Bool {False , True} var; 
var = True; 
printf("%d" , var); //output: 1

enum coord {x = 0 , y=0 , z= 0};
printf("x: %d  y:%d  z:%d" , cood.x , cood.y , cood.z); //output: x:0 y:0 z:0

enum coord {x = 0 , y=1 , z};
printf("x: %d  y:%d  z:%d" , cood.x , cood.y , cood.z); //output: x:0 y:1 z:2
```


## 5.5 Difference between enum and #define
Similarly to `enum` there is `#define` keyword that is used to assign integral constant to names. The question is if we have `#define` , why do we need `enum`. Well, there is two main differences between those 2. 

    - Unlike `#define`, `enum` can be defined locally. 
    - While `#define` needs explicit initialization of the names, `enum` will automatically assign integer constants to names. 

## 5.6 Typical mistakes 
There are some typical mistakes that can trigger a compilation error while working with `enum`.

    - Don't assig float values to the names it will lead to error. 
    - You can not redeclare a name after it is assigned a value. 

**Example 1:**
```c
enum coods = {x = 0 , y= 1 , z= 2.1} // Error: Enumerator value for 'z' is now an integer constant
```

**Example 2:**
```c
enum coods = {x = 0 , y= 1 , z= 2 , x= 10} // Error: Redeclaration of enumerator x. 
```

