# Pattern: Perfect Squares

State:
```text
solve(n) = minimum number of perfect squares needed for n
```

Transition:
```text
solve(n) = 1 + min(solve(n - square))
```

Base:
```text
solve(0) = 0
```
