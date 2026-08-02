# Q3 Intuition - Count Partitions

This is a partition DP problem.

Define:

rec(start) = number of valid ways to partition nums[start...n-1]

For each possible segment nums[start...end]:
if max(segment) - min(segment) <= k,
then this segment can be one part.

So:

rec(start) += rec(end + 1)

Base case:
rec(n) = 1

Why 1?
Because reaching the end means we completed one valid partitioning.

Optimization:
While increasing end, maintain maxEle and minEle.
This avoids recalculating max/min each time.

Complexity:
O(n^2)
