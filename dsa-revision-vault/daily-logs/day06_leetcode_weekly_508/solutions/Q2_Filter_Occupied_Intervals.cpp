// Q2. Filter Occupied Intervals
// Status: Yellow
// Key idea: sort + merge + subtract [freeStart, freeEnd]
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        for (auto &inter : occupiedIntervals) {
            int start = inter[0];
            int end = inter[1];

            if (merged.empty() || start > merged.back()[1] + 1) {
                merged.push_back({start, end});
            } else {
                merged.back()[1] = max(merged.back()[1], end);
            }
        }

        vector<vector<int>> ans;

        for (auto &inter : merged) {
            int l = inter[0];
            int r = inter[1];

            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            } else {
                if (l < freeStart) {
                    ans.push_back({l, freeStart - 1});
                }
                if (r > freeEnd) {
                    ans.push_back({freeEnd + 1, r});
                }
            }
        }

        return ans;
    }
};
