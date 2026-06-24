class Solution {
public:
    int count = 0;
    int answer = -1;

    void inorder(TreeNode* root, int k) {
        if (root == nullptr || answer != -1) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            answer = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return answer;
    }
};
