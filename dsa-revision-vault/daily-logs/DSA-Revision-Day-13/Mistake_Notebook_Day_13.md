# Mistake Notebook - Day 13

## LC 19 - Remove Nth Node From End of List
**Status:** Yellow  
**Pattern:** Dummy node + two pointers

### Memory hook
```text
Dummy + fast n steps ahead + move together.
Slow stops before delete node.
```

---

## LC 143 - Reorder List
**Status:** Yellow  
**Pattern:** Middle + reverse second half + merge alternately

### Memory hook
```text
Middle -> reverse second half -> merge alternately.
```

### Critical coding rule
Always save next pointers before rewiring:

```cpp
ListNode* temp1 = first->next;
ListNode* temp2 = second->next;
```

---

## LC 139 - Word Break
**Status:** Red  
**Pattern:** Cut-based DP

### Carry-over memory hook
```text
Word Break = try every cut.
dp[i] is true if s[0...i-1] can be segmented.
```
