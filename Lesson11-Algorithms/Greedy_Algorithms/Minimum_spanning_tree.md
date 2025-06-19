# Minimum spanning tree: 
Assum that we have an undirected graph `G(V,E)` , whith weights $\omega (e) > 0$ , $e \in E$ , choose a subset of E $E´ \subset E$ so that $G(V,E´)$ is connected and $min(\sum_{e \in E} \omega (e)) = \sum_{e\in E´} \omega (e) $ 

# Solutions 

## 1. Prims Algorithm 
- similar to dijkstras algorithm, it has a priority queue at each which cost set to infinity except for the start node which has cost 0.
- While the queue is not empty. 
- remove min , look at the mins children if the the weights are smaller that cost, set cost to weight. Set visited = true.


## 2. Kruskals Algorithm: 

1. First sort all edges based of weight in ascending order. 
2. Take the smalles edges for which we dont get a cycle. 
3. Go to 2. 

So the question is how do we detect a cycle? 