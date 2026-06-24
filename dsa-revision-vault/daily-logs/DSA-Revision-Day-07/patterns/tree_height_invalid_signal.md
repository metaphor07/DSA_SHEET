# Pattern: Tree Height with Invalid Signal

## Use when
A subtree can become invalid and you want to stop early.

## Common problem
- LC 110 - Balanced Binary Tree

## Template
```cpp
int dfs(TreeNode* root) {
    if (!root) return 0;

    int left = dfs(root->left);
    if (left == -1) return -1;

    int right = dfs(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return 1 + max(left, right);
}
```

## Memory hook
Return height when valid.  
Return -1 when invalid.
