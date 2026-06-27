# Pattern: Subsets

## Memory hook
Every element has two choices: take or skip.

## Template
```cpp
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
```
