// Q3. Count of Unfinished Tasks After Each Shift
// Topic: Prefix sum + upper_bound simulation
// Time: O((n + q) log n)
// Space: O(n)

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        vector<long long> prefix(n);
        prefix[0] = tasks[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + tasks[i];
        }

        long long totalTime = prefix[n - 1];
        long long doneTime = 0;
        vector<int> ans;

        for (int shift : shifts) {
            long long remaining = totalTime - doneTime;

            if (shift >= remaining) {
                ans.push_back(0);
                doneTime = 0;
            } else {
                doneTime += shift;

                int completed = upper_bound(prefix.begin(), prefix.end(), doneTime) - prefix.begin();
                int unfinished = n - completed;

                ans.push_back(unfinished);
            }
        }

        return ans;
    }
};
