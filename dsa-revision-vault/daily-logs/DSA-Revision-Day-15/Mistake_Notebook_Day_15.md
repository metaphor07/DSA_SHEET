# Mistake Notebook - Day 15

## LC 45 - Jump Game II
**Status:** Red  
**Pattern:** Greedy BFS range

### Mistake
I increased jump count whenever I found a better max reach.

### Correct idea
One jump covers a whole range.

```text
farthest = best reach inside current range.
When current range ends, take one jump.
```

### Memory hook
```text
Jump Game II = BFS levels over index ranges.
```

---

## LC 621 - Task Scheduler
**Status:** Red  
**Pattern:** Greedy frequency formula

### Mistake
Tried simulation, but the logic was incomplete.

### Correct formula
```text
answer = max(total tasks, (maxFreq - 1) * (n + 1) + countMaxFreq)
```

### Memory hook
```text
Most frequent task creates gaps.
Other tasks fill gaps.
```

---

## LC 134 - Gas Station
**Status:** Yellow  
**Pattern:** Greedy reset

### Memory hook
```text
If we fail at i, no station before i can be the answer.
Start from i + 1.
```

---

## LC 253 - Meeting Rooms II
**Status:** Locked / Not Tried  
**Pattern:** Intervals + Min Heap

### Note
Problem was locked on LeetCode, so it was not attempted.
