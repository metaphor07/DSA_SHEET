# Day 21 Mistake Analysis

## Q1

Use simplified formula:
(nums[i] / gcd) * (nums[j] / gcd)

## Q2

Not recursion.
Ratio condition becomes cross multiplication.

## Q3

Not DP.
Use prefix sum and progress simulation.

Important rule:
If all tasks finish during a shift, unused time is discarded and next shift restarts from task 0.

## Q4

Same ratio idea as Q2, but need O(n log n).
Use prefix sum + Fenwick tree.
