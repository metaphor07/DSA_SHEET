# Pattern: Tree Comparison DFS

## Use when
Two trees/subtrees must be compared together.

## Template
```cpp
bool dfs(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if (p->val != q->val) return false;

    return dfs(p->left, q->left) && dfs(p->right, q->right);
}
```

## Common problems
- LC 100 - Same Tree
- LC 101 - Symmetric Tree
- LC 572 - Subtree of Another Tree
