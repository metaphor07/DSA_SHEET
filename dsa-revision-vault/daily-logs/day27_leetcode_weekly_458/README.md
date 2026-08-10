# Day 27 - LeetCode Weekly Contest 458

Contest Link: https://leetcode.com/contest/weekly-contest-458/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1 | Added placeholder | Green | Basic implementation |
| Q2. Minimize Maximum Component Cost | Reviewed | Yellow | Kruskal / DSU |
| Q3. Process String with Special Operations II | Debugged | Yellow | Reverse tracing kth character |
| Q4. Longest Palindromic Path in Graph | Upsolved | Red | Bitmask DP + two endpoints |

## Quick Revision

Q2:
Start with n components, add smallest edges until components == k.
The last used edge weight is the minimized maximum component cost.

Q3:
Do not build the final string. First pass calculates final length.
Second pass goes backward and maps index k through operations.

Q4:
n <= 14 should click bitmask DP.
Palindrome path can be expanded from both ends:
dp[mask][left][right] = true.
