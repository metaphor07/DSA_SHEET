# Day 05 Concept Notes - Prefix Sum + Math

## 1. Prefix Sum

Prefix sum stores cumulative sum from the start.

```cpp
prefix[i + 1] = prefix[i] + nums[i];
```

For range sum from `l` to `r`:

```cpp
sum = prefix[r + 1] - prefix[l];
```

## 2. Pivot Index

For each index:

```cpp
right = total - left - nums[i];
```

If:

```cpp
left == right
```

then index `i` is pivot.

## 3. Subarray Sum Equals K

For current prefix sum `curr`, we need previous prefix:

```cpp
curr - k
```

Because:

```text
curr - previousPrefix = k
```

So:

```cpp
ans += freq[curr - k];
freq[curr]++;
```

## 4. Important: Odd Sum Subarrays

A subarray sum is odd when current prefix parity and previous prefix parity are different.

Initial empty prefix is even:

```cpp
even = 1;
odd = 0;
```

If current prefix is even:

```cpp
ans += odd;
even++;
```

If current prefix is odd:

```cpp
ans += even;
odd++;
```
