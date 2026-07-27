# Q2 Intuition - Minimum Swaps to Sort by Digit Sum

Sorting rule:
1. smaller digit sum first
2. if tie, smaller number first

After sorting, we know where every original element should go.

Because any two positions can be swapped:
minimum swaps = cycle decomposition.

A cycle of size c needs c - 1 swaps.
