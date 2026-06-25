// Q2. Apply Operations to Make Sum of Array Greater Than or Equal to k
// Topic: Math / enumeration
// Time: O(k)
// Space: O(1)

class Solution {
public:
    int minOperations(int k) {
        int ans = INT_MAX;

        for (int x = 1; x <= k; x++) {
            int increaseOps = x - 1;
            int copies = (k + x - 1) / x; // ceil(k / x)
            int duplicateOps = copies - 1;

            ans = min(ans, increaseOps + duplicateOps);
        }

        return ans;
    }
};
