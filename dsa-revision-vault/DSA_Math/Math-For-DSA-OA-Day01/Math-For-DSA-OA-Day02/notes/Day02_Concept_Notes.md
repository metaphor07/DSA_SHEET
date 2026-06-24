# Day 02 Concept Notes - Digit Math

## Last Digit
```cpp
int digit = n % 10;
```

## Remove Last Digit
```cpp
n /= 10;
```

## Process Digits
```cpp
while (n > 0) {
    int digit = n % 10;
    n /= 10;
}
```

## Reverse Number
```cpp
rev = rev * 10 + digit;
```

## Overflow Check
```cpp
if (rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0;
```

## Digital Root
```cpp
if (num == 0) return 0;
return 1 + (num - 1) % 9;
```

## Common Mistakes
- Missing `n /= 10`
- Dividing by digit 0
- Not preserving original number
- Forgetting overflow in reverse integer
