# Day 05 Mistake Log

## Mistake 1
Problem:
LeetCode 560 - Subarray Sum Equals K

Issue:
Forgetting `freq[0] = 1`.

Fix:
Initialize:

```cpp
freq[0] = 1;
```

This handles subarrays starting from index 0.

---

## Mistake 2
Problem:
LeetCode 1524 - Number of Sub-arrays With Odd Sum

Priority:
Important

Issue:
Trying to generate all subarrays.

Fix:
Use prefix parity counts.

```cpp
even = 1;
odd = 0;
```

If prefix is odd, add previous even count.
If prefix is even, add previous odd count.

---

## Mistake 3
Problem:
Range sum

Issue:
Using `prefix[r] - prefix[l - 1]` creates special case for `l == 0`.

Fix:
Use `n + 1` prefix array:

```cpp
sum = prefix[r + 1] - prefix[l];
```
