# Mistake Notebook - Day 07

## LC 98 - Validate Binary Search Tree
**Status:** Red/Yellow  
**Pattern:** DFS with lower and upper bounds

### Mistake
I checked only immediate parent-child relation and tried to use one bound.

Wrong idea:
```cpp
root->val > root->left->val
root->val < root->right->val
```

This fails because BST validity depends on all ancestors, not only the parent.

### Counterexample
```text
      5
     / \
    1   7
       / \
      4   8
```

At node `7`, child `4` is less than `7`, so local check passes.  
But `4` is in the right subtree of `5`, so it must be greater than `5`.

### Correct intuition
Every node must satisfy:

```text
low < node->val < high
```

For left child:
```text
high = root->val
```

For right child:
```text
low = root->val
```

### Memory hook
```text
Validate BST = ancestor boundary problem, not parent-child comparison.
```

---

## LC 110 - Balanced Binary Tree
**Pattern:** DFS height + invalid signal

### Memory hook
```text
Return height if balanced.
Return -1 if unbalanced.
```

---

## LC 230 - Kth Smallest Element in BST
**Pattern:** Inorder traversal

### Memory hook
```text
BST + kth smallest = inorder count.
```
