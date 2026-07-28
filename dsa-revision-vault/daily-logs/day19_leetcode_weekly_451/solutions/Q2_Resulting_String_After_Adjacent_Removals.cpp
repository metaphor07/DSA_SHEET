// Q2. Resulting String After Adjacent Removals
// Topic: Stack
// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool isConsecutive(char a, char b) {
        int diff = abs(a - b);
        return diff == 1 || diff == 25;
    }

    string resultingString(string s) {
        string st = "";

        for (char ch : s) {
            if (!st.empty() && isConsecutive(st.back(), ch)) {
                st.pop_back();
            } else {
                st.push_back(ch);
            }
        }

        return st;
    }
};
