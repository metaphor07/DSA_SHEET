# Math for DSA/OA - Day 04

## Topic
Divisibility and Remainders

## Concepts Covered
- Divisibility using `%`
- Remainder grouping
- Complement remainder
- Negative modulo normalization
- Pairing by remainder
- Prefix remainder hashmap
- Sum divisible condition
- Difference divisible condition

## Problems

| # | Platform | Problem | Concept |
|---|----------|---------|---------|
| 1 | LeetCode | 1010. Pairs of Songs With Total Durations Divisible by 60 | Pair count by complement remainder |
| 2 | LeetCode | 1497. Check If Array Pairs Are Divisible by k | Pairing all elements |
| 3 | LeetCode | 1590. Make Sum Divisible by P | Prefix remainder + shortest removal |
| 4 | Codeforces | 1931D. Divisible Pairs | Two remainder conditions |
| 5 | Codeforces | 2093C. Simple Repetition | Divisibility observation |

## Core Patterns

```cpp
// Normalize negative modulo
int rem = ((x % k) + k) % k;

// Complement for sum divisible by k
int need = (k - rem) % k;

// Pair counting
ans += freq[need];
freq[rem]++;

// Difference divisible by k
a % k == b % k
```

## Important Revision

LeetCode 1590 should be revised again.

Main line:

```cpp
int need = (curr - target + p) % p;
```
