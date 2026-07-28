# Day 19 Mistake Analysis

## Q2

Your erase approach was close, but erase shifts characters and the loop skips new pairs.

Correct:
Use a stack.

## Q4

Greedy stack is not enough because we need lexicographically smallest among many possible deletion orders.

Correct:
1. Interval DP to know removable substrings.
2. Suffix DP to choose the lexicographically smallest final string.
