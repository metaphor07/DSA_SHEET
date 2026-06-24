# Math for DSA/OA - Day 03

## Topic
GCD and LCM

## Concepts Covered
- Greatest Common Divisor
- Euclidean algorithm
- GCD of array
- Least Common Multiple
- Safe LCM formula
- Coprime numbers
- GCD of frequencies
- GCD of strings

## Problems
| # | Platform | Problem | Concept |
|---|----------|---------|---------|
| 1 | LeetCode | 1979. Find Greatest Common Divisor of Array | GCD of min and max |
| 2 | LeetCode | 1071. Greatest Common Divisor of Strings | GCD length |
| 3 | LeetCode | 2413. Smallest Even Multiple | LCM with 2 |
| 4 | LeetCode | 914. X of a Kind in a Deck of Cards | GCD of frequencies |
| 5 | Codeforces | 1768A. Greatest Convex | Math observation |

## Core Formulas
```cpp
gcd(a, b) = gcd(b, a % b)
lcm(a, b) = a / gcd(a, b) * b
```
