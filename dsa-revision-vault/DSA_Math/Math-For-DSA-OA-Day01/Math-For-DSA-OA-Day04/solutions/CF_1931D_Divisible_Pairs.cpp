#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<pair<long long, long long>, long long> freq;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long rx = a[i] % x;
            long long ry = a[i] % y;

            long long needX = (x - rx) % x;
            long long needY = ry;

            ans += freq[{needX, needY}];

            freq[{rx, ry}]++;
        }

        cout << ans << '\n';
    }

    return 0;
}
