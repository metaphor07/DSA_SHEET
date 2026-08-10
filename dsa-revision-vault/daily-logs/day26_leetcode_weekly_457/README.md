# Day 26 - LeetCode Weekly Contest 457

Contest Link: https://leetcode.com/contest/weekly-contest-457/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1. Coupon Code Validator | Submitted | Green | String validation + sorting |
| Q2. Power Grid Maintenance | Submitted | Green | DSU + active set per component |
| Q3. Minimum Time for K Connected Components | Reviewed | Yellow | Binary search on time + DSU |
| Q4 | Not attempted | Red | Revisit later |

## Quick Revision

Q1:
Validate code, business line, and active status. Sort valid coupons by businessLine then code.

Q2:
DSU gives connected components. Each component keeps a sorted set of online nodes.
For query type 1:
- if requested node is online, return it
- otherwise return smallest online node in its component
For query type 2:
- remove node from component set

Q3:
At time t, edges with time <= t are removed.
Remaining edges are those with time > t.
Use DSU to count connected components.
Binary search minimum t such that components >= k.
