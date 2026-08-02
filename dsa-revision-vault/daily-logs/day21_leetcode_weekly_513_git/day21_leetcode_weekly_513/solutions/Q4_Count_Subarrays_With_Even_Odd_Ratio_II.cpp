// Q4. Count Subarrays With Even Odd Ratio II
// Topic: Prefix sum + Fenwick tree
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                pref[i + 1] = pref[i] + b;
            } else {
                pref[i + 1] = pref[i] - a;
            }
        }

        vector<long long> values = pref;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int m = values.size();
        vector<long long> bit(m + 2, 0);

        auto update = [&](int idx) {
            while (idx <= m) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            long long sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        };

        long long ans = 0;

        for (int j = 0; j <= n; j++) {
            int idx = lower_bound(values.begin(), values.end(), pref[j]) - values.begin() + 1;

            long long previousPrefixes = j;
            long long smallerPrefixes = query(idx - 1);

            ans += previousPrefixes - smallerPrefixes;

            update(idx);
        }

        return ans;
    }
};
