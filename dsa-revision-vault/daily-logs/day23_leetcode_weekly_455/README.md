# Day 23 - LeetCode Weekly Contest 455

Contest Link: https://leetcode.com/contest/weekly-contest-455/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1 | Added placeholder | Green | Basic implementation |
| Q2. Inverse Coin Change | Reviewed | Yellow | Greedy reconstruction + coin-change DP |
| Q3. Minimum Increments to Equalize Leaf Paths | Debugged | Yellow | Tree DFS + greedy bottom-up |
| Q4 | Not attempted | Red | To upsolve later |

## Quick Revision

Q2:
Build coins from small to large. Maintain coin-change DP from discovered coins.
For amount x:
- if dp[x] == numWays[x-1], no coin x
- if dp[x] + 1 == numWays[x-1], coin x exists
- otherwise impossible

Q3:
Edges are undirected. Root the tree at node 0 during DFS using parent.
For every node, children return maximum path sum to a leaf.
Every child with smaller sum than max child sum needs one increment operation.
