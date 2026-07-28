class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int usedDays = 1;
        int curr = 0;

        for (int w : weights) {
            if (curr + w > capacity) {
                usedDays++;
                curr = 0;
            }

            curr += w;
        }

        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
