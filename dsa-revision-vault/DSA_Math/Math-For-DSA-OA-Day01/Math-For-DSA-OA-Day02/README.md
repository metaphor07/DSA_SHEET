# Math for DSA/OA - Day 02

## Topic
Digit Math

## Concepts Covered
- Extract last digit using `% 10`
- Remove last digit using `/ 10`
- Count digits, sum digits, product digits
- Reverse number and overflow handling
- Digital root
- Happy number cycle detection
- Self-dividing numbers
- Fair number checking

## Problems
| # | Platform | Problem | Concept |
|---|----------|---------|---------|
| 1 | LeetCode | 7. Reverse Integer | Reverse + overflow |
| 2 | LeetCode | 258. Add Digits | Digital root |
| 3 | LeetCode | 202. Happy Number | Digit square sum + cycle |
| 4 | LeetCode | 728. Self Dividing Numbers | Check every digit |
| 5 | Codeforces | 1411B. Fair Numbers | Divisible by all non-zero digits |

## Core Patterns
```cpp
int digit = n % 10;
n /= 10;
rev = rev * 10 + digit;
sum += digit;
sum += digit * digit;
```
