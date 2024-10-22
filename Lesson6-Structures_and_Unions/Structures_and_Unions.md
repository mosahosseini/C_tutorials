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
A structure can be considered as an contrainter for a number of data types. For example we can have a car structs which holds a string variable for name , another string variable for model and an int variable for year. For defining an structure we use the keyword `struct` followed by identifier and curly brackets.
```c
struct car {
    char * name ;
    char * model ;
    int year; 
}
```
## 1.1 Initialization 
 To create instances of car we use `struct identifier name` for example:
 
```c
struct car car1 = {"volvo" , "v70" , 1996};
```
or 
```c
struct car car1 ;
car1.name  = "volvo";
car1.model = "v70";
car1.year  = 1996; 
```
# 2. Array of Structures 

# 3. Nested Structures 

# 4. Unions and Their Usage 

# 5. Typedef and Enum