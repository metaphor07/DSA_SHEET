# Pattern: Interleaving String

## State
```text
dp[i][j] = true if s3[0...i+j-1]
can be formed using s1[0...i-1] and s2[0...j-1]
```

## Transition
```text
Take from s1 if s1[i-1] == s3[i+j-1]
Take from s2 if s2[j-1] == s3[i+j-1]
```

## Memory hook
s3 index = i + j - 1.
