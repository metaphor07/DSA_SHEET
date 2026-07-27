// Q2. Minimum Swaps to Sort by Digit Sum
// Topic: Cycle decomposition
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({digitSum(nums[i]), nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;

                int originalIndex = get<2>(arr[j]);
                j = originalIndex;

                cycleSize++;
            }

            swaps += max(0, cycleSize - 1);
        }

        return swaps;
    }
};
