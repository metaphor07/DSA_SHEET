// Q1. Valid Word
// Status: Green
// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool isValid(string word) {
        int n = word.size();
        if (n < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word) {
            if (isdigit(ch)) {
                continue;
            } else if (isalpha(ch)) {
                if (isVowel(ch)) hasVowel = true;
                else hasConsonant = true;
            } else {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
};
