# Pattern: Find K Closest Elements

## Correct idea
The answer is a sorted window of size k.

Search start index:
```text
low = 0
high = n - k
```

Condition:
```text
if x - arr[mid] > arr[mid + k] - x:
    low = mid + 1
else:
    high = mid
```

## Memory hook
Binary search the window start.
