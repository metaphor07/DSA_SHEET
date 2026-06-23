// Q2. Mark Elements on Array by Performing Queries
// Time: O(n log n + q), Space: O(n)

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<pair<int, int>> arr;
        long long totalSum = 0;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
            totalSum += nums[i];
        }

        sort(arr.begin(), arr.end());

        vector<bool> marked(n, false);
        vector<long long> ans;
        int ptr = 0;

        for (auto &q : queries) {
            int idx = q[0];
            int k = q[1];

            if (!marked[idx]) {
                marked[idx] = true;
                totalSum -= nums[idx];
            }

            while (k > 0 && ptr < n) {
                int id = arr[ptr].second;

                if (!marked[id]) {
                    marked[id] = true;
                    totalSum -= nums[id];
                    k--;
                }

                ptr++;
            }

            ans.push_back(totalSum);
        }

        return ans;
    }
};
