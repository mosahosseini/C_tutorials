#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


typedef struct {
int index; 
int * preferences;
int visited; 
int husband_ind; 
}woman;

void inverted_pref_list(int * pref_list , int n){
    int temp_array [n]; 
    int ind ; 
    int val ; 
    for (int i = 0 ; i<n ; i++){
        ind = pref_list[i];
        val = i+1;
        temp_array[ind-1] = val; 
    }

    for (int i = 0 ; i<n ; i++){
        pref_list[i] = temp_array[i]; 
    }

}

int* copy_preferences(int* pref_plus_ind , int n){
    int * only_prefs = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i<n; i++){
        only_prefs[i] = pref_plus_ind[i+1];
    }
    return only_prefs;

}


int main(){

    int n; //Number of pairs
    FILE* file = fopen("data/sample/3.txt", "r") ;
    if(file == NULL){
        perror("File opening failed");
        return 1 ; 
    } 
    fscanf(file,"%d" , &n);
    
    // Dynamically allocate memory for 'men' and 'women'
    man* men = (man*)malloc(n * sizeof(man));
    woman* women = (woman*)malloc(n * sizeof(woman));
    for (int i = 0 ; i<n ;i++){
        men[i].visited=0;
        men[i].wife_ind = -1 ; 
        women[i].visited = 0;
        women[i].husband_ind = -1 ; 


    }
    for (int i = 0 ; i<2*n ; i++){
        int * index_plus_preferences = (int*) malloc(sizeof(int*)* (n+1));
         if (index_plus_preferences == NULL){
            perror("Memory allocation for preferences failed!");
            return 1;
        }
        int test ;
        for (int j = 0 ; j< n+1 ; j++ ) {
            //fscanf(file,"%d" , &index_plus_preferences[j]);
            fscanf(file,"%d" , &test);
            index_plus_preferences[j] = test;
        }
        
        int ind = index_plus_preferences[0]-1;
        
        
        if (women[ind].visited){
            men[ind].index = ind+1; 
            men[ind].preferences = copy_preferences(index_plus_preferences, n);
            men[ind].visited = 1 ;
            men[ind].proposed_ind = -1; 
            free(index_plus_preferences);

        }else{
            women[ind].index = ind+1;
            women[ind].preferences = copy_preferences(index_plus_preferences, n);
            women[ind].visited = 1 ;
            free(index_plus_preferences);
        }

        }

        for (int i = 0 ; i<n ; i++){
            inverted_pref_list(women[i].preferences , n);
        }

        printf("\n\n\n");
        for(int j = 0 ; j <n ; j++){
            
            printf("man %d pref:" , j+1);
            for (int i = 0 ; i <n ; i ++){
                printf(" %d", men[j].preferences[i]);
            }

            printf("\n");
            printf("woman %d pref:" , j+1);
            for (int i = 0 ; i <n ; i ++){
                printf(" %d", women[j].preferences[i]);
            }
            printf("\n");
        }

        // add all men to the stack. 
        STACK * men_stack = init_stack(n);
        for (int i = n-1 ; i>= 0  ; i--)
        {
            push(men_stack , &men[i]);
        }



        //////
        // Node * head = init_head( &men[0]);
        // for(int i = 1 ; i<n ; i++){
        //     add(&head , &men[i]);
        // }
        int prefered_woman_ind ; 
        
        // 



        while (!is_empty(men_stack)){
            int new_man_ind = pop(men_stack)->index; 
            int old_man_ind;
            int pref_ind ; 

                pref_ind = ++men[new_man_ind-1].proposed_ind ; 
                prefered_woman_ind = men[new_man_ind-1].preferences[pref_ind];
                old_man_ind = women[prefered_woman_ind-1].husband_ind;
                int new_pref = women[prefered_woman_ind-1].preferences[new_man_ind-1];
                int old_pref =  women[prefered_woman_ind-1].preferences[old_man_ind-1];


                
                if (old_man_ind == -1 ){ // if prefered women is not proposed to
                    men[new_man_ind-1].wife_ind = prefered_woman_ind; 
                    women[prefered_woman_ind-1].husband_ind = new_man_ind;
 
                }
                else if (  new_pref<old_pref )
                {
                     women[prefered_woman_ind-1].husband_ind = new_man_ind; 
                     men[new_man_ind-1].wife_ind =  prefered_woman_ind;
                     men[old_man_ind-1].wife_ind = -1;  
                     push(men_stack , &men[old_man_ind-1]);


                }
                else{
                    push(men_stack , &men[new_man_ind-1]);

                }
        }
        for (int i = 0 ; i<n ; i++){
            printf("woman %d is paired with man : %d \n" , women[i].index , women[i].husband_ind );
        }






        



        



        free(men);
        free(women);
        return 0;





    }   





// }


