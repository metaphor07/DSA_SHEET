# Day 14 Mistake Analysis

## Q1
Accepted.
Remove debug cout statements before saving.

## Q2
Accepted.
Cleaner loop: for (int i = 0; i < n; i += k)

## Q3
Accepted.
Your logic works. Cleaner implementation can use start += len directly.

## Q4
Hard part:
For target T, pairing is limited by both total/2 and total - maxNeed.

Important formula:
pairs = min(total / 2, total - maxNeed)
singles = total - 2 * pairs
