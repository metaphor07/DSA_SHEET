# Pattern: Topological Sort

## Kahn's Algorithm
```text
1. Build graph.
2. Count indegree.
3. Push all indegree 0 nodes.
4. Pop node, add to order.
5. Reduce indegree of neighbors.
```

## Memory hook
Indegree 0 = no remaining prerequisite.
