# Mistake Notebook - Day 12

## LC 139 - Word Break
**Status:** Red  
**Pattern:** Cut-based DP / Memoization

### Mistake
I could not identify the cut-based DP pattern.

### Correct intuition
At every index, try every possible word/cut.

For recursion:
```text
Can s[start...n-1] be segmented?
```

For tabulation:
```text
dp[i] = true if s[0...i-1] can be segmented.
```

### Memory hook
```text
Word Break = try every cut.
If left prefix is valid and right substring is a dictionary word, current prefix is valid.
```

### Tabulation transition
```text
dp[i] = true if any dp[j] is true and s[j...i-1] exists in dictionary.
```
