# Pattern: Dijkstra

## State
```text
dist[node] = shortest known distance to node
```

## Rule
Use min heap:
```text
{distance, node}
```

## Memory hook
Always expand the currently closest node.
