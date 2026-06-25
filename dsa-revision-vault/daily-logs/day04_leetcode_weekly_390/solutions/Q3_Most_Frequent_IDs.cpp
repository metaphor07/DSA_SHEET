// Q3. Most Frequent IDs
// Topic: Hashmap + max heap + lazy deletion
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> currentFreq;
        priority_queue<pair<long long, int>> pq;
        vector<long long> ans;

        for (int i = 0; i < nums.size(); i++) {
            int id = nums[i];
            long long change = freq[i];

            currentFreq[id] += change;
            pq.push({currentFreq[id], id});

            while (!pq.empty()) {
                long long heapFreq = pq.top().first;
                int heapId = pq.top().second;

                if (currentFreq[heapId] == heapFreq) break;

                pq.pop();
            }

            ans.push_back(pq.empty() ? 0 : pq.top().first);
        }

        return ans;
    }
};
