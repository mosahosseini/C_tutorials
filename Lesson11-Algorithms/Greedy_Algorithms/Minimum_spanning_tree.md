# Minimum spanning tree: 
Assum that we have an undirected graph `G(V,E)` , whith weights $\omega (e) > 0$ , $e \in E$ , choose a subset of E $E´ \subset E$ so that $G(V,E´)$ is connected and $min(\sum_{e \in E} \omega (e)) = \sum_{e\in E´} \omega (e) $ 

# Solutions 
## Prims Algorithm 
- similar to dijkstras algorithm, it has a priority queue
- Criteria is to choose those nodes which is closest to nodes that we already chosen. 
- Start in an arbitrary node s.  