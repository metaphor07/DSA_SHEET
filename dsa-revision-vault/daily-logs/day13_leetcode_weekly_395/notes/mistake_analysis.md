# Day 13 Mistake Analysis

## Q2

Good initial thought:
remove two elements.

Mistake:
Using only sums to infer x.

Fix:
After finding x, verify the full sorted transformed array.

## Q3

Important pattern:
AND result fixed as x means:
- 1 bits of x are mandatory
- 0 bits are free

Put n-1 into free positions.

## Q4

Important pattern:
median of subarray-derived values means binary search on answer.

For uniqueness:
count(value <= k) = count subarrays with at most k distinct.
