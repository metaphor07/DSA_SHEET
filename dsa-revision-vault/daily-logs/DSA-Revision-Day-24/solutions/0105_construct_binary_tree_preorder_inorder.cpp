class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inorderIndex[rootVal];

        root->left = build(preorder, inStart, idx - 1);
        root->right = build(preorder, idx + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};
