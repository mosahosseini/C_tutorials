# Table Of Content 


# 1 Lists
## 1.1 Why Lists? 
The advantages of lists are flexiblity compared to Arrays. There are different variants of linked list. 

1. Simple Linked Lists (only a pointer to next node) 
2. Double Linked Lists (A pointer to next node and another to previous node)
3. Cirkular Liked Lists (A double linked list wher the last nodes next points to first node and the first nodes previouse node points to Last node)


### 1.1.1 Time Complexity Analysis Of Simply Linked List
It is the simplest form of linked list where the Node have a pointed to next. 

* **Adding an element:**
When we add an element, we need to traverse the double linked list until we read the last node and add the element at the end of the list. which means that we need to traverse over n element to reach the last. So adding an element to a linked list will have a complexity of `O(n)`.

<font color = green> **We can make simple linked list to have constant time complexity for adding an element if we can add a pointer that keeps track of last element in the array. In that way, adding an element will have constant time `O(1)`complexity** </font>

* **Removing an elemnt:** 
Removing an element from the array will have a complexity of **O(n)**

### 1.1.2 Time Complexity Analysis Of Doubly Linked List
* **Adding an element:**
When we add an element, we need to traverse the double linked list until we read the last node and add the element at the end of the list. which means that we need to traverse over n element to reach the last. So adding an element to a linked list will have a complexity of `O(n)`.

<font color = green> **Similarly, if we create a pointer that keeps track of the last node it will cost constant e.g `O(1)`time to add an element to the last node** </font>

* **Removing an elemnt:** 
If we need to search for the element that needs to be removed we need to traverse the list and it will take in worst case **O(n)** if the element is not the head.

<font color = green> **But IF we have direct access to the node, we can remove it in constant time e.g `O(1)`because it already have a pointer to the previouse respective next element let's assume that we want to remove node that are called `node_m`** </font>
we can remove `node_m`by using: 
```c
node_m.prev.next = node_m.next;
node_m.next.prev = node_m.prev;
free(node_m)
```

### 1.1.2 Time Complexity Analysis Of Cirkularly Linked List
* **Adding an element:**
When using the cirkular linked list, we already have a pointer to the last element, which is the first nodes previouse node. Because of that if will cost 'O(1)' to add an element to cirkular linked list.

* **Removing an elemnt:** 
If we need to search for the element that needs to be removed we need to traverse the list and it will take in worst case **O(n)** if the element is not the head or tail. 

<font color = green> **IF we have direct access to the node, we can remove it in constant time e.g `O(1)`.** </font>


## 1.2 Lists vs Arrays
So the milion dollar question is which one is the best, list or array? Well, there is more to that question that meets the eyes. 
### Advantages Of List: 
1. Lists are more flexible, which means that you don't need to have a predefined size for the list.

2. Disadvantages of Lists are that they takes more place (memory) and also takes more time to traverse. The reason to this have to do with chache memory and optimize compilers. 

# 2 Binary Search Trees 
Is a tree structure where each node contains the followings: 
1. Key
2. Value
3. Left child
4. Right child

The tree is build such that all nodes to the left side of the node have lower key that the node itself and all nodes to the right side of the node have a higher key that the node itself. 

The binary trees are very efficient, but when they are balanced . If they are not balanced they will look like a SLL and we waste memory on the unused childrens. Look at the example below.
![alt text](image.png)

The question is how we can balance a tree? We can make the tree to balance itself if we use an algorith. 

- The algorithm is called AVL 
- Called after 2 soviet matematician. Aelson-Velsky and Landin. 
- It have the ability to balance itself in every insertion and deletion . 
- Seaching in AVL tree will take a time complexity of `Ò(logn)`
- It have an additional attriute in each node: `int h = hight_left - hight_right` this additional attribut only need two bites because `h = {0,-1,1}` 
To devel deeper into AVL algotihm we need to get familiar with right and left rotation. Right rotation is when we let the right child be the root and vice versa for left rotation. 

![alt text](image-1.png)


We rotate untill the difference between right and left node is maximum 1. 

In similar way, we can have a double rotation to the left or right. 
![alt text](image-2.png)


# Graphs 
