// Q4. Simple version for understanding
// Use only if constraints are small.
// Time: O(total length * max word length)

class Solution {
public:
    string minRotation(string s) {
        int n = s.size();

        if (n <= 1) return s;

        string best = s;

        for (int i = 1; i < n; i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            best = min(best, rotated);
        }

        return best;
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
