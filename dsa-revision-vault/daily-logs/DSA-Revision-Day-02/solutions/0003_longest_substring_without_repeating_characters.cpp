// LeetCode 3: Longest Substring Without Repeating Characters
// Pattern: Sliding window + frequency
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            while (freq[s[right]] > 0) {
                freq[s[left]]--;
                left++;
            }

            freq[s[right]]++;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

