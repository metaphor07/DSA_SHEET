// LC 271 is locked on LeetCode.
// Standard approach for reference.

class Codec {
public:
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));

            j++;
            ans.push_back(s.substr(j, len));

            i = j + len;
        }

        return ans;
    }
};
