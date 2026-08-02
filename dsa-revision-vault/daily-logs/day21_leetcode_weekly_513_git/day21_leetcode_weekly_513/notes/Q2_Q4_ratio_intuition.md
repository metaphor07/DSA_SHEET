# Q2/Q4 Intuition - Even Odd Ratio

For a subarray:
x = number of even elements
y = number of odd elements

Need:
y > 0
x / y <= a / b

Avoid division:
b*x <= a*y
b*x - a*y <= 0

Convert each element:
even => +b
odd  => -a

Then subarray transformed sum is:
b*evenCount - a*oddCount

Valid iff transformed sum <= 0.

For Q2, brute force all subarrays can pass smaller constraints.
For Q4, use prefix sums + Fenwick tree.
