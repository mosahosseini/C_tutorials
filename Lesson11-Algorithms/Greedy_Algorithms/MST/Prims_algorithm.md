# Prims Algorithm Structure

## heap.h 
Here we defined the heap itself. 

* Heap_t contains a pointer to a comparator function. This function return an int. 

* Then we have another function pointer which is position. It returns the position of the element in the heap.  

* the variable i is the current index of the heap. 

* the variable n is the size of the heap. 

* a is an array that we use as heap. 

## new_heap

* The arguments to this method is n which is size of the heap , the pointer to a function to compare two objects , a pointer to a function that return the position to the element. 

* Allocates and initializes a new heap structure with space for n elements.

* This heap is generic and can be used to store pointers to any type of element.

* It will return heap_t*.

## swap

* The argument to the function is a pointer to the heap , and the position i respective j. 

* It swap the element in the indecies i ,j. 

## up

* The arguments to this method is a pointer to the heap. The second argument and index to the element that we want to move up. 

## down

* The arguments to this method is a pointer to the heap. The second argument and index to the element that we want to move down. 

## init_heap
* He arguments to this method is a pointer to the heap. Pointer to the first element in the array. s is the size of each element in the array. 


## heap_insert 

* The arguments to this method is a pointer to the heap, and x is the element that we want to insert. 

## heap_size

* The arguments to this method is a pointer to the heap.

* The return the size of the heap.


## heap_min

* The arguments to this method is a pointer to the heap.

* It returns the minimum element of heap and NUll if the heap is empty. 

## heap_change_position

* The arguments to this method is a pointer to the heap, and the element we want to change position. 



## Result

### How to check solution: 
To check only 1 input file. 

compile the code using:
```c
gcc prims_algorithm.c -o prims_algorithm
```

Then in cmd you can write: 

```
./prims_algorithm < data/sample/1.in
```

If you want to check all test cases you can do: 
It is important that the check solution.sh is in the same directory as the files. 

```c
time bash check_solution.sh ./prims_algorithm
```
For c we got $\approx 6s$: 
```
real    0m10.787s
user    0m5.518s
sys     0m0.548s
```

For python you can run: 

```txt
time bash check_solution.sh python3 make_friend.py
```

The result is $\approx 44s$: 

```txt
real    0m43.771s
user    0m43.666s
sys     0m6.320s
```