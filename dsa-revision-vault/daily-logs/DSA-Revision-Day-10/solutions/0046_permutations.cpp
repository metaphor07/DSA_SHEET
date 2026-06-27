class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<int>& used, vector<vector<int>>& ans) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = 1;
            path.push_back(nums[i]);

            dfs(nums, path, used, ans);

            path.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<int> used(nums.size(), 0);
        dfs(nums, path, used, ans);
        return ans;
    }
};
