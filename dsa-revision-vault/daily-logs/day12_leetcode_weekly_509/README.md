# Day 12 - LeetCode Weekly Contest 509

Contest Link: https://leetcode.com/contest/weekly-contest-509/

## Contest Status

| Problem | Status | Color | Notes |
|---|---|---|---|
| Q1 | Not recorded | ⚪ Not marked | Add your accepted code later |
| Q2. Subsequence After One Replacement | Upsolved / corrected | 🟡 Yellow | Simple greedy was wrong; correct approach is prefix + suffix subsequence matching |
| Q3. Divisible Game | Upsolved | 🔴 Red | Fixed-k transformed array + compressed Kadane over divisors |
| Q4. Palindromic Subarray Sum | Upsolved | 🔴 Red | Manacher on array + prefix sum |

## Main Learnings

Q2:
Subsequence with at most one replacement is not solved by replacing at the first mismatch.
Correct trigger:
one replacement = one wildcard position in s.
Use prefix matching and suffix matching.

Q3:
For a fixed k, transform nums:
+nums[i] if divisible by k, otherwise -nums[i].
Then find maximum subarray sum.
To handle many k efficiently, process divisors only and use compressed Kadane.

Q4:
Maximum sum palindromic subarray.
Since values are positive, for each center the largest palindrome gives the best sum for that center.
Use Manacher's algorithm on array and prefix sums.
