
import fileinput
import numpy as np

from collections import deque 

    
def propose(m, w):
    if w.Man == 0:
        w.Man = m
        return None
      
    elif w.prio[m.num]<w.prio[w.Man.num]:
        old_man = w.Man
       
        w.Man = m
        return old_man
    else:
        return m

class  Man:
    def __init__(self, num, prio):
        self.num = num
        self.prio = prio

class Woman:
  def __init__(self, num, prio, Man):
    self.num = num
    self.prio = prio
    self.Man = Man
  
w = Woman(1, (1, 2), 0)



# num_pairs = int(input("Hur många par?"))


  # inp = input("Ange individ (nummer och preferenser) på formen 'x y ... z' ")
# inp_tot = input()

inp_tot = ""
for line in fileinput.input():
    inp_tot += line


# testvek
# 2 1 2 1 2 1 2 2 2 1 1 1 2


# inp = np.array(list(map(int,inp.split())))-1 

inp_tot =  list(map(int,inp_tot.split()))

num_pairs = inp_tot[0]
men = []
women = list(np.zeros(num_pairs))
gender = list(np.zeros(num_pairs))
inp_tot = [x-1 for x in inp_tot]

#sparar som arrayobjekt och tar -1 för att nummer ska matcha index i vektor
for i in range(num_pairs*2): #för varje par, precis som innan
    inp = inp_tot[1+i*(num_pairs+1):1+i*(num_pairs+1)+num_pairs+1]

    num = inp[0]

    if gender[num] == 0:
        gender[num] = 1
        prio_old = inp[1:num_pairs+1]      
        prio_new = prio_old.copy()
        # Låter lågt tal betyda hög prio (motsv lågt index hos män)
        for j in range(num_pairs):
            prio_new[prio_old[j]] = j
        
        w = Woman(num, prio_new, 0)
        women[num] = w #Insatta på 'rätt' plats
    else:
        m = Man(num, deque(inp[1:num_pairs+1]))
        men.append(m)
#Ovan sorteras input. O(n) par loopas över och O(n)
# omordningar sker för kvinnor -> O(n^2)  
    #Nu börjar frierierna
    
#Varje man kan max fria n ggr, frieri tar pga omordning endast 1 jämförelse 
#(både man och kvinna vet vem de ska jämföra med). n män ger O(n^2) operationer
        
while ((men)):
    m = men.pop();
    c = m.prio.copy()
    
    for num in c:
    # for num in m.prio:
        m.prio.popleft()
        m_p = propose(m,women[num])
    
        if  m_p==None:
    
            break
        elif m_p != m:
            men.append(m_p)
            
            break
        
for i in range(num_pairs): 
     print (women[i].Man.num+1)   
