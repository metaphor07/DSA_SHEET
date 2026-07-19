// Q4. Minimum Number of String Groups Through Transformations
// Topic: Even/odd split + canonical cyclic rotation
// Time: O(total length) using Booth algorithm
// Space: O(total length)

class Solution {
public:
    string minRotation(string s) {
        int n = s.size();

        if (n <= 1) return s;

        string ss = s + s;

        int i = 0;
        int j = 1;
        int k = 0;

        while (i < n && j < n && k < n) {
            if (ss[i + k] == ss[j + k]) {
                k++;
            } else if (ss[i + k] > ss[j + k]) {
                i = i + k + 1;
                if (i == j) i++;
                k = 0;
            } else {
                j = j + k + 1;
                if (i == j) j++;
                k = 0;
            }
        }

        int start = min(i, j);
        return ss.substr(start, n);
    }

    int minimumGroups(vector<string>& words) {
        unordered_set<string> groups;

        for (string& word : words) {
            string even = "";
            string odd = "";

            for (int i = 0; i < word.size(); i++) {
                if (i % 2 == 0) even += word[i];
                else odd += word[i];
            }

            string key = minRotation(even) + "#" + minRotation(odd);
            groups.insert(key);
        }

        return groups.size();
    }
};
