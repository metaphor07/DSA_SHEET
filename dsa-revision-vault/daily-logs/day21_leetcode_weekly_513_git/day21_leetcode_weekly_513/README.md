# Day 21 - LeetCode Weekly Contest 513

Contest Link: https://leetcode.com/contest/weekly-contest-513/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1. Maximize Pair Strength Using GCD | Reviewed | Green | Brute force pairs + GCD |
| Q2. Count Subarrays With Even Odd Ratio I | Reviewed | Yellow | Ratio transform + prefix sum |
| Q3. Count of Unfinished Tasks After Each Shift | Reviewed | Yellow | Prefix sum + upper_bound simulation |
| Q4. Count Subarrays With Even Odd Ratio II | Upsolved | Red | Prefix sum + Fenwick tree |

## Quick Revision

Q1:
For each pair, strength = (a / gcd(a,b)) * (b / gcd(a,b)).

Q2/Q4:
Ratio x/y <= a/b becomes b*x - a*y <= 0.
Convert even to +b and odd to -a.
Then count subarrays with sum <= 0.

Q3:
Use prefix sums of task times. Maintain progress doneTime in current cycle.
If shift finishes all remaining work, answer is 0 and progress resets.
Otherwise count completed tasks with upper_bound.
