# Mistake Notebook - Day 17

## LC 90 - Subsets II
**Status:** Yellow  
**Pattern:** Backtracking + duplicate skip

### Memory hook
```text
Sort first.
At same recursion level, skip duplicate choices.
```

### Duplicate skip rule
```cpp
if (i > start && nums[i] == nums[i - 1]) continue;
```

---

## LC 494 - Target Sum
**Status:** Yellow  
**Pattern:** Subset sum transform

### Correct transform
```text
positiveSum - negativeSum = target
positiveSum + negativeSum = total
positiveSum = (total + target) / 2
```

### Important checks
```text
if abs(target) > total return 0
if (total + target) is odd return 0
```

### Memory hook
```text
Target Sum becomes count subset sum.
```

---

## LC 97 - Interleaving String
**Status:** Yellow  
**Pattern:** 2D String DP

### State
```text
dp[i][j] = true if s3[0...i+j-1]
can be formed using s1[0...i-1] and s2[0...j-1].
```

### Memory hook
```text
s3 index = i + j - 1.
Take from s1 or take from s2.
```
