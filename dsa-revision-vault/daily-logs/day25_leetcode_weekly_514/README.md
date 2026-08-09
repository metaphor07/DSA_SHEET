# Day 25 - LeetCode Weekly Contest 514

Contest Link: https://leetcode.com/contest/weekly-contest-514/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1. Minimum Total Price After Applying Discounts | Reviewed | Green | Greedy sorting |
| Q2. Weighted Sum of a Tree | Reviewed | Green | Tree BFS / depth |
| Q3. Maximum Area of Two Non-Overlapping Square Submatrices | Debugged | Yellow | Maximal Square DP + binary search |
| Q4. Peaks in Array II | Upsolved | Red | Fenwick tree + local update |

## Quick Revision

Q1: Pair largest price with largest discount.
Q2: Build tree from parent array, calculate depth and height.
Q3: Maximal Square DP + binary search side length. Fix: prefixRight must use cols.
Q4: Fenwick tree stores peak indices. Query [l+1, r-1]. Update only idx-1, idx, idx+1.
