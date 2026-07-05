// Q3. Divisible Game
// Status: Red
// Topic: Divisors + compressed Kadane

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        const long long MOD = 1e9 + 7;

        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int d = 2; 1LL * d * d <= x; d++) {
                if (x % d == 0) {
                    pos[d].push_back(i);

                    int other = x / d;
                    if (other != d && other > 1) {
                        pos[other].push_back(i);
                    }
                }
            }

            if (x > 1) {
                pos[x].push_back(i);
            }
        }

        long long bestDiff = LLONG_MIN;
        int bestK = 2;

        for (auto &entry : pos) {
            int k = entry.first;
            vector<int>& indices = entry.second;

            long long cur = LLONG_MIN;
            long long bestForK = LLONG_MIN;

            int prev = -1;

            for (int idx : indices) {
                long long val = nums[idx];

                if (prev == -1) {
                    cur = val;
                } else {
                    long long gapSum = pref[idx] - pref[prev + 1];
                    long long gapCost = -gapSum;

                    cur = max(val, cur + gapCost + val);
                }

                bestForK = max(bestForK, cur);
                prev = idx;
            }

            if (bestForK > bestDiff) {
                bestDiff = bestForK;
                bestK = k;
            } else if (bestForK == bestDiff && k < bestK) {
                bestK = k;
            }
        }

        if (pos.empty()) {
            bestDiff = -1;
            bestK = 2;
        }

        long long ans = ((bestDiff % MOD + MOD) % MOD) * bestK % MOD;
        return (int)ans;
    }
};
