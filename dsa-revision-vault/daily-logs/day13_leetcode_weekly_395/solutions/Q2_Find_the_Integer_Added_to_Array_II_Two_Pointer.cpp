// Q2. Find the Integer Added to Array II
// Cleaner verification version

class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2, int remove1, int remove2, int x) {
        int p = 0;

        for (int i = 0; i < nums1.size(); i++) {
            if (i == remove1 || i == remove2) continue;

            if (nums1[i] + x != nums2[p]) return false;
            p++;
        }

        return true;
    }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int firstKept = -1;

                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        firstKept = nums1[k];
                        break;
                    }
                }

                int x = nums2[0] - firstKept;

                if (check(nums1, nums2, i, j, x)) {
                    ans = min(ans, x);
                }
            }
        }

        return ans;
    }
};
