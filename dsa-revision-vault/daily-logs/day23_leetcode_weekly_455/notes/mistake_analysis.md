# Day 23 Mistake Analysis

## Q2

Do not try to brute force coins.
Build coins greedily from small amount to large amount.

Key observation:
A coin of value x adds exactly one new way to make amount x.

## Q3

Main mistake:
Edges are undirected, but code built only one direction.

Fix:
Build adjacency both ways and pass parent in DFS.

Tree DFS pattern:
- child returns max path sum
- parent compares all children
- smaller child sums contribute one operation
