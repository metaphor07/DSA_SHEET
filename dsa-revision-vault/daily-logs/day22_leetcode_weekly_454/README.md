# Day 22 - LeetCode Weekly Contest 454

Contest Link: https://leetcode.com/contest/weekly-contest-454/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1. Generate Tag for Video Caption | Added | Green | String simulation |
| Q2. Count Special Triplets | Debugged | Green | Left/right frequency maps |
| Q3. Maximum Product of First and Last Elements of a Subsequence | Debugged | Yellow | Right-side min/max |
| Q4. Find Weighted Median Node in Tree | Upsolved | Red | LCA + binary lifting by weighted distance |

Quick Revision:
Q1: Build hashtag in camelCase, remove non-letters, truncate to 100 characters.
Q2: For middle index j, contribution = leftFreq[2*nums[j]] * rightFreq[2*nums[j]].
Q3: Scan i from right to left and maintain max/min valid right endpoint.
Q4: For query (u, v), find first node on path u -> v whose distance from u reaches at least half of total path distance.
