# Pattern: Edit Distance

## State
```text
dp[i][j] = minimum operations to convert word1[0...i-1] to word2[0...j-1]
```

## Memory hook
same char = no cost  
different char = insert/delete/replace
