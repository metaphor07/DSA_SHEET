# Q4 Notes - Minimum Time With Power Constraint

Pattern:
weighted directed graph + shortest path + limited resource

State:
(node, remainingPower)

Transition:
From node u with power p:
- can leave only if p >= cost[u]
- after leaving, newPower = p - cost[u]
- edge adds time

Why not plain Dijkstra on node only?
Because reaching the same node with different remaining power leads to different future possibilities.

So use:
dist[node][remainingPower]
