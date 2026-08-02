# Q3 User Code Fixes

Initial idea was correct, but these bugs were present:

1. Missing type for k:

bool check(vector<int>& nums, k, int start, int end)

should be:

bool check(vector<int>& nums, int k, int start, int end)

2. max_element/min_element end iterator is exclusive.

To include index end, use:

nums.begin() + end + 1

3. Need memoization.

Without dp[start], the recursion repeats same states.

4. Better approach:
Do not call check every time.
Maintain maxEle and minEle while expanding end.

This reduces complexity from O(n^3) to O(n^2).
