#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Directory path (corrected type)
    char *dir = "data/secret/";

    // File name
    char *file_name = "1testsmallmessy.out";

    // Allocate enough memory for the concatenated result
    char res[256];  // Ensure this buffer is large enough to hold both strings

    // Concatenate the directory and file name
    strcpy(res, dir);  // Copy the directory path into 'res'
    strcat(res, file_name);  // Append the file name to 'res'

    // Print the concatenated result
    printf("Concatenated path: %s\n", res);

    // Method 1: Use strlen to get the length of file_name
    printf("Length of file_name using strlen: %zu\n", strlen(file_name));

    // Method 2: Manually count the length using a loop
    int i = 0;
    while (file_name[i] != '\0') {
        i++;
    }
    printf("Length of file_name using loop: %d\n", i);

    return 0;
}