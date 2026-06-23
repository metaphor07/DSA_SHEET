# Pattern: Tree DFS Return-Based Recursion

## Use when
The parent node needs information from its children.

## Common returned values
- height
- depth
- subtree sum
- balanced/unbalanced status
- path length

## Template
```cpp
int dfs(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    return 1 + max(left, right);
}
```

## Memory hook
Child returns useful information to parent.
