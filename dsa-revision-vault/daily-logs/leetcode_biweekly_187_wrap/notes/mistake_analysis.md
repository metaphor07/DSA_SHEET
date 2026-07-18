# Mistake Analysis

## Q2

The tricky part is realizing that after a peak P,
the next valley should be P - 1, not very small.
This allows the next peak to become P + m - 1.

## Q3

This is not partition DP.
Because adjacent swaps cost equals inversion count, convert into category labels and count inversions.

## Q4

This is not edit distance.
No overlapping rule applications are allowed, so the string is partitioned into untouched single characters and rule-covered intervals.

Correct pattern:
non-overlapping string transformations = prefix DP.
