#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <unistd.h>


// struct that defines a woman
typedef struct {
int index;  // index of he woman 
int * preferences; // an array containing preference list of the woman 
int visited; // this is a boolean parameter that will be used when reading the data. 
int husband_ind;  // the index of the husband of the woman. 
}woman;

void read_input(man *men, woman *women, int *index_plus_preferences, int n) {
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%d", &index_plus_preferences[j]);
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
            

        }else{
            // else , we know that the woman is not visited yet therefor we fill preference to the woman 
            women[ind].index = ind+1; 
            women[ind].preferences = copy_preferences(index_plus_preferences, n);
            women[ind].visited = 1 ; //set visited to 1 

        }
        
        // Further logic to assign preferences based on the read data
    }
}


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
    // Ensure that the array has enough space for n elements
    if (pref_plus_ind == NULL) {
        perror("Input array for preferences is NULL");
        exit(1);
    }

    int *only_prefs = (int*) malloc(sizeof(int) * n);
    if (only_prefs == NULL) {
        perror("Memory allocation for preferences failed!");
        exit(1);
    }

    // Copy preferences skipping the first index
    for (int i = 0; i < n; i++) {
        if (i + 1 >= n + 1) {
            printf("Index out of bounds: i = %d, n = %d\n", i + 1, n);
            exit(1);
        }
        only_prefs[i] = pref_plus_ind[i + 1];  // Skip first element, copy preferences
    }

    return only_prefs;

}

void print_preferences(man* men , woman* women , int n){

        printf("\n\n\n");
        for(int j = 0 ; j <n ; j++){
            
            printf("man %d pref:   [" , j+1);
            for (int i = 0 ; i <n ; i ++){
                printf(" %d ", men[j].preferences[i]);
            }
            
            printf("]\n");
            printf("woman %d pref: [" , j+1);
            for (int i = 0 ; i <n ; i ++){
                printf(" %d ", women[j].preferences[i]);
            }
            printf("]\n");
        }
}

void print_husbands(woman* women , int n ){
            for (int i = 0 ; i<n ; i++){
            woman m = women[i];
            printf("%d\n", m.husband_ind );
            fflush(stdout);
        }
}


void find_matches(man * men , woman* women , int n){
        STACK * men_stack = init_stack(n);
        for (int i = n-1 ; i>= 0  ; i--)
        {
            push(men_stack , &men[i]);
        }


        int prefered_woman_ind , old_man_ind , pref_ind ,new_man_ind ,new_pref ,old_pref; 
        while (!is_empty(men_stack)){
            new_man_ind = pop(men_stack)->index;  //pop a man from the stack
            pref_ind = ++men[new_man_ind-1].proposed_ind ;  // go to next index in preference list. note that proposed_ind is initialized to -1 and if we go to next index it will be 0 which is the begining of the pref array.
            prefered_woman_ind = men[new_man_ind-1].preferences[pref_ind]; // the index of the prefered woman. 
            old_man_ind = women[prefered_woman_ind-1].husband_ind; //index of the prefered womans current man (-1 if the woman doesn't have any husband)
            
            //this two variable is to find out where in preference list of the woman is the new man and her current husband. 
            new_pref = women[prefered_woman_ind-1].preferences[new_man_ind-1];  
            old_pref =  women[prefered_woman_ind-1].preferences[old_man_ind-1];
            
            if (old_man_ind == -1 ){ // if prefered women is not proposed to the new man and his prefered woman will be a pair

                men[new_man_ind-1].wife_ind = prefered_woman_ind;  // the wife ind of the new man will be the index of prefered woman
                women[prefered_woman_ind-1].husband_ind = new_man_ind; // the prefered womans husband will be the index of the current man. 
//                printf("DEBUG: Woman %d is paired with  %d\n", prefered_woman_ind, new_man_ind);
//                sleep(1);
            }
            else if (  new_pref<old_pref )   // if the woman preferes the new man over her current parner
            {       
                women[prefered_woman_ind-1].husband_ind = new_man_ind;  //The index of the husband of the prefered woman will be the index of new man 
                men[new_man_ind-1].wife_ind =  prefered_woman_ind;  //The index of the wife of the new man will be the index of prefered woman
                men[old_man_ind-1].wife_ind = -1; // the wife index of the prefered womans old partner will be -1   
                push(men_stack , &men[old_man_ind-1]); // the old man will be added to the stack.
//                printf("DEBUG: Woman %d is prefers %d over %d\n", prefered_woman_ind , new_man_ind , old_man_ind);
//                sleep(1); 
                
            }
            else{ // if none of the conditions above are fullfilled
                push(men_stack , &men[new_man_ind-1]); // add the new man to the stack so he can propose to the next woman in his preference list.
//                printf("DEBUG: Woman %d rejects man %d\n", prefered_woman_ind, new_man_ind);
//                sleep(1);
            }

        }
        free(men_stack->men_array);  // Free the memory for the men array
        free(men_stack);

    }

void free_allocated_mems(man* men , woman* women , int n){

        for (int i = 0; i < n; i++) {
        free(men[i].preferences);
        free(women[i].preferences);
        }
        free(men);
        free(women);

}

int main(){

    int n; //Number of pairs

    scanf("%d" , &n); // we read the first value and store it in n
    //allocate memory for 'men' and 'women'
    man* men = (man*)malloc(n * sizeof(man));
    woman* women = (woman*)malloc(n * sizeof(woman));
    int * index_plus_preferences = (int*) malloc(sizeof(int)* (n+1)); // this array will contain both index and preference. 
    //we loop over the men and women array and initialize some parameters. 
    if (index_plus_preferences == NULL){
           perror("Memory allocation for preferences failed!");
        return 1;
    }

    for (int i = 0 ; i<n ;i++){
        men[i].visited=0;
        men[i].wife_ind = -1 ; 
        women[i].visited = 0;
        women[i].husband_ind = -1 ; 


    }
    // We know that there is 2*n rows in the data set. 
    
    read_input(men , women , index_plus_preferences , n);
    free(index_plus_preferences);
    // we invert each womans preference list 
    for (int i = 0 ; i<n ; i++){
        inverted_pref_list(women[i].preferences , n);
    }
    find_matches(men , women , n);
//        print_preferences(men , women , n); //uncomment this if you want to see preferences and the data for men and women
    print_husbands(women,n);


        
        return 0;

    }   



