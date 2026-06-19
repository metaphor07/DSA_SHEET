# Pattern: Prefix Sum Remainder

Use this when the problem asks:

```txt
Count subarrays whose sum is divisible by k
```

## Core idea

Let:

```txt
prefixSum[i] = sum from index 0 to i
```

If two prefix sums have the same remainder:

```txt
prefixSum[a] % k == prefixSum[b] % k
```

Then the subarray between them is divisible by `k`.

## Template

```cpp
vector<int> freq(k, 0);
freq[0] = 1;

int prefixSum = 0;
int count = 0;

for (int num : nums) {
    prefixSum += num;

    int rem = prefixSum % k;
    if (rem < 0) rem += k;

    count += freq[rem];
    freq[rem]++;
}
```

## Why `freq[0] = 1`?

Because a prefix sum itself can be divisible by `k`.

Example:

```txt
nums = [5], k = 5
prefixSum = 5
remainder = 0
```

This should count as one valid subarray.

## Day 02 example

- Q974: Subarray Sums Divisible by K

