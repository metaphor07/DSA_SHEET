#include <bits/stdc++.h>
using namespace std;

/*
Topic: GCD of Frequencies
Pattern: Common group size must divide all frequencies
Time: O(n)
Space: O(unique cards)
*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int card : deck) freq[card]++;

        int g = 0;
        for (auto &p : freq) {
            g = gcd(g, p.second);
        }

        return g >= 2;
    }
};
