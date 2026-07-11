// Q2. Minimum Number of Operations to Make Word K-Periodic
// Status: Green
// Topic: Hash map / frequency of blocks
// Time: O(n * k) due to substr copies
// Space: O(n)

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();

        unordered_map<string, int> freq;
        int maxFreq = 0;

        for (int i = 0; i < n; i += k) {
            string block = word.substr(i, k);
            freq[block]++;
            maxFreq = max(maxFreq, freq[block]);
        }

        int totalBlocks = n / k;
        return totalBlocks - maxFreq;
    }
};
