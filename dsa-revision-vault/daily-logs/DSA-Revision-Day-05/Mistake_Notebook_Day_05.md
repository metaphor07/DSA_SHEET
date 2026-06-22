# Mistake Notebook - Day 05

## LC 33 - Search in Rotated Sorted Array
**Status:** Yellow/Red  
**Pattern:** Modified binary search

### Mistake
I tried to create direct complicated conditions using `nums[mid]`, `target`, `nums[left]`, and `nums[right]`.

### Correct intuition
At every step, at least one half is sorted.

Steps:
1. Check whether left half is sorted.
2. If target lies inside sorted half, search there.
3. Otherwise search the other half.

### Memory hook
```text
Find sorted half first.
Then decide if target lies inside that half.
```

---

## LC 875 - Koko Eating Bananas
**Status:** Yellow  
**Pattern:** Binary search on answer

### Mistake / Difficulty
I had the brute force idea: try speed from `1` to `max(piles)`.

But optimal is binary search because if speed `k` works, every speed greater than `k` also works.

### Memory hook
```text
Can I do it with mid?
Yes -> save answer, search left
No  -> search right
```

### Important formula
```cpp
hours += (pile + speed - 1) / speed;
```
