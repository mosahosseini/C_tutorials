
# 1. Problem formulation: 
we construct a graph where each node represents a five-letter word (the words are not necessarily in the English
dictionary, but consist only of lowercase English letters, a–z). Furthermore we draw an (directed) arc from u to v if all
of the last four letters in u are present in v (if there is more than one of a specific letter among the last four letters in
u, then at least the same number has to be present in v in order for us to draw the edge). For example there is an edge
from ”hello” to ”lolem” but not the other way around. There is both an edge from ”there” to ”where” and the other
way around. There is not an edge from ”there” to ”retch” since ”e” is only present once in ”retch”.
You will be asked to answer a series of queries. For each query you will be given two words, the ”starting”-word
and the ”ending”-word. The task is to find the length of the shortest path from the ”starting” to the ”ending” word for
each query.


# 2. Algorithm: 
In this task we are trying to implement a BSF algorithm to find the shortest path between two nodes (in our case, two words). 

## 2.1 Graph representation. 
Each node should have a node number , a value (which in our case it is a 5 letter word). Each node should keep track of its neighbouring nodes. There are different ways to represent a graph. 

___

**NxN bool matrix**

The first method of representing a graph is a matrix the size of the matrix is nxn where n is the number of nodes in the graph. We then index our nodes, and place a 1 in row i and column i+1 if there is an edge from node with index i to node with index i+1. In the case of undirected graph, this matrix will be symmetric. 

The problem with matrix approach is that when the number of nodes gets large, it need large memory to store this nodes in the matrix. Also we need two nested for loop to write the values into the matrix. So the time complexity for creating the graph is O(n^2)
___

**Array List**

Another way of representing a graph is to put the nodes neigbours in an array list. This method is used if we know that the number of neibours are varying. 

___
**Fixed sized array**

Another approach is to use a usual array to store the neibouring nodes. This is used when we know that each node have fixed size neighbour. 


### 2.1.1 Data structure 

