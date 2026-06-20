# Pattern: Minimum Window

## Use when
You need the shortest substring/subarray satisfying a condition.

## Template
```cpp
for (int r = 0; r < n; r++) {
    add(s[r]);

    while (window_is_valid) {
        update_min_answer();
        remove(s[l]);
        l++;
    }
}
```

## Difference from longest-window problems
For longest window:
- shrink when invalid
- update answer when valid

For minimum window:
- expand until valid
- shrink while valid
- update answer inside shrinking loop
