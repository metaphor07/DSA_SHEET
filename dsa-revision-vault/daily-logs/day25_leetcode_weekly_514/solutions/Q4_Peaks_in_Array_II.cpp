// Q4. Peaks in Array II
// Fenwick tree + local update

class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        idx++;
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++;
        int sum = 0;

        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }

        return sum;
    }

    int rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};

class Solution {
public:
    bool isPeak(int i, vector<int>& nums) {
        int n = nums.size();
        if (i <= 0 || i >= n - 1) return false;
        return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        Fenwick fw(n);
        vector<int> peak(n, 0);

        for (int i = 1; i < n - 1; i++) {
            if (isPeak(i, nums)) {
                peak[i] = 1;
                fw.update(i, 1);
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2];
                ans.push_back(fw.rangeQuery(l + 1, r - 1));
            } else {
                int idx = q[1], val = q[2];

                for (int i = idx - 1; i <= idx + 1; i++) {
                    if (i > 0 && i < n - 1 && peak[i]) {
                        fw.update(i, -1);
                        peak[i] = 0;
                    }
                }

                nums[idx] = val;

                for (int i = idx - 1; i <= idx + 1; i++) {
                    if (i > 0 && i < n - 1 && isPeak(i, nums)) {
                        peak[i] = 1;
                        fw.update(i, 1);
                    }
                }
            }
        }

        return ans;
    }
};
