# Lesson 7 File Handling

### Topics:
- File I/O: Opening, Reading, Writing, and Closing Files
- File Pointers and Modes (`r`, `w`, `a`)
- Random Access in Files (`fseek`, `ftell`)

# Table Of Content


# 1. File I/O
In C, file handling is done using the standard library `<stdio.h>`. File operations are carried out with file pointers and the `fopen`, `fclose`, `fread`, `fwrite`, `fseek`, and `ftell` functions.

## 1.1 `fopen` and `fclose`
Files are opened using fopen and closed with fclose. The function `fopen` takes two arguments , the first one is the name of the file and the second one is the mode (determinds if we are reading or writing to the file) and it will return a pointer of type FILE.

Example:  
```c
FILE *filePointer;
filePointer = fopen("filename.txt", "r"); // Opens file in read mode

if (filePointer == NULL) {
    printf("Error opening file.\n");
    return 1;
}

fclose(filePointer); // Closes the file
``` 
## 1.2 File Modes
Here is a table of available file modes. 
| Mode | Description |
|------|-------------|
| `"r"` | Opens a file for reading. Returns `NULL` if the file doesn’t exist. |
| `"w"` | Opens a file for writing. If the file exists, it truncates the content; otherwise, it creates a new file. |
| `"a"` | Opens a file for appending. Creates a new file if it doesn’t exist. |
| `"r+"`| Opens a file for both reading and writing. |
| `"w+"`| Opens a file for both reading and writing, truncating the file first if it exists. |
| `"a+"`| Opens a file for both reading and appending. |

---

## 1.3 Reading/Writing

When working with files in C, there are multiple ways to read from and write to files. Each function has different use cases, depending on whether you’re working with text or binary data, handling line-by-line versus word-by-word operations, and whether your focus is on precision or efficiency. Here’s a breakdown of when to use each function.


## 1.4 Writing To A File
You can Write to a file using `fprintf`, `fputs`, or `fwrite`.
### 1.4.1 `fprintf`
**Use Case:** Writing formatted text data, similar to printf but into a file. This is useful when writing structured information like strings, integers, floats, etc., where formatting (spacing, precision, etc.) is important.

**Syntax**

```c
fprintf(FILE *filePointer, const char *format, ...);
```
**Usecase Example:** 
```c
FILE *file = fopen("data.txt", "w");
if (file == NULL) {
    perror("File opening failed");
    return 1;
}
fprintf(file, "Name: %s, Age: %d, GPA: %.2f\n", "Alice", 20, 3.75);
fclose(file);
```
**Use `fprint` When:**
- Writing human-readable data to a text file.
- Need control over formatting.
- Logging or saving structured data where format is required.

### 1.4.2 `fputs`
Use Case: Writing strings to a file, typically one line or chunk at a time without formatting. It doesn’t append newlines automatically, so if you need to separate lines, you have to add \n manually.

**Syntax:**
```c
fputs(const char *str, FILE *filePointer);
```

**Usecase Example:**
```c
FILE *file = fopen("data.txt", "w");
if (file == NULL) {
    perror("File opening failed");
    return 1;
}
fputs("Hello, World!\n", file);
fputs("Another line of text.\n", file);
fclose(file);
``` 
**Use `fputs` When:**
- Writing text data without formatting.
- Writing simple string data (e.g., line-by-line logging).
- Avoiding format specifiers for faster output when structure isn’t critical.

### 1.4.3 `fwrite`
Use Case: Writing raw binary data or fixed-size data structures to a file. fwrite doesn’t add line breaks or any formatting, so it’s efficient for handling large amounts of binary data or structs.

**Syntax**
```c
fwrite(const void *ptr, size_t size, size_t count, FILE *filePointer);
```

**Usecase Example:**
```c
struct Student {
    char name[50];
    int age;
    float gpa;
};

struct Student s = {"Alice", 20, 3.75};
FILE *file = fopen("data.bin", "wb");
if (file == NULL) {
    perror("File opening failed");
    return 1;
}
fwrite(&s, sizeof(struct Student), 1, file);
fclose(file);
```

**Use `fwrite` when:**
- Writing binary data (like structs or arrays).
- High-performance requirements where raw data storage is preferred.
- Storing data that doesn’t require line breaks or special formatting.



## 1.5 Reading From A File 


### 1. `fscanf`

**Use Case:** Reading formatted text data, like integers, floats, and strings, where specific format specifiers are needed to interpret the data correctly. Similar to `scanf` but for files.

**Syntax:**
```c
fscanf(FILE *filePointer, const char *format, ...);
```

**Example:**
```c
FILE *file = fopen("data.txt", "r");
if (file == NULL) {
    perror("File opening failed");
    return 1;
}
char name[50];
int age;
float gpa;
fscanf(file, "Name: %s, Age: %d, GPA: %f", name, &age, &gpa);
printf("Name: %s, Age: %d, GPA: %.2f\n", name, age, gpa);
fclose(file);
```

**When to Use:**
- Reading structured, formatted text.
- Extracting specific data types and applying formats (useful for parsing structured text).
- Situations where you know the exact format of the input file.

---

### 2. `fgets`

**Use Case:** Reading a line of text at a time (until `\n` or end-of-file) into a string. This is efficient and safe for string-based files but doesn’t parse numbers directly.

**Syntax:**
```c
fgets(char *str, int n, FILE *filePointer);
```

**Example:**
```c
FILE *file = fopen("data.txt", "r");
if (file == NULL) {
    perror("File opening failed");
    return 1;
}
char buffer[100];
while (fgets(buffer, 100, file) != NULL) {
    printf("%s", buffer);
}
fclose(file);
```

**When to Use:**
- Reading text files line-by-line.
- Loading long strings or unstructured text data.
- When you need to read data safely without format specifiers.

---

### 3. `fread`

**Use Case:** Reading raw binary data, commonly used to load files with binary data structures or exact byte-length blocks. It reads exactly the amount specified, without interpretation.

**Syntax:**
```c
fread(void *ptr, size_t size, size_t count, FILE *filePointer);
```

**Example:**
```c
struct Student {
    char name[50];
    int age;
    float gpa;
};

struct Student s;
FILE *file = fopen("data.bin", "rb");
if (file == NULL) {
    perror("File opening failed");
    return 1;
}
fread(&s, sizeof(struct Student), 1, file);
printf("Name: %s, Age: %d, GPA: %.2f\n", s.name, s.age, s.gpa);
fclose(file);
```

**When to Use:**
- Reading binary files or files with fixed-length records.
- High-efficiency data loading, particularly for non-textual data.
- Working with pre-structured data where conversion to text isn’t required.

---

Each command has a unique purpose. Text-based functions (`fprintf`, `fputs`, `fscanf`, `fgets`) work best for human-readable files, while binary-focused functions (`fwrite`, `fread`) are suitable for handling structured data that doesn’t require interpretation. Choose functions based on the structure and format of your data, ensuring compatibility with the intended data structure and format.
















































Here’s a tutorial on basic file I/O operations in C, covering file pointers, modes, and random access. This will help you understand how to open, read, write, and navigate through files in C programming.

---

## 1. Basic File I/O in C

In C, file handling is done using the standard library `<stdio.h>`. File operations are carried out with file pointers and the `fopen`, `fclose`, `fread`, `fwrite`, `fseek`, and `ftell` functions.

### 1.1. Opening and Closing Files

Files are opened using `fopen` and closed with `fclose`.

```c
FILE *filePointer;
filePointer = fopen("filename.txt", "r"); // Opens file in read mode

if (filePointer == NULL) {
    printf("Error opening file.\n");
    return 1;
}

fclose(filePointer); // Closes the file
```

### 1.2. File Modes

| Mode | Description |
|------|-------------|
| `"r"` | Opens a file for reading. Returns `NULL` if the file doesn’t exist. |
| `"w"` | Opens a file for writing. If the file exists, it truncates the content; otherwise, it creates a new file. |
| `"a"` | Opens a file for appending. Creates a new file if it doesn’t exist. |
| `"r+"`| Opens a file for both reading and writing. |
| `"w+"`| Opens a file for both reading and writing, truncating the file first if it exists. |
| `"a+"`| Opens a file for both reading and appending. |

---

## 2. Reading and Writing Files

### 2.1 Writing to a File

To write to a file, you can use `fprintf`, `fputs`, or `fwrite`.

#### Example using `fprintf`:

```c
FILE *file = fopen("example.txt", "w");
if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
}

fprintf(file, "Hello, World!\n");
fclose(file);
```

### 2.2 Reading from a File

You can read from a file using `fscanf`, `fgets`, or `fread`.

#### Example using `fgets` to read a line:

```c
FILE *file = fopen("example.txt", "r");
char buffer[100];

if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
}

while (fgets(buffer, 100, file) != NULL) {
    printf("%s", buffer);
}

fclose(file);
```

---

## 3. Random Access in Files

In C, you can use `fseek` and `ftell` to move around in a file.

### 3.1 `fseek`

`fseek` lets you move to a specific location in the file. Its syntax is:
```c
int fseek(FILE *file, long offset, int origin);
```

- `offset`: number of bytes to move.
- `origin`: starting point, which can be:
  - `SEEK_SET`: Beginning of the file.
  - `SEEK_CUR`: Current position.
  - `SEEK_END`: End of the file.

#### Example using `fseek`:

```c
FILE *file = fopen("example.txt", "r");
fseek(file, 5, SEEK_SET); // Move 5 bytes from the start

char c = fgetc(file); // Read the character at the new position
printf("Character at position 5: %c\n", c);

fclose(file);
```

### 3.2 `ftell`

`ftell` returns the current position of the file pointer.

```c
FILE *file = fopen("example.txt", "r");
fseek(file, 10, SEEK_SET);

long position = ftell(file);
printf("Current position: %ld\n", position);

fclose(file);
```

---

## Example: Combining File I/O with Random Access

Here’s a complete example that writes data, then uses random access to modify it.

```c
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w+");

    // Writing to the file
    fprintf(file, "ABCDEFGHIJ");

    // Moving to the 5th position
    fseek(file, 4, SEEK_SET); // Position to 5th character
    fprintf(file, "X"); // Replaces 'E' with 'X'

    // Check result
    fseek(file, 0, SEEK_SET); // Return to the start
    char buffer[11];
    fread(buffer, 1, 10, file); // Read 10 characters
    buffer[10] = '\0';

    printf("Modified content: %s\n", buffer); // Output: ABCDXFGHIJ

    fclose(file);
    return 0;
}
```

This example opens a file, writes some data, uses `fseek` to move to a specific location, then modifies the content, demonstrating both file I/O and random access in action.

--- 

This should give you a solid foundation in handling files in C. Feel free to experiment with other file modes and functions!