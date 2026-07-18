# Q3 Intuition - Minimum Adjacent Swaps to Partition Array

The final array needs three contiguous parts:

1. values < a
2. values in [a, b]
3. values > b

Convert every number into a category:

0 = nums[i] < a
1 = a <= nums[i] <= b
2 = nums[i] > b

The final category array must be sorted:

0 0 0 1 1 1 2 2 2

Minimum adjacent swaps to sort by categories equals inversion count.

Inversions are:
- 1 before 0
- 2 before 0
- 2 before 1

While scanning:
- current 0 adds cnt1 + cnt2
- current 1 adds cnt2
- current 2 adds 0

This is why it is not partition DP.
