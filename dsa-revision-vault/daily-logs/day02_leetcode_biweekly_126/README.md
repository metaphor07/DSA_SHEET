# Day 2 - LeetCode Biweekly Contest 126

Contest Link: https://leetcode.com/contest/biweekly-contest-126/

## Contest Result

| Problem | Status | Topic | Note |
|---|---|---|---|
| Q1. Find the Sum of Encrypted Integers | Solved after fix | Digit simulation | Infinite loop bug due to missing len-- |
| Q2. Mark Elements on Array by Performing Queries | Solved | Sorting + pointer + marking | Optimal approach |
| Q3. Replace Question Marks in String to Minimize Its Value | Upsolved | Greedy + frequency balancing | Key trick: choose min frequency, then sort chosen chars |
| Q4. Find the Sum of the Power of All Subsequences | Upsolved | DP / subsequence sum with contribution | Missing multiplier 2 in not-pick case |

## Day 2 Summary

Good progress. Q2 was solved optimally.

Main learning:
- Q1: Every while loop must update the condition variable.
- Q2: Repeated smallest unmarked removal = sort once + pointer + marked array.
- Q3: Minimize value = balance character frequencies.
- Q4: Subsequence inside larger subsequence = unchosen elements contribute factor 2.

## Target for Day 3

Q1 under 10 min, Q2 under 25 min, Q3 correct idea within 30 min.
