/*
Topic: Basic Math / Simulation
Pattern: Collatz sequence
Time Complexity: O(number of generated terms)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";

        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }

    cout << 1 << "\n";

    return 0;
}
