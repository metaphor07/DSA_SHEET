// Q4. Find Subarray With Bitwise AND Closest to K
// Topic: Bitwise AND + distinct AND values ending at each index
// Time: O(n * 32) approximately
// Space: O(32)

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;

        // prev stores all distinct AND values of subarrays ending at previous index.
        vector<int> prev;

        for (int x : nums) {
            vector<int> curr;
            curr.push_back(x);

            for (int val : prev) {
                curr.push_back(val & x);
            }

            sort(curr.begin(), curr.end());
            curr.erase(unique(curr.begin(), curr.end()), curr.end());

            for (int val : curr) {
                ans = min(ans, abs(val - k));
            }

            prev = curr;
        }

        return ans;
    }
};
