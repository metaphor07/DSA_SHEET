# Pattern: Topological Sort using Indegree

## Use when
There are prerequisites or dependency ordering.

## Course Schedule interpretation
For `[a, b]`:

```text
To take a, first take b.
Edge: b -> a
```

## Memory hook
Course with indegree 0 can be taken. If all courses are taken, no cycle exists.
