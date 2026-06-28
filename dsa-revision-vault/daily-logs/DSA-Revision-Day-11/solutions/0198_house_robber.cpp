class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;

        for (int x : nums) {
            int curr = max(prev1, x + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
