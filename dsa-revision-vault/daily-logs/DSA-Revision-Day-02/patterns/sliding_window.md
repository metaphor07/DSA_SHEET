# Pattern: Sliding Window

Use this when the problem asks about a contiguous subarray or substring.

## Type 1: Fixed-size window

Use when window size is already given.

Example:

```txt
Maximum sum of subarray of size k
```

## Type 2: Variable-size window

Use when we need longest/minimum window satisfying a condition.

Template:

```cpp
int left = 0;

for (int right = 0; right < n; right++) {
    // add nums[right] / s[right]

    while (window_is_invalid) {
        // remove nums[left] / s[left]
        left++;
    }

    // update answer
}
```

## Longest window

Shrink while invalid, then update answer.

```txt
Longest valid window => update after fixing invalid window.
```

## Minimum window

Update answer while window is valid, then shrink.

```txt
Minimum valid window => update while shrinking valid window.
```

## Day 02 examples

- Q209: minimum length with sum at least target
- Q424: longest window where replacements needed are at most k
- Q3: longest window with no repeated characters

