// The Catering Challenge
// Greedy + max heap
// Initial penalty = sum(Ti * Si).
// One day of work on order i saves Si.
// So every day choose available order with maximum Si.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, D;
    cin >> N >> D;

    vector<vector<pair<int,int>>> byDay(D + 1);
    long long penalty = 0;

    for (int i = 0; i < N; i++) {
        int Di, Ti, Si;
        cin >> Di >> Ti >> Si;

        penalty += 1LL * Ti * Si;
        byDay[Di].push_back({Si, Ti});
    }

    priority_queue<pair<int,int>> pq; // {penalty rate, remaining days}

    for (int day = 1; day <= D; day++) {
        for (auto &ord : byDay[day]) {
            pq.push(ord);
        }

        if (!pq.empty()) {
            auto [S, rem] = pq.top();
            pq.pop();

            penalty -= S; // saved penalty
            rem--;

            if (rem > 0) {
                pq.push({S, rem});
            }
        }
    }

    cout << penalty << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}
