# Mistake Notebook - Day 06

## LC 543 - Diameter of Binary Tree
**Status:** Red/Yellow  
**Pattern:** DFS height + global answer

### Mistake
I called recursion on left and right child, but ignored the returned height.

Wrong idea:
```cpp
recFun(root->left);
leftm += 1;
recFun(root->right);
rightm += 1;
```

This makes `leftm` and `rightm` almost always just 1, no matter how deep the subtree is.

### Correct intuition
At every node:
```text
leftHeight = height of left subtree
rightHeight = height of right subtree
diameter through current node = leftHeight + rightHeight
height returned to parent = 1 + max(leftHeight, rightHeight)
```

### Memory hook
```text
Diameter problem:
Return height.
Update diameter.
```

More specifically:
```text
left + right = possible answer
1 + max(left, right) = value returned to parent
```

---

## General Tree DFS Mistake Rule

When a recursive function returns something, always store it:

```cpp
int left = dfs(root->left);
int right = dfs(root->right);
```

Do not call recursion and ignore its return value unless the DFS is only doing traversal.
