# Day 7 Mistake Analysis

## Q1

No major mistake. Strong one-pass implementation.

## Q2

The issue was incomplete cyclic distance handling.

Correct:
costToA = min(c - 'a', 'z' - c + 1)

## Q3

You were thinking too much about gaps and step-by-step operations.

For median problems after sorting:
- If median too small, fix right half.
- If median too large, fix left half.

## Q4

The missing trigger:
Queries on weighted graph + walk allowed + bitwise AND cost.

Because walk can repeat edges/nodes, answer depends on the whole connected component, not a single shortest path.
Use DSU and component-wise bitwise AND.
