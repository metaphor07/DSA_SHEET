// Q4. Minimum Moves to Pick K Ones
// Topic: Positions of ones + median + prefix sum
// Intuition upsolve version

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<long long> pos;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                pos.push_back(i);
            }
        }

        int m = pos.size();

        vector<long long> pref(m + 1, 0);
        for (int i = 0; i < m; i++) {
            pref[i + 1] = pref[i] + pos[i];
        }

        long long ans = LLONG_MAX;

        int minExisting = max(0, k - maxChanges);
        int maxExisting = min(k, m);

        for (int take = minExisting; take <= maxExisting; take++) {
            if (take == 0) {
                ans = min(ans, 2LL * k);
                continue;
            }

            for (int l = 0; l + take - 1 < m; l++) {
                int r = l + take - 1;
                int mid = (l + r) / 2;

                long long median = pos[mid];

                long long leftCount = mid - l;
                long long leftSum = pref[mid] - pref[l];
                long long leftCost = median * leftCount - leftSum;

                long long rightCount = r - mid;
                long long rightSum = pref[r + 1] - pref[mid + 1];
                long long rightCost = rightSum - median * rightCount;

                long long existingMoveCost = leftCost + rightCost;
                long long changeCost = 2LL * (k - take);

                ans = min(ans, existingMoveCost + changeCost);
            }
        }

        return ans;
    }
};
