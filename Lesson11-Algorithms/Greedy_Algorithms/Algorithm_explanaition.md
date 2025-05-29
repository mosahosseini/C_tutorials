# Greedy Algorithms 

## 1. What is Greedy Algorithms? 
A greedy algorithm is an approach that makes the best possible decision at each step based on the current local information, aiming to find a globally optimal solution. It does not reconsider its choices once made, and it works well when local optimal choices lead to a global optimum.



Yes — that’s actually a great **intuition** for how greedy algorithms work, especially if you’re thinking visually or in terms of exploration.

Let’s break it down:

---

### 1.1 Game Analogy:

Imagine you're playing a game where:

* The **map starts out black**, and you can only see what’s immediately around your character.
* At each step, you must choose where to go **based only on what you can currently see**.
* Your goal is to gather the **most resources**, or reach a **goal** as efficiently as possible.
* Once you move, you **can’t go back** or undo your choices.(Have you played the )

---

### 🎯 This Fits the Greedy Algorithm Model Because:

* You **only use local information** — what’s visible or available right now.
* You **don’t know the full picture**, but you still make what seems like the best choice at each moment.
* You **don’t revisit** or adjust earlier decisions based on future information. (think of it as a miner game where you have a lanthern and can only see what is infront of you.)


### 💡 Important Caveat:

Just like in the game, greedy choices might **lead you into a dead end** or a suboptimal path — unless the game/map is structured in a way where **greedy exploration always leads to the best result**.

That’s why greedy algorithms only work well on problems where:

* **Local optimality leads to global optimality**
* The problem has the **greedy-choice property** and **optimal substructure**

---

### 1.2 What is meant by greedy-choice properties? 
With greedy properties we mean that. 
1. You can manke locally optimal choice at each step.
2. These locally optimal choices will lead to global optimum. 


### 2. **Optimal Substructure**

An optimal solution to the problem contains **optimal solutions to subproblems**.

> This also applies to dynamic programming. If the subproblems themselves can also be solved greedily, that’s a good sign.


## 2. Greedy Algorithm will not work for all problems: 
If the Greedy choice properties and optimal substructure is not fullfilled the greedy algorithm will not work. So how can we find out if the greedy algorithm is suitable for our problem. 

### Before writing a greedy algorithm:

1. **Try a few small examples by hand**:

   * Make greedy choices.
   * Check if the result is really the best possible.
   * Try a brute-force solution for comparison.
2. **Ask: If I make a greedy choice now, could it block better options later?**
3. **Prove that greedy works**, if possible:

   * Use a formal proof (exchange argument or contradiction).
   * Or try to reason informally: can you always replace any part of an optimal solution with a greedy one without making it worse?

---


## ✅ Problems Where Greedy Usually Works Well

* **Activity selection** (earliest finishing time)
* **Minimum spanning tree** (Kruskal’s, Prim’s algorithms)
* **Huffman encoding**
* **Fractional knapsack** (but **not** 0/1 knapsack!)
* **Dijkstra’s algorithm** (shortest paths with non-negative weights)
* **Job scheduling with deadlines** (under certain constraints)

---

## ❌ Problems Where Greedy Often Fails

* **0/1 knapsack problem** (greedy doesn’t consider combinations)
* **Traveling salesman problem** (greedy usually gives a poor route)
* **Coin change with non-standard denominations** 
* **Longest increasing subsequence**

---

## 🧠 Rule of Thumb

> **If your problem involves combining or selecting items based on weights, values, or priorities, and you're tempted to “pick the best one available right now,” it's worth trying greedy — but always test or prove it.**

---

