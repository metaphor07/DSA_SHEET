# Day 27 Mistake Analysis

## Q2

Greedy is correct, but implement as Kruskal:
add smallest edges until components == k.

## Q3

Do not build the result string.
Use length + backward tracing.

## Q4

Do not generate all paths.
Use palindrome expansion from both endpoints.

Key state:
mask + left endpoint + right endpoint
