class Solution {
public:
    bool solve(int start, string& s, unordered_set<string>& dict, vector<int>& dp) {
        if (start == s.size()) return true;

        if (dp[start] != -1) return dp[start];

        string word = "";

        for (int end = start; end < s.size(); end++) {
            word += s[end];

            if (dict.count(word)) {
                if (solve(end + 1, s, dict, dp)) {
                    return dp[start] = true;
                }
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);

        return solve(0, s, dict, dp);
    }
};
