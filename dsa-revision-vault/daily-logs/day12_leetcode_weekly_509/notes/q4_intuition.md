# Q4 Intuition - Palindromic Subarray Sum

Need maximum sum of a palindromic subarray.

Brute force all subarrays is too slow.

Use Manacher's algorithm on the integer array to get:
- largest odd palindrome radius for each center
- largest even palindrome radius for each gap

Because nums are positive, for a fixed center, the largest palindrome around that center has the maximum sum for that center.

Then use prefix sum to get any palindrome sum in O(1).
