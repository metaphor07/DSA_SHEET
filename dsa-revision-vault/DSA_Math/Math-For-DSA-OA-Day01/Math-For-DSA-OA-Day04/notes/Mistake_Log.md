# Day 04 Mistake Log

## Mistake 1
Problem:
LeetCode 1497

Possible issue:
Using `k - rem` directly.

Fix:
Always use:

```cpp
int need = (k - rem) % k;
```

## Mistake 2
Problem:
LeetCode 1590

Issue:
Hard to derive required previous prefix remainder.

Fix:
Use:

```cpp
int need = (curr - target + p) % p;
```

## Mistake 3
Problem:
Codeforces 1931D

Issue:
Confusing sum and difference conditions.

Fix:
For sum divisible, use complement remainder.
For difference divisible, use same remainder.
