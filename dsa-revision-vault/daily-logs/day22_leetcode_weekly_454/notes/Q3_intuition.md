# Q3 Intuition - Maximum Product of First and Last Elements

If first chosen index is i and last chosen index is j:

j - i + 1 >= m
=> j >= i + m - 1

Scan i from right to left.
Maintain maxEle and minEle among all valid right endpoints.

If nums[i] is positive, use maxEle.
If nums[i] is negative, use minEle.

Use LLONG_MIN for answer.
