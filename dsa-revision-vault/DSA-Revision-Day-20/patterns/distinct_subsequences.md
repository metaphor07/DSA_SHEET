# Pattern: Distinct Subsequences

## State
```text
dp[i][j] = number of ways to form t[0...j-1]
using s[0...i-1]
```

## Transition
```text
If s[i-1] == t[j-1]:
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
Else:
    dp[i][j] = dp[i-1][j]
```
