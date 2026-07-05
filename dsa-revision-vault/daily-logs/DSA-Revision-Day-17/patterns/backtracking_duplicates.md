# Pattern: Backtracking with Duplicates

Used in:
- LC 90 - Subsets II
- LC 40 - Combination Sum II

## Rule
Sort first.

Then skip duplicates at the same recursion level:

```cpp
if (i > start && nums[i] == nums[i - 1]) continue;
```

## Memory hook
Same level duplicate choice creates duplicate answer.
