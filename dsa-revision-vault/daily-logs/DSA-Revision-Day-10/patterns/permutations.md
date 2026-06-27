# Pattern: Permutations

## Memory hook
Choose one unused number for current position.

## Template
```cpp
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
```
