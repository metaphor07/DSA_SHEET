# Pattern: Grid DP

## Unique Paths

### State
```text
dp[i][j] = number of ways to reach cell (i, j)
```

### Transition
```text
dp[i][j] = dp[i-1][j] + dp[i][j-1]
```

## Memory hook
Reach current cell from top or left.
