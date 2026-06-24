#include <bits/stdc++.h>
using namespace std;

/*
Topic: LCM
Pattern: lcm(n, 2)
Time: O(1)
Space: O(1)
*/

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n % 2 == 0) ? n : 2 * n;
    }
};
