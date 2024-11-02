#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/*
### Exercises:
- Implement a linked list from scratch
- Implement a stack using arrays and pointers
- Create a binary tree with traversal functions
*/





int main(){
    Node_t* head = init_linked_list(0);
    add(head, 100);
    add(head,200);
    add(head , 3000) ;  
    head = remove_element(head , 200);

    print_linked_list(head);


    return 0;
}