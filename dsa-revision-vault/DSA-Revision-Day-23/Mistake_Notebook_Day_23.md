# Mistake Notebook - Day 23

## LC 853 - Car Fleet
**Status:** Yellow  
**Pattern:** Greedy / Stack-like processing

### Mistakes
```text
Used integer ceil time instead of exact double time.
Sorted by position ascending.
Used unnecessary stack logic.
```

### Correct idea
```text
Sort by position descending.
Process closest to target first.
If current time > slowest time ahead, it forms a new fleet.
Else, it catches the fleet ahead.
```

### Memory hook
```text
Car Fleet:
Sort closest to target first.
Slower time ahead absorbs faster car behind.
```

---

## LC 918 - Maximum Sum Circular Subarray
**Status:** Yellow  
**Pattern:** Kadane Variant

### Correct idea
```text
Answer is either:
1. normal Kadane max
2. totalSum - Kadane min
```

### Exception
```text
If all numbers are negative, return normal max.
```

### Memory hook
```text
Circular max = total sum - minimum middle subarray.
```
