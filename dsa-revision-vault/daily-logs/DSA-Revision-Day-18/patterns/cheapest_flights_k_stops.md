# Pattern: Cheapest Flights Within K Stops

This is not plain Dijkstra.

## State
```text
cost, node, stops
```

## Memory hook
Same node can be reached with different stops,
so stops must be part of the state.
