# Mistake Notebook - Day 19

## LC 743 - Network Delay Time
**Status:** Yellow  
**Pattern:** Dijkstra

### Correct idea
```text
No indegree.
This is not dependency ordering.
This is weighted shortest path.
Use Dijkstra.
```

### Memory hook
```text
Indegree -> Topological Sort.
Weighted shortest path -> Dijkstra.
```

---

## LC 4 - Median of Two Sorted Arrays
**Status:** Red  
**Pattern:** Binary Search Partition

### Memory hook
```text
Binary search partition on smaller array.

Valid partition:
leftA <= rightB
leftB <= rightA

Odd total:
median = max(leftA, leftB)

Even total:
median = average of max left and min right
```

---

## LC 658 - Find K Closest Elements
**Status:** Yellow  
**Pattern:** Binary Search Window

### Mistake
Started from one closest index and expanded with two pointers.

### Correct idea
```text
The answer is always a continuous sorted window of size k.
Binary search the starting index of the best window.
```

---

## LC 767 - Reorganize String
**Status:** Red  
**Pattern:** Max Heap / Greedy

### Mistakes
```text
Accessed ans[ans.size()-1] when ans may be empty.
Erased from unordered_map during range loop.
Returned "" too early when current char matched previous char.
Greedy was not based on max frequency.
```

### Correct memory hook
```text
Most frequent character is the danger.
If maxFreq > (n+1)/2, impossible.
Otherwise use max heap and always pick top two different chars.
```
