# Day 19 - LeetCode Weekly Contest 451

Contest Link: https://leetcode.com/contest/weekly-contest-451/

| Problem | Status | Color | Pattern |
|---|---|---|---|
| Q1 | Add submitted code if needed | 🟢 Green | Not discussed in chat |
| Q2. Resulting String After Adjacent Removals | Debugged | 🟢 Green | Stack for repeated adjacent removals |
| Q3 | Add submitted/upsolved code if needed | 🟡 Yellow | Not discussed in chat |
| Q4. Lexicographically Smallest String After Adjacent Removals | Upsolved | 🔴 Red | Interval DP + suffix DP |

## Quick Revision

Q2:
Repeatedly removing adjacent consecutive characters should be handled using a stack, not string erase inside a loop.

Q4:
Since removing a middle substring can create new adjacent removable pairs, we need interval DP to know which substrings can disappear.
Then use suffix DP to build the lexicographically smallest remaining string.
