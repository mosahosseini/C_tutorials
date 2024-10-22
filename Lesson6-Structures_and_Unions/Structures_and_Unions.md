## 6. Structures and Unions
**Duration:** 1-2 weeks

### Topics:
- Structures: Definition, Initialization, Access
- Array of Structures
- Nested Structures
- Unions and their usage
- Typedef and Enum

# Table Of Content


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
## 1.1 Declaring Structure Variables 
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

## 1.2 Accessing a Member of Structure

You can access the members of a structure using the dot operator (`.`):

```c
book1.title  // Accesses the title of book1
book1.author // Accesses the author of book1
```



## 1.3 Passing Structures to Functions

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

## 1.4 Pointer To Array
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

# 4. Unions and Their Usage 

# 5. Typedef and Enum





