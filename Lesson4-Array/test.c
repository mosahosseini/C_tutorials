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

int main(){
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
    
    return 0;
}