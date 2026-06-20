# Math for DSA/OA - Day 01

## Topic
Basic Math + Overflow + Binary Search Foundation

## Concepts Covered
- `int` vs `long long`
- Safe multiplication using `1LL`
- Sum of first `n` numbers
- Ceil/floor division basics
- Digit extraction
- Carry handling
- Binary search for largest valid answer
- Simulation with `long long`

## Problems Solved

| # | Platform | Problem | Concept |
|---|----------|---------|---------|
| 1 | LeetCode | 9. Palindrome Number | Digit extraction, reverse half |
| 2 | LeetCode | 66. Plus One | Carry handling |
| 3 | LeetCode | 69. Sqrt(x) | Binary search, overflow safety |
| 4 | LeetCode | 441. Arranging Coins | Formula + binary search |
| 5 | CSES | Weird Algorithm | Simulation, long long |

## Key Formulas

```cpp
// Sum from 1 to n
1LL * n * (n + 1) / 2

// Sum from l to r
1LL * r * (r + 1) / 2 - 1LL * (l - 1) * l / 2

// Number of subarrays
1LL * n * (n + 1) / 2

// Number of pairs
1LL * n * (n - 1) / 2

// Ceil division for positive integers
(a + b - 1) / b

// Safe multiplication
1LL * a * b
```

## Important Binary Search Pattern

```cpp
while (low <= high) {
    long long mid = low + (high - low) / 2;

    if (condition(mid)) {
        ans = mid;
        low = mid + 1;   // try bigger answer
    } else {
        high = mid - 1;  // try smaller answer
    }
}
```

## Day 1 Reflection

The hardest problems today were:
- LeetCode 69 - Sqrt(x)
- LeetCode 441 - Arranging Coins

Reason:
Both require binary search on answer, where the answer is not directly present in an array.

Fix:
Think of binary search as finding the largest or smallest value satisfying a condition.
