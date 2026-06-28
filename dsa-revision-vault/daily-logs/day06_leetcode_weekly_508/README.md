# Day 6 - LeetCode Weekly Contest 508

Contest Link: https://leetcode.com/contest/weekly-contest-508/

## Contest Status

| Problem | Status | Color | Notes |
|---|---|---|---|
| Q1. Maximum Total Sum of K Selected Elements | Solved in one attempt | 🟢 Green | Good greedy implementation |
| Q2. Filter Occupied Intervals | Attempted / partial | 🟡 Yellow | Correct main direction: merge first, then subtract free interval |
| Q3. Maximum Subarray Sum After Multiplier | Not solved in contest | 🔴 Red | Needs Kadane with states |
| Q4. Minimum Time to Reach Target With Power Constraint | Not solved in contest | 🔴 Red | Dijkstra with state `(node, remainingPower)` |

## Summary

Requested marking:
- Q1 = Green
- Q2 = Yellow
- Q3 = Red
- Q4 = Red

## Main Learnings

1. Q2 interval problems usually become:
   - sort
   - merge overlapping/touching intervals
   - subtract the removal interval from each merged interval

2. Q3 is not "modify whole array then run Kadane".
   The operation applies to exactly one subarray, so use Kadane + states.

3. Q4 is a shortest-path problem with resource constraint.
   Use Dijkstra on expanded states: `(node, remainingPower)`.
