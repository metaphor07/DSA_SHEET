// LC 253 is locked on LeetCode.
// Standard solution for reference.

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if (!minHeap.empty() && minHeap.top() <= start) {
                minHeap.pop();
            }

            minHeap.push(end);
        }

        return minHeap.size();
    }
};
