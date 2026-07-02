# Q4 Intuition - Find Edges in Shortest Paths

Run Dijkstra twice:

1. From source 0:
   distFromStart[x] = shortest distance from 0 to x

2. From target n-1:
   distFromEnd[x] = shortest distance from x to n-1

Let shortest = distFromStart[n-1].

For an undirected edge (u, v, w), it is part of some shortest path if either:

distFromStart[u] + w + distFromEnd[v] == shortest

or

distFromStart[v] + w + distFromEnd[u] == shortest
