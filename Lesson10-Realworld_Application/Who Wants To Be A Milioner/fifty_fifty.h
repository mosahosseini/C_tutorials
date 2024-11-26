#include <stdlib.h>
#define NUM_CHARS  4

int get_right_ans_ind(char ans){
    char validChars[NUM_CHARS] = {'a', 'b', 'c', 'd'};
    for (int i = 0 ; i <4 ; i++){
        if (validChars[i] == ans){
            return i;
        }
    }
}



int get_fake_ans_ind(char ans ){
    char validChars[NUM_CHARS] = {'a', 'b', 'c', 'd'};
    int fake_ans_inds[3];
    int counter = 0 ; 

    for (int i = 0 ; i <4 ; i++){
        if (validChars[i] != ans){
            fake_ans_inds[counter] = i; 
            counter++;
        }
    }

    int rand_ind = rand() %3;
    return fake_ans_inds[rand_ind] ;
}