// Q4. Minimum Cost to Equalize Array
// Status: Red
// Topic: Greedy math + pair deficits + candidate target check
// Time: O(n)
// Space: O(1)

class Solution {
public:
    static const long long MOD = 1000000007LL;

    long long getCost(long long target, vector<int>& nums, long long cost1, long long cost2) {
        long long total = 0;
        long long maxNeed = 0;

        for (int x : nums) {
            long long need = target - x;
            total += need;
            maxNeed = max(maxNeed, need);
        }

        long long pairs = min(total / 2, total - maxNeed);
        long long singles = total - 2 * pairs;

        return pairs * cost2 + singles * cost1;
    }

    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();

        if (n == 1) return 0;

        long long mn = *min_element(nums.begin(), nums.end());
        long long mx = *max_element(nums.begin(), nums.end());

        long long sum = 0;
        for (int x : nums) sum += x;

        if (2LL * cost1 <= cost2 || n == 2) {
            long long ans = 0;

            for (int x : nums) {
                ans += (mx - x) * 1LL * cost1;
            }

            return ans % MOD;
        }

        vector<long long> candidates;
        candidates.push_back(mx);

        long long balance = mx;

        if (n > 2) {
            long long numerator = sum - 2LL * mn;
            long long denominator = n - 2;

            if (numerator > 0) {
                balance = (numerator + denominator - 1) / denominator;
                balance = max(balance, mx);
            }
        }

        for (long long t = balance - 3; t <= balance + 3; t++) {
            if (t >= mx) candidates.push_back(t);
        }

        for (long long t = mx; t <= mx + 3; t++) {
            candidates.push_back(t);
        }

        long long ans = LLONG_MAX;

        for (long long target : candidates) {
            ans = min(ans, getCost(target, nums, cost1, cost2));
        }

        return ans % MOD;
    }
};
