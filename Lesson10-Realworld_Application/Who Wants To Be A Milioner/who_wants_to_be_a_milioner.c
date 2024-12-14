#include "game_handler.h"

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