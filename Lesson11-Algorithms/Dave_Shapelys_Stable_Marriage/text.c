#include <stdio.h>

typedef struct {
    char name[50];
    int age;
}Person;

int main() {
    // Declare an array of 3 Person structs
    Person people[3];

    // Assign values to the structs
    people[0].age = 30;
    snprintf(people[0].name, sizeof(people[0].name), "Alice");

    people[1].age = 25;
    snprintf(people[1].name, sizeof(people[1].name), "Bob");

    people[2].age = 40;
    snprintf(people[2].name, sizeof(people[2].name), "Charlie");

    // Access and print the values
    for (int i = 0; i < 3; i++) {
        printf("Person %d: %s, Age: %d\n", i + 1, people[i].name, people[i].age);
    }

    return 0;
}

