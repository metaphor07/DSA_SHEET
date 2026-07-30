# Pattern: Longest Common Subsequence

```text
If same char: 1 + dp[i-1][j-1]
Else: max(dp[i-1][j], dp[i][j-1])
```
