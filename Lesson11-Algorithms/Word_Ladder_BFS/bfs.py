# -*- coding: utf-8 -*-
# import time
import fileinput
from collections import deque 

class Node:
    def __init__(self,string,pred,arcs , ind):
        self.pred = pred
        self.string = string
        self.arcs = arcs
        self.ind = ind


def ssplit(word):
    return [char for char in word]
                    
        
def make_graph(G): #Här har vi 4 loopar men de innre looparna körs max konstant antal gånger. 
    for n1 in G:
        for n2 in G: 
            if n1 != n2 :
                word = ssplit(n2.string)
                word = ssplit(n2.string)                              
                for c in range (1,5):
                    c1 = n1.string[c] #För varje char index 1-4 i första nodens ord
                    found = False
                    for c2 in word:
                        if c1 == c2:
                            found = True
                            break
                    if not found:
                        break
                    word.remove(c1) #If found we remove the char from word  and its ok because word has constant length.
                if found: #Kommer bara vara sann efter loopen ovan om alla 4 c1 gått genom
                    n1.arcs.append(n2)


def find_lepath(narc,ns): # hittar längden av vägen mellan narc och ns (tc=O(n))
    n = narc
    step_counter = 1
    if narc == ns:
        return 0
    while n.pred != ns:                   
        step_counter += 1
        n = n.pred
    return step_counter



#node_start, end_string, Number of nodes in graph

def search (ns,e,N):        #har tc=O(n^2)  while loopen körs max n gånger och forloopen 
#som finns inuti while loopen körs max n ggr. find_lepath körs bara 1 gång. 
 
    
# Metoden hittar kortaste vägen från start till slutnod och returnerar antal steg eller "impossible " om vägen saknas.    
    if ns.string == e:
        return 0
    ns.pred = ns
    nio = deque([ns]) #"nodes in order"     
       
    
    while nio:      
        n = nio.popleft()
        for narc in n.arcs:      #o(n+2m+n) 
            if narc.pred == None:
                narc.pred = n
                nio.append(narc)
                if narc.string == e:
                    return find_lepath(narc,ns)
      
    return "Impossible"
        
    #         if n.string == e:
    #             return d
    #        


def find_node (G,s): #Metoden hittar noden med strängen s i grafen G.  tc=O(n)
    for n in G:
        if n.string == s:
            return n
    return None

def clear_pred (G):
    for n in G:
        n.pred = None
        


  
# N=int(inp_tot[0])
# Q=int(inp_tot[1])


inp_tot = ""


# for line in fileinput.input():
#     inp_tot += line

with open("3medium1.in" , "r") as f:
    inp_tot = f.read()

inp_tot =  inp_tot.split()

[N, Q] = list(map(int,inp_tot[0:2]))


graph = []
que = []

for i in range(2,N+2):
    graph.append(Node(inp_tot[i],None,[] , i-2))


make_graph(graph)

for j in range(N+2,len(inp_tot),2):
    s = inp_tot[j]
    e = inp_tot[j+1]
    ns = find_node(graph,s)
    print (search(ns, e, N)) 
    clear_pred(graph)


print([n.ind for n in graph[58].arcs])









