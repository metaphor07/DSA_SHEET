# Pattern: Union Find / DSU

## Core idea
```text
find(x) returns ultimate parent.
union(a, b) connects two components.
If find(a) == find(b), they are already connected.
```

## Memory hook
Same parent means same component.
