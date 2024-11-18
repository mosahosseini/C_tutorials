#include "question_array.h"
#include <stdlib.h>
#include <string.h>
#include "generate_random_vector.h"
#include "fifty_fifty.h"
#include <unistd.h>  // For the sleep() function

void print_question(Q_obj* question_obj){
    printf("%s" ,question_obj->question);
    printf("%s" ,question_obj->A);
    printf("%s" ,question_obj->B);
    printf("%s" ,question_obj->C);
    printf("%s" ,question_obj->D);
}


void print_part_question(Q_obj* question_obj  , int ans_ind , int fake_ind){
    char** str = (char** ) malloc(sizeof(char*)*4);
    str[0] = strdup(question_obj -> A);
    str[1] = strdup(question_obj -> B);
    str[2] = strdup(question_obj -> C);
    str[3] = strdup(question_obj -> D);
    printf("%s" ,question_obj->question);

    int randomize_order = rand() %2; 
    
    if (randomize_order == 0 ){
        printf("%s" ,str[ans_ind]);
        printf("%s" , str[fake_ind]);
    }
    else{
        printf("%s" ,str[fake_ind]);
        printf("%s" , str[ans_ind]); 
    }
/*

    for (int i = 0 ; i <4 ; i ++){
        free(str[i]);
    }
    free(str);
*/
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


void compare_ans(char right_ans,char ans ){
        // this piece of code gonno be repetetiv, may be it deserve a function ? 
    if (tolower(right_ans) == tolower(ans)){
        printf("Correct!\n\n");
    }
    else {
        printf("Wrong answer!\n");
        printf("Correct answer is: %c \n" , right_ans);
        printf(" ____________________\n|                    |\n|     Game Over      |\n|Exiting the game... |\n|____________________|");
        return;
    }

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
            printf("\n\n%d$ question:\n\n" , prices[i]);
            int random_q_index = rand_array[i];
            print_question(&arr_q_obj[random_q_index]);
            printf("\ncall a friend: f   Ask public: p   50/50: h\n");
            char ans;
            printf("Answer: "); 
            scanf(" %c" , &ans);
            char right_ans = arr_q_obj[random_q_index].Answer[8];
            
            if (tolower(right_ans) == tolower(ans)){
                printf("Correct!\n\n");
            }
            else if ('h' == tolower(ans)){
                int ans_ind = get_right_ans_ind(tolower(right_ans));
                int fake_ans_ind = get_fake_ans_ind(tolower(right_ans));
                print_part_question(&arr_q_obj[random_q_index] , ans_ind , fake_ans_ind );
                printf("Answer: "); 
                scanf(" %c" , &ans);
                compare_ans(right_ans , ans);
            }
            else if('p' == tolower(ans)){
                generatePercentages( tolower(right_ans));
                printf("\nAnswer: "); 
                scanf(" %c" , &ans);
                compare_ans(right_ans , ans);

            }
            else if('f' == tolower(ans)){
                printf("calling Mike .");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                printf("\nMike: I think the answer is: %c\n" , right_ans );
                printf("Answer: ");
                scanf(" %c" , &ans);
                compare_ans(right_ans , ans);
            }

            // add another else if for public , and call a friend 
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
