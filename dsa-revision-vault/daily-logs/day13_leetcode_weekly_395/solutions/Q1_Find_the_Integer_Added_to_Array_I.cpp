// Q1. Find the Integer Added to Array I
// Status: Green
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int mn1 = *min_element(nums1.begin(), nums1.end());
        int mn2 = *min_element(nums2.begin(), nums2.end());
        return mn2 - mn1;
    }
};
