# Pattern: BST Inorder Traversal

## Key fact
Inorder traversal of BST gives values in sorted order.

```text
left -> root -> right
```

## Used in
- Kth smallest element
- Validate BST using sorted order
- Convert BST to sorted list

## Template
```cpp
void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    visit(root);
    inorder(root->right);
}
```
