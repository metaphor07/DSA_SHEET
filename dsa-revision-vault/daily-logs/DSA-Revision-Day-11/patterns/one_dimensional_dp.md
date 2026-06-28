# Pattern: 1D DP

## Climbing Stairs
```text
dp[i] = ways to reach step i
dp[i] = dp[i-1] + dp[i-2]
```

## Min Cost Climbing Stairs
```text
dp[i] = minimum cost to reach step i
dp[i] = cost[i] + min(dp[i-1], dp[i-2])
answer = min(dp[n-1], dp[n-2])
```

## House Robber
```text
dp[i] = maximum money from houses 0...i
dp[i] = max(dp[i-1], nums[i] + dp[i-2])
```
