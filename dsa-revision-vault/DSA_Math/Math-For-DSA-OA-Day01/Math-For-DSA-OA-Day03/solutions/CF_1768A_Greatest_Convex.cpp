#include <bits/stdc++.h>
using namespace std;

/*
Topic: Math Observation
Pattern: For each k, answer is k - 1
Time: O(t)
Space: O(1)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cout << k - 1 << '\n';
    }
    return 0;
}
