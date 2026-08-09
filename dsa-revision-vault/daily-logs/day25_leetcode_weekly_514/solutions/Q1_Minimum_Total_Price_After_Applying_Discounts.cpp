// Q1. Minimum Total Price After Applying Discounts

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        double ans = 0.0;
        int n = prices.size(), m = discounts.size();
        int i = 0;

        while (i < n && i < m) {
            ans += prices[i] * (100.0 - discounts[i]) / 100.0;
            i++;
        }

        while (i < n) {
            ans += prices[i];
            i++;
        }

        return ans;
    }
};
