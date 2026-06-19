# DSA Revision - Day 02

Focus pattern: Sliding Window + Prefix Sum Remainder

## Questions done

| LeetCode | Problem | Pattern | Status | Main learning |
|---|---|---|---|---|
| 209 | Minimum Size Subarray Sum | Variable-size sliding window | Solved | Your approach was optimal, but extra checks made it messy |
| 974 | Subarray Sums Divisible by K | Prefix sum + remainder frequency | TLE first | Brute force `O(n^2)` must be replaced by remainder counting |
| 424 | Longest Repeating Character Replacement | Sliding window with max frequency | Wrong approach | Window is valid if `windowSize - maxFreq <= k` |
| 3 | Longest Substring Without Repeating Characters | Sliding window + frequency | Runtime/wrong earlier | Use full ASCII frequency and shrink until duplicate removed |

## Revision rule for Day 02

Before solving any similar question, first identify:

1. Is it asking for subarray/substring?
2. Is it asking for longest/minimum/count?
3. Is the condition monotonic?
4. If yes, use sliding window.
5. If counting many subarrays with divisibility/sum relation, think prefix sum.

## Mistake summary

- Do not use `O(n^2)` for counting subarrays when `n` is large.
- For substring problems, never skip characters like space unless the problem says so.
- For LeetCode 974, handle negative modulo.
- For LeetCode 424, do not try to actually replace characters. Only track the most frequent character count in the current window.

## Quick pattern memory

### Variable sliding window

```txt
Expand right.
While window is invalid, shrink left.
Update answer depending on longest/minimum/count requirement.
```

### Prefix remainder counting

```txt
If two prefix sums have same remainder modulo k,
then the subarray between them is divisible by k.
```

