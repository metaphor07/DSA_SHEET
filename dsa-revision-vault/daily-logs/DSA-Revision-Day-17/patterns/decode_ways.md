# Pattern: Decode Ways

## State
```text
dp[i] = ways to decode s[0...i-1]
```

## Transitions
```text
Single digit if s[i-1] != '0': dp[i] += dp[i-1]
Two digits if 10 <= value <= 26: dp[i] += dp[i-2]
```

## Memory hook
Check one digit and two digits. Zero cannot stand alone.
