// Q2. Find the Integer Added to Array II
// Status: Yellow
// Topic: Sorting + remove two elements + verify
// Time: O(n^3)
// Space: O(n)

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> remain;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    remain.push_back(nums1[k]);
                }

                int x = nums2[0] - remain[0];
                bool ok = true;

                for (int k = 0; k < nums2.size(); k++) {
                    if (remain[k] + x != nums2[k]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) ans = min(ans, x);
            }
        }

        return ans;
    }
};
