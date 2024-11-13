#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
// excersice 1 
typedef struct q_obj{
    char* question; 
    char* A; 
    char* B;
    char* C; 
    char* D;
    char* Answer; 
}Q_obj;


void remove_substring(char **str_ptr, const char *substr) {
 //   char *pos = strstr(str, substr); // Find the first occurrence of substr in str
 //   printf("pos is :%s\n", pos);
    int len = strlen(substr);

    // Check if *str_ptr starts with substr
    if (strncmp(*str_ptr, substr, len) == 0) {
        *str_ptr += len;  // Move the pointer past the substring
    }

}



char* get_substring(int i) {

    char str_num[12];
    char substr[100] = "Question ";  // Local buffer for forming the string

    // Convert the integer to a string
    sprintf(str_num, "%d", i);

    // Concatenate the number and ": "
    strcat(substr, str_num);
    strcat(substr, ": ");

    // Allocate memory dynamically for the result
    char *result = (char *)malloc(strlen(substr) + 1); // +1 for the null terminator
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Copy the contents of substr to the dynamically allocated memory
    strcpy(result, substr);

    return result;  // Return the pointer to the dynamically allocated string
}

void init_q_obj(Q_obj* q){
      q->question =(char*) malloc(sizeof(char)*100);
      q->A        =(char*) malloc(sizeof(char)*100);
      q->B        =(char*) malloc(sizeof(char)*100);
      q->C        =(char*) malloc(sizeof(char)*100); 
      q->D        =(char*) malloc(sizeof(char)*100);
      q->Answer   =(char*) malloc(sizeof(char)*10);
}

void init_array(Q_obj * arr , int size ){
    
    for (int i = 0 ; i < size ; i++){
        init_q_obj(&arr[i]);
    }
}


int random_array(int * array ,int size){
    for ( int i = size-1 ; i>= 0 ; i--){
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;  
    }
}

void play_the_game(){
    printf("**************************************\n");
    printf("***** Who Wants To Be A Milioner *****\n");
    printf("**************************************\n\n");

    printf("Are you ready (y/n)?");
    char status; 
    scanf("%c" , &status);

    if (tolower(status) == "y"){
        //TODO: complete
    }
    else {
        printf("\nExiting the game!");
    }
};

int main() {
    FILE *file;    
    char line[256];  // Buffer to hold each line (256 chars per line is common, adjust as needed)
    Q_obj arr_q_obj[100];
    init_array(arr_q_obj , 100);


    time_t now=time(NULL);  
    srand(time(0)) ;

    // Open the file in read mode
    file = fopen("science_questions.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    
    // Read and print each line until end of file
    int question_number = 1 ; 
    int line_number = 1;
    char* st = (char*) malloc(sizeof(char)*256);
    while (fgets(line, sizeof(line), file)) {
        
        strcpy(st , line) ; 
        if (line_number % 7 != 0){
            if (line[0] == 'Q' ){

                char * substr = get_substring(question_number);

                remove_substring(&st,substr);

                strcpy( arr_q_obj[question_number-1].question ,st );

                // ... fix it 
//            printf("Line %d: %s", line_number, line);
                line_number++;
            }
            else if (line[0] == 'A'&& line[1] == '.'){
                 strcpy( arr_q_obj[question_number-1].A ,st );                
                line_number++; 
            }
            else if (line[0] == 'B' ){
                strcpy( arr_q_obj[question_number-1].B ,st );   
                line_number++; 

            }
            else if (line[0] == 'C' ){
                strcpy( arr_q_obj[question_number-1].C ,st );   
                line_number++; 

            }
            else if (line[0] == 'D' ){
                strcpy( arr_q_obj[question_number-1].D ,st );   
                line_number++; 

            }
            else if (line[0] == 'A'   && line[1] == 'n'){
                strcpy( arr_q_obj[question_number-1].Answer ,st );   
                line_number++; 
            
            }

        }else{
            
            if (question_number == 1 || question_number == 2){
                printf("%s" ,arr_q_obj[question_number-1].question);
                printf("%s" ,arr_q_obj[question_number-1].A);
                printf("%s" ,arr_q_obj[question_number-1].B);
                printf("%s" ,arr_q_obj[question_number-1].C);
                printf("%s" ,arr_q_obj[question_number-1].D);
                printf("%s" , arr_q_obj[question_number-1].Answer);
            }
   
            question_number++;

            line_number++;
            
        }


    }
    
    // Close the file
    fclose(file);
    

    return 0;

}