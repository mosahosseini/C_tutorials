#include <stdio.h>
#include <stdlib.h>

typedef struct {
int * preferences;
int visited ; 
}man;

typedef struct {
int * preferences;
int visited; 
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
    printf("\n\nsize of pref_puls ind is: %d ", sizeof(pref_plus_ind)/sizeof(int*) );
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
        women[i].visited = 0;
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
            men[ind].preferences = copy_preferences(index_plus_preferences, n);
            men[ind].visited = 1 ;
            free(index_plus_preferences);

        }else{
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

        free(men);
        free(women);
        return 0;





    }   





// }


