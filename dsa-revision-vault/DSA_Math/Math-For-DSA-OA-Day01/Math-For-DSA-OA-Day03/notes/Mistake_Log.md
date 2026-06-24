# Day 03 Mistake Log

## LCM Overflow
Wrong:
```cpp
a * b / gcd(a, b)
```

Correct:
```cpp
1LL * a / gcd(a, b) * b
```

## GCD of Strings
Always check:
```cpp
str1 + str2 == str2 + str1
```

## GCD of Frequencies
For grouping problems, take GCD of all frequencies.
