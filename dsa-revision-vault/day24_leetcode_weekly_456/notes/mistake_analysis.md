# Day 24 Mistake Analysis

## Q2

Removing one element from an array changes only local adjacency.
So do not recompute all LCPs after every removal.

## Q3

Marked RED.
Revisit later.

## Q4

Important observations:
- Mandatory edges must be included.
- Mandatory edges cannot be upgraded.
- Mandatory edges forming a cycle means impossible.
- Whole graph must be connected.
- For guessed stability X, use DSU to test connectivity.
