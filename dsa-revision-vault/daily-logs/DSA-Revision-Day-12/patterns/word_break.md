# Pattern: Word Break

## Problem type
Cut-based DP.

## Memoization state
```text
dp[start] = whether s[start...n-1] can be segmented.
```

## Tabulation state
```text
dp[i] = true if s[0...i-1] can be segmented.
```

## Transition
```text
dp[i] = true if:
dp[j] == true
and
s[j...i-1] exists in dictionary
```

## Memory hook
Try every cut.
Left part must already be valid.
Right part must be a dictionary word.
