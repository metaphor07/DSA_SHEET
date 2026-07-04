# Day 11 - LeetCode Biweekly Contest 186

Contest Link: https://leetcode.com/contest/biweekly-contest-186/

## Contest Status

| Problem | Status | Color | Notes |
|---|---|---|---|
| Q1 | Not recorded | ⚪ Not marked | Add your accepted code later |
| Q2 | Not recorded | ⚪ Not marked | Add your accepted code later |
| Q3. Minimum Operations to Transform Binary String | Upsolved | 🟡 Yellow | Recursion + memoization with state `(index, currentBit)` |
| Q4. Count Distinct Ways to Form Target from Two Strings | Upsolved | 🔴 Red | DP with last used indices / prefix-sum bottom-up |

## Main Learnings

Q3:
Operation affects current and next index, so greedy is risky.
Use DP state:
`rec(index, currentBit)`

Q4:
Need to form target using increasing indices from both strings.
Track last used index in word1 and word2, and whether both strings were used.
Efficient solution uses bottom-up DP with prefix sums.
Recursion memoization is easier to understand but may be slower.
