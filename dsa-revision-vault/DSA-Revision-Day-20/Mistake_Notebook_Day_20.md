# Mistake Notebook - Day 20

## LC 332 - Reconstruct Itinerary
**Status:** Yellow  
**Pattern:** DFS / Euler Path

### Reason
Euler path idea is new. The important part is understanding why we add airport after DFS and reverse the answer.

### Correct idea
```text
Tickets = directed edges.
Use every ticket exactly once = Euler path.
Use min heap for lexical order.
Add airport after exploring all outgoing edges.
Reverse answer at the end.
```

### Memory hook
```text
Keep going until stuck.
When stuck, add airport.
Reverse final path.
```

---

## LC 767 - Reorganize String
**Status:** Red

```text
Most frequent character is the danger.
If maxFreq > (n+1)/2, impossible.
Otherwise use max heap and always pick top two different chars.
```

---

## LC 4 - Median of Two Sorted Arrays
**Status:** Red

```text
Binary search partition on smaller array.
Valid partition:
leftA <= rightB
leftB <= rightA
```

---

## LC 658 - Find K Closest Elements
**Status:** Yellow

```text
Answer is a window of size k.
Binary search the window start from 0 to n-k.
```
