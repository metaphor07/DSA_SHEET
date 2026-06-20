# Day 1 - LeetCode Weekly Contest 400

Contest Link: https://leetcode.com/contest/weekly-contest-400/

## Contest Result

| Problem | Status | Topic | Note |
|---|---|---|---|
| Q1. Minimum Number of Chairs in a Waiting Room | Solved | Simulation / Counting | Solved quickly |
| Q2. Count Days Without Meetings | Solved | Sorting + Interval Merge | Solved within contest |
| Q3. Lexicographically Minimum String After Removing Stars | Wrong approach | Greedy + 26 stacks | Upsolved |
| Q4. Find Subarray With Bitwise AND Closest to K | Not solved | Bitwise + Subarray AND compression | Upsolved |

## Time Performance

Solved Q1 and Q2 within 30 minutes.

This is a strong Day 1 result. For OA preparation, solving the first 2 problems fast is a good sign.
The next goal is to convert Q3-level problems by recognizing the correct data structure faster.

## Main Learnings

1. For lexicographically minimum deletion problems, think about which character should be deleted globally, not only locally.
2. For repeated removals from a string, avoid actual erase operations when possible. Use index marking.
3. For bitwise AND subarray problems, remember that AND values only decrease as the subarray expands, so the number of distinct AND values ending at each index is small.
4. In contests, after solving Q1 and Q2 fast, spend 20-25 minutes calmly identifying the pattern for Q3 before coding.

## Target for Next Contest

- Q1 + Q2 within 35 minutes.
- Q3 with correct approach, even if implementation takes time.
- Read Q4 and identify the topic, but do not panic if it feels hard.
