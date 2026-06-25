# Day 4 - LeetCode Weekly Contest 390

Contest Link: https://leetcode.com/contest/weekly-contest-390/

## Contest Problems

| Problem | Topic | Status |
|---|---|---|
| Q1. Maximum Length Substring With Two Occurrences | Sliding window / frequency | Added optimal |
| Q2. Apply Operations to Make Sum of Array Greater Than or Equal to k | Math / enumeration | Upsolved |
| Q3. Most Frequent IDs | Hashmap + max heap + lazy deletion | Approach correct |
| Q4. Longest Common Suffix Queries | Trie on reversed words | Upsolved |

## Main Learnings

Q2 is not about powers of 2. It is about choosing a value x, increasing 1 to x, then duplicating it enough times.

Q3 max heap direction is correct, but because frequencies update, old heap entries become stale. Use lazy deletion.

Q4 suffix query becomes prefix query after reversing strings. Build trie on reversed container words and store the best index at every node.
