# Day 26 Mistake Analysis

## Q1

Careful with exact strings:
'grocery' has no trailing space.

## Q2

Main bug:
For type 1 query, first check if requested node is online.
Do not directly return smallest node.

## Q3

Do not remove edges one by one and recompute.
Think in terms of remaining edges at time t.

Remaining edge condition:
edgeTime > t
