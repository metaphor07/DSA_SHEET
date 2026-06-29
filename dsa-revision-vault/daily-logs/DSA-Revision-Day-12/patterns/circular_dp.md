# Pattern: Circular DP

## House Robber II

Because first and last houses are adjacent, solve two linear cases:

```text
case1 = rob houses 0 to n-2
case2 = rob houses 1 to n-1
answer = max(case1, case2)
```

## Memory hook
Circular robber = break circle into two linear robber problems.
