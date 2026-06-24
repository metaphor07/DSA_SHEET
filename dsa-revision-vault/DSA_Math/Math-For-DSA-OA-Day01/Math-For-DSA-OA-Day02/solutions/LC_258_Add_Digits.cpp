#include <bits/stdc++.h>
using namespace std;

/*
Topic: Digit Math
Pattern: Digital root
Time: O(1)
Space: O(1)
*/

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};
