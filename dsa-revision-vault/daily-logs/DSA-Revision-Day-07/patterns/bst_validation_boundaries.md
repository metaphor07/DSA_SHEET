# Pattern: BST Validation with Boundaries

## Use when
You need to verify whether a binary tree is a valid BST.

## Key rule
Every node has a valid range:

```text
low < node->val < high
```

## Template
```cpp
bool isValid(TreeNode* root, long long low, long long high) {
    if (root == nullptr) return true;

    if (root->val <= low || root->val >= high) return false;

    return isValid(root->left, low, root->val) &&
           isValid(root->right, root->val, high);
}
```

## Why long long?
Node values can be `INT_MIN` or `INT_MAX`, so use `LLONG_MIN` and `LLONG_MAX`.
