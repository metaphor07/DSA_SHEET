# Day 24 - LeetCode Weekly Contest 456

Contest Link: https://leetcode.com/contest/weekly-contest-456/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1 | Added placeholder | Green | Basic implementation |
| Q2. Longest Common Prefix Between Adjacent Strings After Removals | Reviewed | Yellow | LCP + multiset |
| Q3 | Not solved in contest | Red | Revisit later |
| Q4. Maximize Spanning Tree Stability with Upgrades | Upsolved | Red | DSU + binary search on answer |

## Quick Revision

Q2:
After removing one string, only local adjacent pairs change:
- old pair (i-1, i) removed
- old pair (i, i+1) removed
- new pair (i-1, i+1) added

Q4:
Binary search the answer X.
For each X, use DSU to check if all nodes can be connected using mandatory edges, free optional edges, and at most k upgraded optional edges.
