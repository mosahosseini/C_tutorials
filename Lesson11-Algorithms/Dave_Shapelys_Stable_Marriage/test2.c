#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

typedef struct {
    int index;
    int * preferences;
    int visited;
    int husband_ind;
} woman;


void inverted_pref_list(int * pref_list , int n){
    // This function will invert preference list of the woman.
    // This means that the value of the preference will be the index and the index will be the value. 
    int temp_array [n]; // create a temporary array
    int ind ; 
    int val ; 
    for (int i = 0 ; i<n ; i++){
        ind = pref_list[i];  // the index will be the value on i:th position 
        val = i+1; // the value 
        temp_array[ind-1] = val;  
    }

    for (int i = 0 ; i<n ; i++){
        pref_list[i] = temp_array[i]; // let the ith value of preflist be the ith value of the temparray. 
    }

}

int* copy_preferences(int* pref_plus_ind , int n){
    // this function will copy the preference list, this is because the preference list not containing the index. 
    int * only_prefs = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i<n; i++){
        only_prefs[i] = pref_plus_ind[i+1];
    }
    return only_prefs;

}

void find_matches(man* men, woman* women, int n) {
    printf("DEBUG: Starting matching algorithm\n");
    
    STACK* men_stack = init_stack(n);
    if (!men_stack) {
        printf("ERROR: Failed to initialize stack\n");
        return;
    }

    // Add all men to stack
    for (int i = n-1; i >= 0; i--) {
        printf("DEBUG: Adding man %d to stack\n", men[i].index);
        push(men_stack, &men[i]);
        
    }

    while (!is_empty(men_stack)) {
        man* current_man = pop(men_stack);
        if (!current_man) {
            printf("ERROR: Failed to pop from stack\n");
            continue;
        }
        
        int new_man_ind = current_man->index;
        printf("\nDEBUG: Processing man %d\n", new_man_ind);
        
        // Increment proposal index
        current_man->proposed_ind++;
        int pref_ind = current_man->proposed_ind;
        
        if (pref_ind >= n) {
            printf("ERROR: Man %d has exhausted his preference list\n", new_man_ind);
            continue;
        }

        // Get preferred woman's index
        int prefered_woman_ind = current_man->preferences[pref_ind];
        printf("DEBUG: Man %d proposing to woman %d (preference %d)\n", 
               new_man_ind, prefered_woman_ind, pref_ind + 1);

        // Get current husband of preferred woman
        int old_man_ind = women[prefered_woman_ind-1].husband_ind;
        printf("DEBUG: Woman %d current husband is %d\n", 
               prefered_woman_ind, old_man_ind);

        // Get preferences
        int new_pref = women[prefered_woman_ind-1].preferences[new_man_ind-1];
        int old_pref = (old_man_ind == -1) ? n + 1 : 
                       women[prefered_woman_ind-1].preferences[old_man_ind-1];

        if (old_man_ind == -1) {
            printf("DEBUG: Woman %d is free, accepting proposal\n", prefered_woman_ind);
            men[new_man_ind-1].wife_ind = prefered_woman_ind;
            women[prefered_woman_ind-1].husband_ind = new_man_ind;
        }
        else if (new_pref < old_pref) {
            printf("DEBUG: Woman %d prefers new man %d over current man %d\n", 
                   prefered_woman_ind, new_man_ind, old_man_ind);
            women[prefered_woman_ind-1].husband_ind = new_man_ind;
            men[new_man_ind-1].wife_ind = prefered_woman_ind;
            men[old_man_ind-1].wife_ind = -1;
            push(men_stack, &men[old_man_ind-1]);
        }
        else {
            printf("DEBUG: Woman %d rejects man %d\n", prefered_woman_ind, new_man_ind);
            push(men_stack, &men[new_man_ind-1]);
        }
    }

    printf("\nDEBUG: Matching complete. Final pairings:\n");
    for (int i = 0; i < n; i++) {
        printf("Man %d married to Woman %d\n", i+1, men[i].wife_ind);
    }
}

void print_preferences(man* men, woman* women, int n) {
    printf("\n=== Current State ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nMan %d (wife: %d) preferences: [", 
               men[i].index, men[i].wife_ind);
        for (int j = 0; j < n; j++) {
            printf("%d ", men[i].preferences[j]);
        }
        printf("]");

        printf("\nWoman %d (husband: %d) preferences: [", 
               women[i].index, women[i].husband_ind);
        for (int j = 0; j < n; j++) {
            printf("%d ", women[i].preferences[j]);
        }
        printf("]\n");
    }
    printf("===================\n");
}


int main(){

    int n; //Number of pairs
    FILE* file = fopen("data/sample/3.txt", "r") ;  // creates a file object. 
    if(file == NULL){  
        perror("File opening failed");
        return 1 ; 
    } 
    fscanf(file,"%d" , &n); // we read the first value and store it in n
    
    // Dynamically allocate memory for 'men' and 'women'
    man* men = (man*)malloc(n * sizeof(man));
    woman* women = (woman*)malloc(n * sizeof(woman));
    
    //we loop over the men and women array and initialize some parameters. 

    for (int i = 0 ; i<n ;i++){
        men[i].visited=0;
        men[i].wife_ind = -1 ; 
        women[i].visited = 0;
        women[i].husband_ind = -1 ; 


    }
    // We know that there is 2*n rows in the data set. 
    for (int i = 0 ; i<2*n ; i++){
        int * index_plus_preferences = (int*) malloc(sizeof(int)* (n+1)); // this array will contain both index and preference. 
        
        if (index_plus_preferences == NULL){
            perror("Memory allocation for preferences failed!");
            return 1;
        }
        // each row contains n+1 values which. the first is the index then n element for preferences
        int val ; 
        for (int j = 0 ; j< n+1 ; j++ ) {
            //fscanf(file,"%d" , &index_plus_preferences[j]);
            fscanf(file,"%d" , &val);
            index_plus_preferences[j] = val;
        }
        
        int ind = index_plus_preferences[0]-1; 
        
        //We don't know if the index and preferences is for the woman, or man. Therefore we use 
        //Visited parameted. 
        //IF the woman have recieved a preference array, we know that the preference is for the man[ind]
        if (women[ind].visited){ 
            men[ind].index = ind+1; 
            men[ind].preferences = copy_preferences(index_plus_preferences, n);
            men[ind].visited = 1 ; //set visited to 1
            men[ind].proposed_ind = -1;  // The index of the woman he proposes to;
            free(index_plus_preferences);

        }else{
            // else , we know that the woman is not visited yet therefor we fill preference to the woman 
            women[ind].index = ind+1; 
            women[ind].preferences = copy_preferences(index_plus_preferences, n);
            women[ind].visited = 1 ; //set visited to 1 
            free(index_plus_preferences); // free the index plus pref
        }

        }

        // we invert each womans preference list 
        for (int i = 0 ; i<n ; i++){
            inverted_pref_list(women[i].preferences , n);
        }

//        print_preferences(men , women , n);


        find_matches(men , women , n);
        print_preferences(men , women , n);

        // woman w ;
        // for (int i = 0 ; i<n ; i++){
        //     w = women[i];
        //     printf("%d", w.husband_ind );
        // }
        for (int i = 0; i < n; i++) {
    free(men[i].preferences);
    free(women[i].preferences);
        }
        free(men);
        free(women);
        return 0;
}