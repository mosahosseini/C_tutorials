
#include <stdio.h>
#include <stdlib.h>

/*
- Debug a program with memory leaks
- Write clean code for a complex program (e.g., a CLI utility)
*/



// run the following code in linux terminal or wsl (windows sunsystem for linux): 
// valgrind --leak-check=full ./excersices9
// exampel code with memo leak.

int main() {
    int *array = (int *)malloc(5 * sizeof(int));  // Dynamically allocate memory for 5 integers

    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < 5; i++) {
        array[i] = i + 1;
        printf("%d ", array[i]);
    }
    printf("\n");

    // Memory leak: we forgot to free the allocated memory
    return 0;
}

// output from valgrind: we see in summary that  valgrind successfully detects memoryleak. 
/*
==1018== Memcheck, a memory error detector
==1018== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1018== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==1018== Command: ./excersices9
==1018==
1 2 3 4 5
==1018==
==1018== HEAP SUMMARY:
==1018==     in use at exit: 20 bytes in 1 blocks
==1018==   total heap usage: 2 allocs, 1 frees, 1,044 bytes allocated
==1018==
==1018== 20 bytes in 1 blocks are definitely lost in loss record 1 of 1
==1018==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1018==    by 0x1091BE: main (in /mnt/c/Users/sasyn/documents/GitHub/C_tutorials/Lesson9-Debugging_and_Best_Practices/excersices9)
==1018==
==1018== LEAK SUMMARY:
==1018==    definitely lost: 20 bytes in 1 blocks
==1018==    indirectly lost: 0 bytes in 0 blocks
==1018==      possibly lost: 0 bytes in 0 blocks
==1018==    still reachable: 0 bytes in 0 blocks
==1018==         suppressed: 0 bytes in 0 blocks
==1018==
==1018== For lists of detected and suppressed errors, rerun with: -s
==1018== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/