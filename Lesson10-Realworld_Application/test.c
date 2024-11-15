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


void load_questions(Q_obj * arr_q_obj);

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

void free_q_obj(Q_obj *q){
    free(q->question);
    free(q->A);
    free(q->B);
    free(q->C);
    free(q->D);
    free(q->Answer);
}

void free_array(Q_obj * arr, int size ){
    for(int i = 0 ; i< size ; i++){
        free_q_obj(&arr[i]);
    }
    printf("\nArray successfully dealocated!\n");
    return;
}


int random_array(int * array ,int size){
    for (int i = 0; i <size ;i++ ){
        array[i] = i;
    }
    for ( int i = size-1 ; i>= 0 ; i--){
        time_t now=time(NULL);  
        srand(time(0)) ;
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;  
    }
}

void print_question(Q_obj* question_obj){
    printf("%s" ,question_obj->question);
    printf("%s" ,question_obj->A);
    printf("%s" ,question_obj->B);
    printf("%s" ,question_obj->C);
    printf("%s" ,question_obj->D);
}

void load_questions(Q_obj * arr_q_obj){
    FILE *file;    
    char line[256];  // Buffer to hold each line (256 chars per line is common, adjust as needed)
    // Open the file in read mode
    file = fopen("science_questions.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
    }
    
    // Read and print each line until end of file
    
    int question_number = 1 ; 
    int line_number = 1;
    char* st = (char*) malloc(sizeof(char)*256);
    while (fgets(line, sizeof(line), file)) {
        
        strcpy(st , line) ; 
        if (line_number % 7 != 0){
            if (line_number %7 == 1 ){
                strcpy( arr_q_obj[question_number-1].question ,st );

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
            question_number++;

            line_number++;
            
        }
    }
    free(st);
    fclose(file);

}

void play_the_game(int size){
    printf("\n**************************************\n");
    printf("***** Who Wants To Be A Milioner *****\n");
    printf("**************************************\n\n");

    printf("Are you ready (y/n)?");
    char status; 
    scanf("%c" , &status);
    if (tolower(status) == 'y'){
        int rand_array[size];
        random_array(rand_array, size);
        Q_obj arr_q_obj[size];
        init_array(arr_q_obj , size);
        load_questions(arr_q_obj);
//free_array(arr_q_obj , num_q);    
        int won_so_far = 10 ;   
        for (int i = 0 ; i <15 ; i++){
            if  ( i %3 == 0 && i != 0){
                won_so_far *=10;
                printf("\nCongrats! You have %d kr!\n", won_so_far);
            }
            int random_q_index = rand_array[i];
            print_question(&arr_q_obj[random_q_index]);
            char ans;
            printf("Answer: "); 
            scanf(" %c" , &ans);
            char right_ans = arr_q_obj[random_q_index].Answer[8];

            if (ans == tolower(right_ans)){
                printf("Correct!\n\n");
            }
            else {
                printf("Wrong answer!\n");
                printf("Correct answer is: %c \n" , right_ans);

            }

        }

          
    }
    else {
        printf("\nExiting the game!");
        return;
    }
};


int main() {
    int num_q = 58; 
//    load_questions(arr_q_obj);
//    free_array(arr_q_obj , num_q);
    play_the_game(num_q);

/*

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
            if (line_number %7 == 1 ){
                strcpy( arr_q_obj[question_number-1].question ,st );

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

    free_array(arr_q_obj , num_q);
    // Close the file
 
    
*/
   
    return 0;

}