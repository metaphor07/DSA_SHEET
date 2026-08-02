# Day 20 - LeetCode Weekly Contest 453

Contest Link: https://leetcode.com/contest/weekly-contest-453/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1. Transform Array to All Equal Elements | Upsolved / reviewed | 🟢 Green | Adjacent flip greedy |
| Q2. Count Computer Unlocking Permutations | Upsolved / reviewed | 🟢 Green | Unique minimum + factorial |
| Q3. Count Partitions With Max-Min at Most K | Attempted / upsolved | 🟡 Yellow | Partition DP recursion + memoization |
| Q4 | Not discussed | ⚪ Not marked | Add later |

## Quick Revision

Q1:
Try target = 1 and target = -1. Greedily scan left to right. If current value is not target, flip current and next.

Q2:
Computer 0 must be the unique minimum complexity. If yes, all other computers can be unlocked in any order, so answer is (n-1)!.

Q3:
Partition DP:
rec(start) = number of valid ways to partition suffix starting at start.
While extending segment, maintain current min and max.
If max - min <= k, add rec(end + 1).
