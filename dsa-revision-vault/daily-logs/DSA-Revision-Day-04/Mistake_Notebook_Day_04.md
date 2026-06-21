# Mistake Notebook - Day 04

## LC 84 - Largest Rectangle in Histogram
**Status:** Red/Yellow  
**Pattern:** Monotonic increasing stack

### Mistake / Difficulty
The core intuition is hard:
For each bar, treat it as the minimum height of a rectangle and find how far it can extend left and right.

### Memory hook
When a smaller height arrives:
- current index = next smaller on right
- new stack top after pop = previous smaller on left
- area = popped height * width

### Formula
```text
width = right - left - 1
area = height * width
```

---

## LC 739 - Daily Temperatures
**Pattern:** Monotonic decreasing stack

### Memory hook
Keep indexes whose warmer day is not found yet.  
When current temperature is greater than stack top temperature, current index is the answer for stack top.

---

## Stack Pattern Summary
Basic stack:
- parentheses
- undo operations
- expression evaluation

Monotonic stack:
- next greater element
- next smaller element
- daily temperatures
- histogram
