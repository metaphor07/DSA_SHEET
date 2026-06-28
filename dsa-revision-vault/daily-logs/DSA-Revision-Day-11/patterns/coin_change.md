# Pattern: Coin Change

## State
```text
dp[x] = minimum coins needed to make amount x
```

## Transition
```text
dp[x] = min(dp[x], 1 + dp[x - coin])
```

## Memory hook
For every amount, try every coin.
