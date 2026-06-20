// Q2. Count Days Without Meetings
// Topic: Sorting + Interval Merge
// Time: O(n log n)
// Space: O(1) extra apart from sorting

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        long long busy = 0;
        int start = meetings[0][0];
        int end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            int s = meetings[i][0];
            int e = meetings[i][1];

            if (s <= end + 1) {
                end = max(end, e);
            } else {
                busy += end - start + 1;
                start = s;
                end = e;
            }
        }

        busy += end - start + 1;

        return days - busy;
    }
};
