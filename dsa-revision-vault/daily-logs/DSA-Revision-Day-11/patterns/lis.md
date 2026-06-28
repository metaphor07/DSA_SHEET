# Pattern: Longest Increasing Subsequence

## O(n^2) DP

```text
dp[i] = length of LIS ending at index i
```

```text
if nums[j] < nums[i]:
    dp[i] = max(dp[i], 1 + dp[j])
```

## O(n log n) Binary Search

```text
tails[i] = smallest possible tail value of an increasing subsequence of length i + 1
```

For each x:

```cpp
auto it = lower_bound(tails.begin(), tails.end(), x);

if (it == tails.end()) {
    tails.push_back(x);
} else {
    *it = x;
}
```

## Memory hook
Binary-search LIS does not store the real LIS.  
It stores the best possible tails.
