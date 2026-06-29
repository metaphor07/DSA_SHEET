# Pattern: 0/1 Knapsack

## Partition Equal Subset Sum

First:
```text
If total sum is odd, return false.
```

Then:
```text
Can we form sum = total / 2?
```

## State
```text
dp[x] = true if sum x is possible.
```

## Transition
```cpp
for (int num : nums) {
    for (int x = target; x >= num; x--) {
        dp[x] = dp[x] || dp[x - num];
    }
}
```

## Memory hook
Loop backward because each number can be used only once.
