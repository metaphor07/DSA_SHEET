# LeetCode Biweekly Contest 187 - Wrapped Notes

Contest Link: https://leetcode.com/contest/biweekly-contest-187/

Included problems:

| Problem | Status | Color | Main Pattern |
|---|---|---|---|
| Q2. Maximum Value of an Alternating Sequence | Upsolved | 🟡 Yellow | Math / greedy construction |
| Q3. Minimum Adjacent Swaps to Partition Array | Upsolved | 🟡 Yellow | Category inversion counting |
| Q4. Minimum Cost to Convert String III | Upsolved | 🔴 Red | Prefix DP over non-overlapping intervals |

## Quick Revision

Q2:
To maximize value, start by going upward. First peak = s + m. Every next peak increases by m - 1.

Q3:
Convert each number into category 0, 1, or 2. Minimum adjacent swaps to group categories as 0-1-2 equals inversion count.

Q4:
Since positions used by rules cannot be reused, process left to right with dp[i] = minimum cost to transform prefix of length i.
