## Shortest path algorithm: 

In this types of problems we look att directed graph with weights. So each edge have a weight in this problem formulation the weights are positive if weights are less than 0 the greedy algorithm is not anough. 


**Dijistras Algorithm**
Dijistras algortihms is a greedy algorithms that findes the shortest path in weighted graph. 

Here are some properties of Dijstras Algrotihm.

- It greedy 
- Every node have a parameter d(v) which is the shortest path from start to that node. 

- It needs two sets, one for the node where their distans to start node is know we call it S and the other one containing the nodes where we dont know their distance to start node  we call it Q .

- From the beginning we have S ={s} , d(s)= 0. 

- Each node have a pred, which is the node we came from. 