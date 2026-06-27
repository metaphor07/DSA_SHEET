class Solution {
public:
    void dfs(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(path);
            return;
        }

        dfs(idx + 1, nums, path, ans);

        path.push_back(nums[idx]);
        dfs(idx + 1, nums, path, ans);
        path.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, nums, path, ans);
        return ans;
    }
};
