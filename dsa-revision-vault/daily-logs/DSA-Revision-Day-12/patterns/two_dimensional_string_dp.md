# Pattern: 2D String DP

## Longest Common Subsequence

### State
```text
dp[i][j] = LCS length of text1[0...i-1] and text2[0...j-1]
```

### Transition
```text
if text1[i-1] == text2[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

## Memory hook
Same char -> take both.  
Different char -> skip one side.
