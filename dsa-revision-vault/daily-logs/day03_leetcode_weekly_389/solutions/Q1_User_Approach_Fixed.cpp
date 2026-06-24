// Q1. User approach fixed using set<string>

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.length();

        if (n < 2) return false;

        set<string> st;

        for (int i = 0; i < n - 1; i++) {
            string curr = "";
            curr += s[i];
            curr += s[i + 1];

            if (st.find(curr) != st.end()) {
                return true;
            }

            string rev = "";
            rev += s[i + 1];
            rev += s[i];

            st.insert(rev);
        }

        return false;
    }
};
