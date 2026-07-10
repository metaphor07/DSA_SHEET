# Q3 Intuition - Minimum Array End

Need an increasing array of length n starting with x, and bitwise AND of all elements must equal x.

For AND to stay x:
Every bit that is 1 in x must be 1 in all array elements.

So:
1-bits of x are fixed.
0-bits of x are free.

Since nums[0] = x, the last element is obtained by putting n - 1 into the zero-bit positions of x.
