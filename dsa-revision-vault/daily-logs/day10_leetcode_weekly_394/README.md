# Day 10 - LeetCode Weekly Contest 394

Contest Link: https://leetcode.com/contest/weekly-contest-394/

## Contest Status

| Problem | Status | Color | Notes |
|---|---|---|---|
| Q1. Count the Number of Special Characters I | Solved | 🟢 Green | Solved in contest |
| Q2. Count the Number of Special Characters II | Solved | 🟢 Green | Solved in contest |
| Q3. Minimum Number of Operations to Satisfy Conditions | Upsolved after hint | 🟡 Yellow | Column cost + DP / recursion memoization |
| Q4. Find Edges in Shortest Paths | Not solved | 🔴 Red | Dijkstra from source and target |

## Summary

You solved Q1 and Q2 within 30 minutes. Good speed.

Q3 pattern:
column cost + adjacent-column restriction = Paint House style DP

Q4 pattern:
Find whether each edge belongs to any shortest path
= Dijkstra from source + Dijkstra from target
