// Q4. Minimize Manhattan Distances
// Topic: Manhattan distance transform + multiset
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> sumSet;
        multiset<int> diffSet;

        for (auto &p : points) {
            int x = p[0];
            int y = p[1];

            sumSet.insert(x + y);
            diffSet.insert(x - y);
        }

        int ans = INT_MAX;

        for (auto &p : points) {
            int x = p[0];
            int y = p[1];

            int sumVal = x + y;
            int diffVal = x - y;

            // Remove exactly one occurrence.
            sumSet.erase(sumSet.find(sumVal));
            diffSet.erase(diffSet.find(diffVal));

            int maxSum = *sumSet.rbegin();
            int minSum = *sumSet.begin();

            int maxDiff = *diffSet.rbegin();
            int minDiff = *diffSet.begin();

            int curr = max(maxSum - minSum, maxDiff - minDiff);

            ans = min(ans, curr);

            // Put the point back for next iteration.
            sumSet.insert(sumVal);
            diffSet.insert(diffVal);
        }

        return ans;
    }
};
