# Q4 Intuition

Peak index i:

nums[i] > nums[i-1] and nums[i] > nums[i+1]

For query [l, r], count peaks only in [l+1, r-1].

For update at idx, only these peak states may change:
idx-1, idx, idx+1

Use Fenwick tree for point update and range sum.
