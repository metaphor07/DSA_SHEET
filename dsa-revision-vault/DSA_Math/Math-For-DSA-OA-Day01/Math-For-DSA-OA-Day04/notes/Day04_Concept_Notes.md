# Day 04 Concept Notes - Divisibility and Remainders

## 1. Divisibility

A number `a` is divisible by `b` if:

```cpp
a % b == 0
```

## 2. Negative Modulo

In C++, negative modulo can be negative.

Correct normalized remainder:

```cpp
int rem = ((x % k) + k) % k;
```

## 3. Pair Sum Divisible by k

If:

```cpp
a % k = rem
```

then `b` needs:

```cpp
need = (k - rem) % k;
```

## 4. Same Remainder Means Difference Divisible

If:

```cpp
a % k == b % k
```

then:

```cpp
(a - b) % k == 0
```

## 5. LeetCode 1590 Pattern

Let:

```cpp
target = totalSum % p;
```

Need to remove smallest subarray with remainder `target`.

For current prefix remainder `curr`:

```cpp
need = (curr - target + p) % p;
```

## 6. Codeforces 1931D Pattern

Conditions:

```text
(a[i] + a[j]) % x == 0
(a[i] - a[j]) % y == 0
```

For current value `v`:

```cpp
rx = v % x;
ry = v % y;

needX = (x - rx) % x;
needY = ry;
```
