#include "question_array.h"
#include <stdlib.h>
#include <string.h>

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
        int prices [15] = {100 , 200, 300 ,500 ,1000 ,
         2000, 4000, 8000 , 16000 , 32000 , 64000 , 125000 ,
          250000 , 500000, 1000000 };

          
        for (int i = 0 ; i <=15 ; i++){
            printf("\n----------------------\n%d$ question:\n----------------------\n" , prices[i]);
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
                printf(" ____________________\n|                    |\n|     Game Over      |\n|Exiting the game... |\n|____________________|");
                return;

            }

        }

          
    }
    else {
        printf("\nExiting the game!");
        return;
    }
};
