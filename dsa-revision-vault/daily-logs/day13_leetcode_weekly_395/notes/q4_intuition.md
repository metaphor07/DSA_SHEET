# Q4 Intuition - Median of Uniqueness Array

For every subarray, uniqueness = number of distinct values.

Brute force:
Generate all subarrays, count distinct, sort uniqueness array, return median.

Optimal trigger:
Median of all subarray values
= binary search on answer
+ count how many subarrays have value <= mid.

Here:
value <= mid means subarray has at most mid distinct elements.

Counting subarrays with at most k distinct is classic sliding window.

For fixed k:
- maintain frequency map
- shrink left while distinct > k
- for each right, add right - left + 1 valid subarrays.
