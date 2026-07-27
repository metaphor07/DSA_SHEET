# Day 18 - LeetCode Weekly Contest 450

Contest Link: https://leetcode.com/contest/weekly-contest-450/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1. Smallest Index With Digit Sum Equal to Index | Added | 🟢 Green | Simulation |
| Q2. Minimum Swaps to Sort by Digit Sum | Reviewed | 🟢 Green | Cycle decomposition |
| Q3. Grid Teleportation Traversal | Upsolved | 🟡 Yellow | 0-1 BFS |
| Q4. Minimum Weighted Subgraph With the Required Paths II | Upsolved | 🔴 Red | LCA + tree distance formula |

## Quick Revision

Q1: Check each index. Return first i where digitSum(nums[i]) == i.

Q2: Sort by digit sum and value. Minimum arbitrary swaps = cycle decomposition.

Q3: Normal grid move cost is 1, teleport cost is 0. Use 0-1 BFS with deque.

Q4: Minimum subtree connecting three nodes in a tree has weight:
(dist(a,b) + dist(a,c) + dist(b,c)) / 2.
Use LCA to answer distances quickly.
