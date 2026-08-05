// Q1. Generate Tag for Video Caption
// Topic: String simulation
// Time: O(n)
// Space: O(n)

class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";

        bool newWord = true;
        bool firstWord = true;

        for (char ch : caption) {
            if (!isalpha(ch)) {
                newWord = true;
                continue;
            }

            ch = tolower(ch);

            if (newWord) {
                if (!firstWord) {
                    ch = toupper(ch);
                }

                firstWord = false;
                newWord = false;
            }

            ans.push_back(ch);

            if (ans.size() == 100) {
                break;
            }
        }

        return ans;
    }
};
