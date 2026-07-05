# Pattern: Coin Change II

## State
```text
dp[x] = number of combinations to make amount x
```

## Transition
```cpp
dp[x] += dp[x - coin];
```

## Loop order
```cpp
for (int coin : coins) {
    for (int x = coin; x <= amount; x++) {
        dp[x] += dp[x - coin];
    }
}
```

## Memory hook
Coin outside loop = combinations.
Amount outside loop = permutations.
