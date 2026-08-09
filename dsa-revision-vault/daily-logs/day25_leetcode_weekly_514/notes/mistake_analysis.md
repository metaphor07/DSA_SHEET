# Day 25 Mistake Analysis

Q1:
Greedy sorting because discount saving is multiplicative.

Q2:
Depth starts from 1, not 0.

Q3:
The column prefix array must have size cols.
Use binary search on side length.

Q4:
Query range is [l+1, r-1], not [l, r].
Update affects only idx-1, idx, idx+1.
