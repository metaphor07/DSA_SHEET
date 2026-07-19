// Q3. Transform Binary String Using Subsequence Sort
// Topic: Prefix feasibility + limited '?' assignment
// Time: O(n * q)
// Space: O(n)

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        vector<int> prefZero(n, 0);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefZero[i] = prefZero[i - 1];
            }

            if (s[i] == '0') {
                prefZero[i]++;
            }
        }

        int totalZerosInS = prefZero[n - 1];

        vector<bool> ans;

        for (auto& t : strs) {
            int fixedZero = 0;
            int questionCount = 0;

            for (char ch : t) {
                if (ch == '0') fixedZero++;
                else if (ch == '?') questionCount++;
            }

            bool ok = true;

            if (fixedZero > totalZerosInS || fixedZero + questionCount < totalZerosInS) {
                ok = false;
            }

            int needQuestionAsZero = totalZerosInS - fixedZero;

            int curZero = 0;
            int curQuestion = 0;

            for (int i = 0; i < n && ok; i++) {
                if (t[i] == '0') curZero++;
                else if (t[i] == '?') curQuestion++;

                int maxZeroInPrefix = curZero + min(curQuestion, needQuestionAsZero);

                if (maxZeroInPrefix < prefZero[i]) {
                    ok = false;
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};
