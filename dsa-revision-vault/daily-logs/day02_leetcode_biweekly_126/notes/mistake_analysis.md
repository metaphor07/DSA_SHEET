# Day 2 Mistake Analysis

## Q1

Logic was correct, but the loop missed `len--`, causing infinite loop.

## Q2

Your submitted solution is optimal.

Pattern:
Repeatedly mark smallest unmarked elements -> sort once + pointer + marked array.

## Q3

Correct idea:
For each '?', choose the character with minimum current frequency.
After selecting all replacement characters, sort them and fill '?' from left to right.

Why sort?
The chosen multiset minimizes value. Sorting gives lexicographically smallest final string.

## Q4

Your original DP counted subsequences with sum k only.

But each target subsequence with sum k contributes:

2^(n - length)

So recurrence becomes:

rec(ind, k) = 2 * rec(ind + 1, k) + rec(ind + 1, k - nums[ind])

The `2 * not_pick` is the key.
