# Q3 Review

You had the correct trigger:

sort + median index

If nums[mid] < k:
Only elements from mid to n-1 can affect raising the median.

If nums[mid] > k:
Only elements from 0 to mid can affect lowering the median.

No gap array or simulation is required.
