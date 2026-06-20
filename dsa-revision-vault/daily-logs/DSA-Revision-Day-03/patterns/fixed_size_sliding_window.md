# Pattern: Fixed-Size Sliding Window

## Use when
The window length is fixed or must equal a specific length.

## Common problems
- LC 567 - Permutation in String
- Find anagrams
- Maximum sum subarray of size K

## Template
```cpp
for (int r = 0; r < n; r++) {
    add(nums[r]);

    if (r >= k) {
        remove(nums[r - k]);
    }

    if (window_is_valid) {
        update_answer();
    }
}
```

## Key idea
The window size should be exactly `k`.
