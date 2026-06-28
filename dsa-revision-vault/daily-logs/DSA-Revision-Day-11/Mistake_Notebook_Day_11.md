# Mistake Notebook - Day 11

## LC 300 - Longest Increasing Subsequence
**Status:** Yellow  
**Pattern:** LIS DP + Binary Search optimization

### Reason
All problems were submitted successfully, but the optimal binary-search approach for LIS was not easy to recall.

### O(n^2) DP memory hook
```text
dp[i] = length of LIS ending at i.
Check all j < i where nums[j] < nums[i].
```

### Binary-search memory hook
```text
tails[len] = smallest possible ending value of an increasing subsequence of length len + 1.
```

### Key idea
For each number:
- find first element in tails that is >= current number
- replace it with current number
- if no such element exists, append current number

### Why replace?
Replacing keeps the subsequence ending value as small as possible, which gives more chance to extend later.
