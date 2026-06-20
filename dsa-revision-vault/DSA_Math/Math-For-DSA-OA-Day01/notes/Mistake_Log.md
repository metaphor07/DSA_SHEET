# Day 01 Mistake Log

## Mistake 1
Problem:
LeetCode 69 - Sqrt(x)

Issue:
Difficulty understanding binary search when answer is not directly inside an array.

Fix:
Search over possible answer values. Find largest `mid` such that `mid * mid <= x`.

---

## Mistake 2
Problem:
LeetCode 441 - Arranging Coins

Issue:
Difficulty converting rows into formula.

Fix:
For `k` full rows, coins needed:
```cpp
k * (k + 1) / 2
```
Find largest `k` such that this value is `<= n`.

---

## General Fix
When solving binary search on answer:

```text
1. Define search space.
2. Define valid condition.
3. If mid is valid, store answer and try better.
4. If mid is invalid, reduce search space.
```
