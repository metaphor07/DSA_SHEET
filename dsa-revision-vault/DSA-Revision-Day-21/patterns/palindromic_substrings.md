# Pattern: Palindromic Substrings

## DP state
```text
dp[i][j] = true if s[i...j] is palindrome
```

## DP transition
```text
if s[i] == s[j] and (len <= 2 or dp[i+1][j-1]):
    dp[i][j] = true
```

## Memoization
```text
solve(i,j):
    if i >= j return true
    return s[i] == s[j] and solve(i+1,j-1)
```
