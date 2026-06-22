# Pattern: Binary Search on Answer

## Use when
You need minimum/maximum possible value satisfying a condition.

## Requirement
There must be monotonic behavior:

```text
false false false true true true
```

## Template for minimum valid answer
```cpp
int l = low, r = high;
int ans = high;

while (l <= r) {
    int mid = l + (r - l) / 2;

    if (can(mid)) {
        ans = mid;
        r = mid - 1;
    } else {
        l = mid + 1;
    }
}

return ans;
```
