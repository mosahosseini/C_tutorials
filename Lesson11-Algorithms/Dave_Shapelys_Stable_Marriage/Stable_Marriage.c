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
        val = i;
        temp_array[ind] = val; 
    }

    for (int i = 0 ; i<n ; i++){
        pref_list[i] = temp_array[i]; 
    }

}


int main(){

    int n; //Number of pairs
    FILE* file = fopen("data/sample/1.txt", "r") ;
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
            index_plus_preferences[j] = test-1;
        }

        printf("preference: ");
        for(int w = 0 ; w <n+1 ; w++){
            printf(" %d ", index_plus_preferences[w]);
            
        }
        
        int ind = index_plus_preferences[0];
        
        
        if (women[ind].visited){
            men[ind].preferences = &index_plus_preferences[1];
            men[ind].visited = 1 ;

        }else{
            women[ind].preferences = &index_plus_preferences[1];
            women[ind].visited = 1 ;
        }

        }



        for (int i = 0 ; i<n ;i++){
            inverted_pref_list(women[i].preferences , n);
        }


        printf("\n\n");
        for(int j = 0 ; j <n ; j++){
            
            printf("man %d pref:" , j);
            for (int i = 0 ; i <n ; i ++){
                printf(" %d", men[j].preferences[i]);
            }
            printf("\n");
            printf("woman %d pref:" , j);
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


