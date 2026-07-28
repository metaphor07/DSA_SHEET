# Pattern: Median of Two Sorted Arrays

## Valid partition
```text
leftA <= rightB
leftB <= rightA
```

## Median
```text
Odd total:
median = max(leftA, leftB)

Even total:
median = (max(leftA,leftB) + min(rightA,rightB)) / 2
```

## Memory hook
Median = correct partition.
Binary search partition on smaller array.
