# Day 5 - LeetCode Weekly Contest 391

Contest Link: https://leetcode.com/contest/weekly-contest-391/

## Contest Result

| Problem | Status | Topic | Note |
|---|---|---|---|
| Q1. Harshad Number | Submitted | Digit sum | Easy implementation |
| Q2. Water Bottles II | Submitted | Simulation / greedy | Straightforward simulation |
| Q3. Count Alternating Subarrays | Submitted | Sliding window / counting | Good progress |
| Q4. Minimize Manhattan Distances | Upsolved | Manhattan transform + multiset | Key pattern learned |

## Day 5 Summary

Strong progress: first 3 questions submitted successfully.

Main Q4 learning:
For Manhattan distance between points, transform each point `(x, y)` into:

- `x + y`
- `x - y`

Then maximum Manhattan distance among all points becomes:

max(
    max(x+y) - min(x+y),
    max(x-y) - min(x-y)
)

After removing each point, use multiset to quickly get current min and max values.
