# Day 22 Mistake Analysis

## Q2

User idea with index vector was correct, but helper scans occurrences repeatedly and can TLE.

Optimal:
leftFreq[target] * rightFreq[target]

## Q3

Fixes:
- use LLONG_MIN instead of INT_MIN for answer
- use long long multiplication
- keep min/max valid right endpoint while scanning backward

## Q4

Do not build full path per query.
Use LCA + weighted binary lifting.
