# Q3 Intuition - Minimum Time for K Connected Components

At time t:
- edges with removal time <= t are removed
- edges with removal time > t still exist

For a fixed t:
Build DSU using only edges with time > t.
Then count components.

If components >= k:
t is enough, try smaller time.

If components < k:
need remove more edges, try larger time.

This gives binary search on time.
