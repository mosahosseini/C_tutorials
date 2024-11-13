#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>


void list_files(const char *directory) {
    DIR *dir = opendir(directory);  // Open directory
    if (dir == NULL) {  // If opening fails
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;  // Pointer to struct to store directory entry info

    // Iterate through directory entries
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {  // Ignore hidden files
            printf("%s\n", entry->d_name);
        }
    }

    // Check if we encountered an error with reading the directory
    if (errno) {
        perror("Error reading directory");
    }

    closedir(dir);  // Close directory
}


int main(){
 //   list_file("C:\\Users\\sasyn\\Documents\\GitHub\\C_tutorials\\Lesson9-Debugging_and_Best_Practices");
    char cwd[1024];  // Buffer to hold the current directory path
    getcwd(cwd, sizeof(cwd));
    printf("Current directory: %s\n", cwd);
    list_files(cwd);
    return 0 ;
}