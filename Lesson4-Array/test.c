# include <stdio.h>

int * bubble_sort(int * array , int size ){

    for (int i = 0 ; i< size; i++){
        int swap_happend = 0;
        for (int j = 0 ; j < size-1 ; j++){
            int left = array[j];
            int right = array[j+1];
            if  (left >right){
                swap_happend = 1;
                array[j] = right;
                array[j+1] = left;
            }
        }
        if(swap_happend == 0){
            return array;
        }
    }
    return array;
}

void run_bubble_sort(){
    int array [] = {2,3,6,1,1,1,1,1,8,7,0,9};

    int * sorted = bubble_sort( array , sizeof(array)/sizeof(array[0]));

    for (int i = 0 ; i < sizeof(array)/sizeof(int) ; i++){
        if (i==0){
            printf("\n[%d," , sorted[i]);
        }
        else if (i== sizeof(array)/sizeof(int)-1){
            printf("%d]" , sorted[i] );
        }
        else{
           printf("%d," , sorted[i]); 
        }


    }
    
}

void string_print( char *string){
    printf("%s" , string);
}

void int_array_print( int *array , int size){
    for (int i =0 ; i < size ; i++){
        if(i == 0){
        printf("[%d," , array[i]);            
        }
        else if (i == size-1){
         printf("%d]" , array[i]);           
        }
        else {
        printf("%d," , array[i]);
        }

    }
};

int main(){
    int array [] = {1,2,3,4,5,67,34,2,1};
    /*
    
    char str [] = "Hello World!";
 //   string_print(str);
        int_array_print(array , sizeof(array)/4);
    */

    int *  p_arr = array;
    
    printf("%d" , *(&p_arr[2]+3));


        return 0;
}