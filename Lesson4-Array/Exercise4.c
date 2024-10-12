#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
- Implement linear search and binary search
- Implement bubble sort
- Reverse a string
*/

// Linear Search
// I want to implement it using pointer
int *linear_search(float *array, float element, int size, int *resultSize);
int binary_search(int *array, int element, int start, int end);

int *linear_search(float *array, float element, int size, int *resultSize)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            count++;
        }
    }

    if (count == 0)
    {
        printf("No such element found!\n");
        return NULL;
    }

    int *p_indexes = malloc(count * sizeof(int));
    *resultSize = count;
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            //            printf("count : %d \n", count);
            p_indexes[count] = i;
            count++;
        }
    }
    return p_indexes;
}

int binary_search(int *array, int element, int start, int end)
{
    /*
    Binary Search is a bit special. For it to work, the input array must be sorted. given a sorted input array it can find the elements in constant time.

    first we implements it so that i find only index of 1. Which means we assume arrays elements are unique , then we can build upon it so that it returns an array of indecies.

    Algorithm:
    - 1. Find the middle of the array.
    - 2. Initiate 3 pointers , left ,mid right : array = [1,2,3,4,5,6,7]   - left = 1 , mid = 7  , right = 7   :  searched_element = 6
    - 3. If searched_element> left and  searched_element <= mid :  right = mid ,  mid = (int) (index(left)+ index(mid))/2
    - 4. If searched_element> mid and  searched_element <= right :  left = mid+1 ,  mid = (int) (index(mid)+ index(right))/2
    - 5. If left ==mid or right == mid  return index.

    */
    int mid = (int)(end + start) / 2;

    if (start == mid || end == mid)
    {
        return mid;
    }

    else
    {
        if (element >= array[start] && element < array[mid])
        {
            return binary_search(array, element, start, mid);
        }

        if (element >= array[mid] && element <= array[end])
        {
            return binary_search(array, element, mid, end);
        }
    }
}

void print_array(float *array, int size)
{

    for (int i = 0; i <= size - 1; i++)
    {

        if (i == 0)
        {
            printf("\n [%.1f , ", array[i]);
        }
        else if (i == size - 1)
        {
            printf("%.1f]", array[i]);
        }
        else
        {
            printf("%.1f , ", array[i]);
        }
    }
}

void run_linear_search()
{
    float array[] = {3, 5, 7, 8, 12, 14, 13, 14, 19, 20, 37, 44, 56};
    int searched_element = 14;
    printf("Example array is: ");
    print_array(array, sizeof(array) / sizeof(float));
    printf("\n We are searching for element: %d\n ", searched_element);
    int resultSize;
    int *p_indexes = linear_search(array, searched_element, sizeof(array) / sizeof(float), &resultSize);

    printf("answer: [");
    for (int i = 0; i < resultSize; i++)
    {
        if (i == resultSize - 1)
        {
            printf("%d", p_indexes[i]);
        }
        else
        {
            printf("%d,", p_indexes[i]);
        }
    }
    printf("]\n\n");
}


void run_binary_search(){
    int array[] = {3, 5, 7, 8, 12, 14, 13, 19, 20, 37, 44, 56};
    int size = sizeof(array) / sizeof(float);
    int searched_element = 14;
    printf("Example array is: ");

    for (int i = 0; i <= size - 1; i++)
    {

        if (i == 0)
        {
            printf("\n [%d , ", array[i]);
        }
        else if (i == size - 1)
        {
            printf("%d]", array[i]);
        }
        else
        {
            printf("%d , ", array[i]);
        }
    }
    
    printf("\n We are searching for element: %d\n ", searched_element);

    int ind = binary_search(array, searched_element , 0 , size-1);

    printf("answer: index of the searched element is: %d \n\n" , ind);



}



int main()
{
    //run_linear_search();
    run_binary_search();
}