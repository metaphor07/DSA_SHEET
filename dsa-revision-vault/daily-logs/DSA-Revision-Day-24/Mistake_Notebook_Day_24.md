# Mistake Notebook - Day 24

## LC 105 - Construct Binary Tree from Preorder and Inorder
**Status:** Yellow  
**Pattern:** Tree Recursion + HashMap

### Correct idea
```text
preorder gives root.
inorder divides left and right subtree.
```

### Memory hook
```text
Preorder: root, left, right
Inorder: left, root, right
```

### Weak point
```text
Recursion boundaries need more practice.
```

---

## LC 23 - Merge k Sorted Lists
**Status:** Green

### Memory hook
```text
Merge pairwise like merge sort.
Total levels = log k.
Each level touches all nodes once.
Time = O(N log k).
```

---

## LC 279 - Perfect Squares
**Status:** Green

### Memory hook
```text
solve(n) = minimum squares needed for n.
Try n-1, n-4, n-9, ...
Base solve(0)=0.
```
