# Day 13 - LeetCode Weekly Contest 395

Contest Link: https://leetcode.com/contest/weekly-contest-395/

## Contest Status

| Problem | Status | Color | Notes |
|---|---|---|---|
| Q1. Find the Integer Added to Array I | Solved / add later if needed | 🟢 Green | Simple min-difference observation |
| Q2. Find the Integer Added to Array II | Attempted | 🟡 Yellow | Remove two elements, then verify actual transformed array |
| Q3. Minimum Array End | Upsolved | 🟡 Yellow | Fill zero bits of x using n-1 |
| Q4. Find the Median of the Uniqueness Array | Upsolved | 🔴 Red | Binary search answer + sliding window count |

## Main Learnings

Q2:
Sum-based checking is not enough. After removing two numbers, verify that every remaining element plus x exactly matches nums2.

Q3:
For bitwise AND to remain x, every 1-bit of x must stay 1 in all numbers. Only 0-bits of x are free.

Q4:
Median of all subarray values usually means binary search on answer.
