// Q1. Count Dominant Nodes in a Binary Tree
// Topic: Postorder DFS
// Time: O(n)
// Space: O(height)

class Solution {
public:
    int ans;

    int dfs(TreeNode* root) {
        if (root == NULL) {
            return INT_MIN;
        }

        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);

        int childMax = max(leftMax, rightMax);

        if (root->val >= childMax) {
            ans++;
        }

        return max(root->val, childMax);
    }

    int countDominantNodes(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
