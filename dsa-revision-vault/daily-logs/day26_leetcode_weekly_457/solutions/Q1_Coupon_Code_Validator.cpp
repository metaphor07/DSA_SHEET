// Q1. Coupon Code Validator
// Topic: string validation + sorting
// Time: O(n log n * L)
// Space: O(n)

class Solution {
public:
    bool isValidCode(string& s) {
        if (s.empty()) return false;

        for (char c : s) {
            if (!isalnum(c) && c != '_') {
                return false;
            }
        }

        return true;
    }

    bool isValidBusinessLine(string& s) {
        return s == "electronics" ||
               s == "grocery" ||
               s == "pharmacy" ||
               s == "restaurant";
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        vector<pair<string, string>> valid;

        for (int i = 0; i < n; i++) {
            if (isActive[i] && isValidCode(code[i]) && isValidBusinessLine(businessLine[i])) {
                valid.push_back({businessLine[i], code[i]});
            }
        }

        sort(valid.begin(), valid.end());

        vector<string> ans;

        for (auto& p : valid) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
