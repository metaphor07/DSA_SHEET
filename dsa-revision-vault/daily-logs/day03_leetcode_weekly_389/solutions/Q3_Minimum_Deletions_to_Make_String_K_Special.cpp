// Q3. Minimum Deletions to Make String K-Special
// Topic: Frequency + greedy enumeration
// Time: O(26 * 26)
// Space: O(26)

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for (char c : word) {
            freq[c - 'a']++;
        }

        int ans = word.size();

        for (int base : freq) {
            if (base == 0) continue;

            int deletions = 0;

            for (int f : freq) {
                if (f == 0) continue;

                if (f < base) {
                    deletions += f;
                } else if (f > base + k) {
                    deletions += f - (base + k);
                }
            }

            ans = min(ans, deletions);
        }

        return ans;
    }
};
