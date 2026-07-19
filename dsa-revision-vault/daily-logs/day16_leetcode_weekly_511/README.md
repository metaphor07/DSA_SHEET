# Day 16 - LeetCode Weekly Contest 511

Contest Link: https://leetcode.com/contest/weekly-contest-511/

Included problems:

| Problem | Status | Color | Main Pattern |
|---|---|---|---|
| Q1. Count Dominant Nodes in a Binary Tree | Solved / reviewed | 🟢 Green | Postorder subtree maximum |
| Q2. Even Number of Knight Moves | Solved / reviewed | 🟢 Green | Chessboard color parity |
| Q3. Transform Binary String Using Subsequence Sort | Upsolved / debugged | 🟡 Yellow | Prefix zero feasibility with limited '?' |
| Q4. Minimum Number of String Groups Through Transformations | Upsolved | 🔴 Red | Split even/odd indices + canonical rotation |

## Quick Revision

Q1: A node is dominant if its value is the maximum in its subtree. Use postorder DFS and return subtree maximum. Null should return INT_MIN, not 0.

Q2: A knight changes square color every move. Even number of moves means start and target must have the same board color.

Q3: Sorting a binary subsequence can only move 0s to the left and 1s to the right. Therefore every prefix of target must be able to have at least as many zeros as the source prefix.

Q4: Transformation independently cyclically shifts even-index subsequence and odd-index subsequence. Normalize both by lexicographically minimum rotation and count unique keys.
