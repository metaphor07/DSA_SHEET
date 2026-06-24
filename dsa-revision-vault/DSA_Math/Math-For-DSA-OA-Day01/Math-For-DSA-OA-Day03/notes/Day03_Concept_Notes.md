# Day 03 Concept Notes - GCD and LCM

## GCD
GCD is the greatest number that divides two numbers completely.

```cpp
gcd(12, 18) = 6
```

## Euclidean Algorithm
```cpp
int gcdEuclid(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
```

## GCD of Array
```cpp
int g = nums[0];
for (int x : nums) {
    g = gcd(g, x);
}
```

## LCM
```cpp
long long l = 1LL * a / gcd(a, b) * b;
```

## GCD of Strings
```cpp
if (str1 + str2 != str2 + str1) return "";
return str1.substr(0, gcd(str1.size(), str2.size()));
```

## GCD of Frequencies
If all frequencies have GCD >= 2, grouping is possible.
