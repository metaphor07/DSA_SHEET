# Day 18 Mistake Analysis

## Q2

This is arbitrary swap, not adjacent swap.
Use cycle decomposition, not inversion count.

## Q3

This is shortest path with 0/1 edge weights.
Use 0-1 BFS, not recursion memoization.

## Q4

Do not try to build subtree manually per query.
For three nodes in tree:
required subtree weight = half of sum of pairwise distances.

Key formula:
answer = (dist(a,b) + dist(a,c) + dist(b,c)) / 2
