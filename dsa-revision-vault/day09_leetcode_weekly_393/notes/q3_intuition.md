# Q3 Intuition - Kth Smallest Amount

Your heap idea can generate values in sorted order for small k, but it is too slow for large k.

Correct trigger:

kth smallest number + can count how many numbers are <= x
=> binary search on answer

A number is valid if it is divisible by at least one coin.

For a candidate x:

countValid(x) = number of integers from 1 to x divisible by at least one coin

Use inclusion-exclusion with LCMs.

Then binary search the smallest x such that:

countValid(x) >= k
