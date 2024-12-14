# Matching
We have two set X and Y, each with n element. A match is a pair of element from X and Y. 

```math
M = \{(x,y) : x \in X , y \in Y \}.
```
M is a matching. If |M| = n, we say the matching is perfect. 

# Stable Match
If the pairs are fairly satisfied with their pairing.It is called an stable matching. 

## Ralistic Example, Stable 
Imagine there is a dance party and we have the following men and women in the club. 

men= {Toke , Orm }

Women = {Ylva , Ingrid}

These individs have different preferences. 

Orm : Ylva , Ingrid 

Toke : Ylva , Ingrid 

Ylva : Orm , Toke 

Ingrid: Toke , Orm

Orm likes prefers to dance with Ylva and if it is not possible , he can danse with ingrid. The question is , what is an stable match in this case. It doesn't mean every body is happy but rather there is nobody who wants to chage their partner and build a new pair. 

### An example of non stable match is: 

{(Orm , Ingrid) , (Toke , Ylva)}

Because Orm and Ylva both are their eachothers first choice , they will break the current mathing and build a new pair. This pairing is perfect , because every one is included, but it is not stable. 


### An example of Stable matching is: 

{(Orm , Ylva) , (Toke , Ingrid)}


## Dave Shapleys Algorithm
Dave Shapleys Algorithm finds a stable matching ![alt text](image.png)

Lets go through the algorithm. 

1. Add all men to a list of unproposed men p 
2. while p is not empty.
3. Pick a man, m  from p and look at his preference list.
4. Pick the woman,w which he preferes the most and is not yet proposed to. 
5. If the woman he picked is not proposed to and is free , they will become a pair. 
6. Else if she prefes this m over her current partner, then she will build a new pair with the man (m,w) and the old pair (mw, w) is removed. and Add mw to p.
7. is non of the condition above are satisfied, add m to p. 



## Example of Dave Shapely algorithm

Each person if give a number. 

Men: <br />
1. Orm
2. Toke

Women: 
1. Ylva 
2. Ingrid

Preference Lists

Orm:  1,2 <br />
Toke: 1,2

Ylva:   1,2 <br />
Ingrid: 2,1

The first rule is that it is the men who are proposing. So we need a list of men who haven't proposed yet. 

P = [1,2]

Things we need: 
* Each men have a list of preferences , in other words, list of womens he wants to ask for dance. 
* Each woman have a list of preferences. 
* Each men shoule know in which index he is standing . For example Toke shoule know the he has the index 2. 
* Womens preference list must be in inverted order. 

### Why inverted order for women ?

To understand why inverted order for women is needed let's analyze time komplexity. 

1. To pick a man from the p list (the list of the men who havent proposed yet.) is O(1)
2. To to through the mans preferences will take O(n)
3. If a man want to know where in the preference list of the woman he proposing to he is, he needs to go through the (in ordered) womens preferences which will take O(n). 

If we use the inverted preferences for wormen the time komplexity for a man to know where in the preference list of the women he propose to he is will only be a constant. 


### Inverted order

Imagine we have a list of men: 
1. Orm
2. Toke
3. Are 
4. Krok

The Woman named Anna have the following prefenreces: 

Anna = [3,2,4,1]

In this order, the indecies means the preference and the value is the indices of man. 

In the inverted preference list, we indicies are the indices of men and the value is her preferences. 

Anna = [4,2,1,3]

This means man in the index 1 which is Orm. have the preference 4. 


In this case, if Krok  wants to know wher in the preference of Anna he is. He can simply write his own index, which is 4 in the preference list of Anna and  Anna[4] = 3 , which means He is the third prefered partner for anna. 

