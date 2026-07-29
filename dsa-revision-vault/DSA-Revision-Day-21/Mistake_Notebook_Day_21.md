# Mistake Notebook - Day 21

## LC 647 - Palindromic Substrings
**Status:** Yellow  
**Pattern:** DP / Memoization / Expand Around Center

### DP state
```text
dp[i][j] = true if s[i...j] is palindrome
```

### Transition
```text
s[i] == s[j] and inside substring is palindrome
```

### Memoization state
```text
solve(i, j) = true if s[i...j] is palindrome
```

### Base case
```text
i >= j => true
```

### Memory hook
```text
Palindrome DP:
Outer chars must match.
Inside must already be palindrome.
```

---

## LC 146 - LRU Cache
**Status:** Red  
**Pattern:** HashMap + Doubly Linked List

### Reason
Needed full implementation.

### Correct idea
```text
Map gives node address.
Doubly linked list gives order.

head side = most recently used
tail side = least recently used
```

### Memory hook
```text
get(key):
    if missing return -1
    move node to head
    return value

put(key,value):
    if exists remove old node
    if full remove tail->prev
    insert new node after head
```
