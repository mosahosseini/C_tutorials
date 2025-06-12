
import fileinput
from collections import deque
import numpy as np
# import numpy as np

# from collections import deque 

class Edge:
    def __init__ (self, n1,n2,w):
        self.n1 = n1
        self.n2 = n2
        self.w = w

class Node:
    def __init__ (self,pred,num,h):
        self.pred = pred
        self.num= num
        self.h = h

def get_w(Edge):
    return Edge.w

def find(n):
    while n.pred!=None:
        n=n.pred
    return n    

#Tar en edge och kopplar samman dess noder om det ej blir loop, returnerar i så fall vikten
def join (e):  # Om den enas höjd är större än den andra så kopplar vi den som är minst till den som är störst och då bevaras höjden.
    n1 = e.n1
    n2 = e.n2

    r1 = find(n1)  
    r2 = find(n2)
    
    if r1 == r2: #ends the method call if its a cycle (same root)
        return 0
    
    if r1.h>r2.h:
        r2.pred = r1
    elif r2.h> r1.h:
        r1.pred = r2
    else:              # om de har samma höjd så ska en av de bli rot och höjden ökar med 1 
        r2.pred = r1
        r1.h += 1
    return e.w
    
    
    
    
#nas = []  # nodes at start. contains all nodes in the beginning  

edges = []   
        
inp_tot = ""
for line in fileinput.input():
    inp_tot += line

inp_tot =  deque(map(int,inp_tot.split()))

N = inp_tot.popleft() #Number of nodes

nodes =list( np.zeros(N))

M = inp_tot.popleft() #Number of edges

while inp_tot: #loops over all edges
    num = inp_tot.popleft()
    if nodes[num-1] == 0: #So we only create nodes with the same num once
        nodes[num-1] = Node(None, num, 1)
    n1 = nodes[num-1]
    
    num = inp_tot.popleft()    
    if nodes[num-1] == 0:        
        nodes[num-1] = Node(None, num, 1)
    n2 = nodes[num-1]
    w = inp_tot.popleft()
    
    edges.append(Edge(n1, n2, w))
    
edges.sort(key = get_w) #Sorts edges by weight, time complexity  O(nlogn)

pathsum = 0
count = 0
for k in range(len(edges)):
    edge = edges[k]
    w = join(edge)
    if w > 0: #We can only have N-1 succesful joinings before all nodes are connected
    #Improves performance if M>>N
        pathsum += w
        count += 1
    if count == N-1:
        break
    
print(pathsum)
    
    




    
