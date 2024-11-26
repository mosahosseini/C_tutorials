#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function prototype
#define NUM_CHARS 4
void print_probs(float *prob_arrays, char*  alternatives );
void generatePercentages(char inputChar);
float * softmax(float * arr );
// Deffinition
float * softmax(float * arr ){
    float* probs = (float*) malloc(NUM_CHARS * sizeof(float));
    if (probs == NULL){
        printf("\nMemory allocation for probabilities for softmax failed!!\n");
        exit(1);
    }
    float sum_exps = 0;
    for (int i = 0 ; i <NUM_CHARS ; i++){
        sum_exps += exp(arr[i]);
    }

    for (int i = 0 ; i <NUM_CHARS ; i++){
        probs[i] = exp(arr[i])/sum_exps;
    }

    return probs; 

}

void generatePercentages(char inputChar) {
    srand(time(NULL));
    int index = -1;
    char validChars[NUM_CHARS] = {'a', 'b', 'c', 'd'};
    
    // Find the index corresponding to the inputChar
    for (int i = 0; i < NUM_CHARS; i++) {
        if (validChars[i] == inputChar) {
            index = i;
            break;
        }
    }
    
    // Handle invalid input
    if (index == -1) {
        printf("Invalid input character!\n");
        exit(1);
    }
    
    float rand_vals [4];
    // Generate random values for other indices
   // Seed for randomness
    for (int i = 0 ; i<NUM_CHARS ; i++){

        if (validChars[i] == inputChar){

            rand_vals[i] = 2+ (float) rand()/ (float)RAND_MAX;
        }
        else{
   
            rand_vals[i] = 1 +  (float) rand()/ (float) RAND_MAX;
        }

    }
    float * probs = softmax(rand_vals);
    print_probs(probs , validChars);
    free(probs);
}


void print_probs(float *prob_arrays, char*  alternatives ){
    for (int i = 0 ; i<NUM_CHARS ; i++){
            printf("%c : %.0f%c   " , alternatives[i] , 100*prob_arrays[i] , '%');
    }
}