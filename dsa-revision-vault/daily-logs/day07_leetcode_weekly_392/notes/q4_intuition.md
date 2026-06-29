# Q4 Intuition - Minimum Cost Walk in Weighted Graph

Problem pattern:
Undirected weighted graph + many queries + walk can repeat nodes/edges.

Important observation:
Since it is a walk, not a simple path, inside one connected component you can move around and include extra edges.

For bitwise AND, adding more edges can only keep the value same or decrease it.

So the minimum possible cost between any two nodes in the same connected component becomes:

bitwise AND of all edge weights in that connected component.

Therefore:
1. Use DSU to find connected components.
2. For every edge, AND its weight into that component's value.
3. For each query:
   - if source and target are in different components, answer is -1
   - else answer is componentAnd[root]
