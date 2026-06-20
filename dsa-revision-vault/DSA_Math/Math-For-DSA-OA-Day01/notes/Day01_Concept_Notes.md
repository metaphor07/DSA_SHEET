# Day 01 Concept Notes

## 1. int vs long long

`int` range is approximately -2e9 to 2e9.

Example:
```cpp
int n = 100000;
int sum = n * (n + 1) / 2; // overflow
```

Correct:
```cpp
long long sum = 1LL * n * (n + 1) / 2;
```

## 2. Sum Formula

```cpp
sum(1 to n) = n * (n + 1) / 2
```

Used in:
- Missing number
- Arranging coins
- Counting subarrays
- Counting operations

## 3. Ceil Division

For positive integers:

```cpp
ceil(a / b) = (a + b - 1) / b
```

Do not write:

```cpp
ceil(a / b)
```

because integer division happens first.

## 4. Digit Extraction

```cpp
int digit = x % 10;
x /= 10;
```

Used in:
- Reverse number
- Palindrome number
- Sum of digits

## 5. Binary Search on Answer

When the problem asks maximum/minimum possible value and a condition is monotonic, use binary search.

Examples:
- Sqrt(x): largest `mid` such that `mid * mid <= x`
- Arranging Coins: largest `k` such that `k * (k + 1) / 2 <= n`

## 6. Overflow Safety

Avoid:

```cpp
mid * mid <= x
```

Safer:

```cpp
mid <= x / mid
```

or use:

```cpp
1LL * mid * mid <= x
```
