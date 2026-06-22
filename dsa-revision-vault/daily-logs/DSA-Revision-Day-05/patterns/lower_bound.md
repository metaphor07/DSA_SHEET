# Pattern: Lower Bound

## Meaning
Find the first index where:
```text
nums[index] >= target
```

## Template
```cpp
int l = 0, r = nums.size();

while (l < r) {
    int mid = l + (r - l) / 2;

    if (nums[mid] < target) l = mid + 1;
    else r = mid;
}

return l;
```
