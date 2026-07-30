# Mistake Notebook - Day 22

## LC 435 - Non-overlapping Intervals
**Status:** Yellow

### Mistake
Sorted by start time:
```cpp
sort(intervals.begin(), intervals.end());
```

### Correct idea
Sort by end time.

### Memory hook
```text
Earliest ending interval leaves maximum room for future intervals.
This is not merge intervals.
```

---

## LC 981 - Time Based Key-Value Store
**Status:** Yellow

### Correct idea
```text
Each key stores sorted timestamp history.
set = push_back.
get = binary search largest timestamp <= given timestamp.
```

---

## LC 138 - Copy List with Random Pointer
**Status:** Yellow

### HashMap approach
```text
old node -> copied node
```

### Interweaving approach
```text
A -> A' -> B -> B'
old->next is old's copy.
copy->random = old->random->next
```

---

## LC 146 - LRU Cache
**Status:** Red

### Memory hook
```text
Map gives node address.
DLL gives order.
head = most recent.
tail = least recent.
```
