#include <bits/stdc++.h>
using namespace std;

/*
Topic: Digit Math / Divisibility
Pattern: Find next number divisible by all non-zero digits
Time: O(answer gap * digits)
Space: O(1)
*/

bool isFair(long long x) {
    long long temp = x;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit != 0 && x % digit != 0) return false;
        temp /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        while (!isFair(n)) n++;
        cout << n << '\n';
    }
    return 0;
}
