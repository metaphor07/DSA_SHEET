# Mistake Notebook - Day 10

## LC 46 - Permutations
**Status:** Yellow  
**Pattern:** Backtracking with used array

### Memory hook
```text
Permutation = choose one unused number for current position.
```

---

## LC 131 - Palindrome Partitioning
**Status:** Red  
**Pattern:** Backtracking + palindrome check

### Correct intuition
At every index, try every possible substring.

If substring is palindrome:
1. Choose it.
2. Recurse from next index.
3. Backtrack.

### Memory hook
```text
Palindrome Partitioning = cut the string at every valid palindrome.
```

---

## LC 79 - Word Search
**Status:** Green  
**Pattern:** Grid backtracking

### Memory hook
```text
Match current char.
Mark visited.
Explore 4 directions.
Unmark while returning.
```

---

## Revision Problems

### LC 57 - Insert Interval
**Status:** Green  
```text
Before overlap -> merge overlap -> after overlap.
```

### LC 133 - Clone Graph
**Status:** Green  
```text
old node -> cloned node map.
```

### LC 215 - Kth Largest Element
**Status:** Green  
```text
kth largest = index n-k in sorted ascending order.
```
