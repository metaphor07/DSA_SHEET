# Q3 Intuition - Minimum Operations to Transform Binary String

Operations:
1. Change one 0 to 1.
2. If adjacent bits are 11, change both to 00.

The pair operation affects index i and i+1, so greedy can fail.

State:
recFun(ind, curBit)

Meaning:
minimum operations from index ind to end, where s1[ind] currently has value curBit.

Why curBit?
Because previous pair operation may already have changed current index to 0.

At each index:
1. Fix current position alone if possible.
2. Use pair operation on current and next index.

This is a classic DP pattern when an operation affects i and i+1.
