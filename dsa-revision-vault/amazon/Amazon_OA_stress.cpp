// Brute-force stress tests for Amazon_OA_solutions.cpp
#define NO_MAIN
#include "Amazon_OA_solutions.cpp"
mt19937 rng(12345);
int rnd(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

// R1 brute: assign each of k warehouses (log, amount>=0) within log totals
ll bruteSecure(const vector<int>& logs, int k) {
    ll best = 0; vector<int> left(logs), w(k);
    function<void(int)> go = [&](int idx) {
        if (idx == k) { vector<int> s(w); sort(s.begin(), s.end()); ll t = 0;
            for (int i = 0; i < k / 2; ++i) t += s[i]; best = max(best, t); return; }
        for (size_t l = 0; l < logs.size(); ++l)
            for (int amt = 0; amt <= left[l]; ++amt) { left[l] -= amt; w[idx] = amt; go(idx + 1); left[l] += amt; }
    };
    go(0); return best;
}
int bruteWindow(const string& s, int k) {
    int n = s.size(), best = 0;
    for (int i = 0; i + k <= n; ++i) { string t = s; for (int j = i; j < i + k; ++j) t[j] = '1';
        int run = 0; for (char c : t) { run = c == '1' ? run + 1 : 0; best = max(best, run); } }
    return best;
}
ll bruteArr(vector<ll> A) {
    sort(A.begin(), A.end()); ll c = 0;
    do { int run = 0; bool ok = true; for (ll v : A) { run = v % 2 == 0 ? run + 1 : 0; if (run > 2) ok = false; } c += ok; }
    while (next_permutation(A.begin(), A.end()));
    return c % MOD;
}
ll brutePal(const string& s) {
    int n = s.size(); ll c = 0;
    for (int m = 0; m < (1 << n); ++m) { array<int, 26> f{}; for (int i = 0; i < n; ++i) if (m >> i & 1) f[s[i] - 'a']++;
        int odd = 0; for (int x : f) odd += x & 1; c += odd <= 1; }
    return c;
}
ll bruteGroups(const vector<int>& lv) {
    map<int, int> cnt; for (int v : lv) cnt[v]++; int mx = 0; for (auto& p : cnt) mx = max(mx, p.second);
    ll best = LLONG_MAX;
    for (int g = 1; g <= mx; ++g) { ll tot = 0; bool ok = true;
        for (auto& p : cnt) { int c = p.second; int bestT = -1;
            for (int t = 1; t <= c; ++t) if ((ll)t * g <= c && c <= (ll)t * (g + 1)) { bestT = t; break; }
            if (bestT < 0) { ok = false; break; } tot += bestT; }
        if (ok) best = min(best, tot); }
    return best;
}
ll bruteMerge(const string& a, const string& b) {
    int n = a.size(), m = b.size(); ll best = LLONG_MAX;
    for (int mask = 0; mask < (1 << (n + m)); ++mask) { if (__builtin_popcount(mask) != n) continue;
        string t; int i = 0, j = 0; for (int p = 0; p < n + m; ++p) t += (mask >> p & 1) ? a[i++] : b[j++];
        ll inv = 0; for (int p = 0; p < n + m; ++p) for (int q = p + 1; q < n + m; ++q) inv += t[p] > t[q];
        best = min(best, inv); }
    return best;
}
int bruteXor(const vector<int>& v) { set<int> s; int n = v.size();
    for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) s.insert(v[i] ^ v[j] ^ v[k]); return s.size(); }
vector<int> bruteRet(const vector<pair<int,int>>& r, const vector<pair<int,int>>& q) {
    vector<int> a; for (auto& p : q) { int c = 0; for (auto& x : r) c += (p.first <= x.first && p.second <= x.second); a.push_back(c); } return a; }
pair<ll,ll> bruteMed(const vector<ll>& v, int k) {
    int n = v.size(); ll mx = LLONG_MIN, mn = LLONG_MAX;
    for (int m = 0; m < (1 << n); ++m) { if (__builtin_popcount(m) != k) continue; vector<ll> s;
        for (int i = 0; i < n; ++i) if (m >> i & 1) s.push_back(v[i]); sort(s.begin(), s.end());
        mx = max(mx, s[(k - 1) / 2]); mn = min(mn, s[(k - 1) / 2]); }
    return {mx, mn};
}
vector<int> bruteMex(const vector<int>& a) {
    int n = a.size(); vector<int> best; bool has = false;
    for (int m = 0; m < (1 << (n - 1)); ++m) {        // bit i set => cut after i
        vector<int> res, cur;
        for (int i = 0; i < n; ++i) { cur.push_back(a[i]);
            if (i == n - 1 || (m >> i & 1)) { set<int> s(cur.begin(), cur.end()); int x = 0; while (s.count(x)) x++; res.push_back(x); cur.clear(); } }
        if (!has || res > best) { best = res; has = true; } }
    return best;
}
ll bruteChannels(const vector<ll>& p, int m) {
    int n = p.size(); ll best2 = LLONG_MIN; vector<int> lab(n);
    function<void(int)> go = [&](int i) {
        if (i == n) { vector<vector<ll>> g(m); for (int j = 0; j < n; ++j) g[lab[j]].push_back(p[j]);
            ll s2 = 0; for (auto& v : g) { if (v.empty()) return; sort(v.begin(), v.end()); int L = v.size();
                s2 += (L % 2) ? 2 * v[L / 2] : v[L / 2 - 1] + v[L / 2]; }
            best2 = max(best2, s2); return; }
        for (int c = 0; c < m; ++c) { lab[i] = c; go(i + 1); } };
    go(0); return (best2 + 1) / 2;
}
ll bruteErrors(const string& s, ll x, ll y) {
    vector<int> q; for (int i = 0; i < (int)s.size(); ++i) if (s[i] == '!') q.push_back(i);
    ll best = LLONG_MAX;
    for (int m = 0; m < (1 << q.size()); ++m) { string t = s; for (size_t j = 0; j < q.size(); ++j) t[q[j]] = (m >> j & 1) ? '1' : '0';
        ll z = 0, o = 0, c = 0; for (char ch : t) { if (ch == '0') { c += y * o; z++; } else { c += x * z; o++; } } best = min(best, c); }
    return best % MOD;
}

int main() {
    for (int it = 0; it < 400; ++it) {           // R1
        int n = rnd(1, 3), k = 2 * rnd(1, 2); vector<int> l(n); for (int& v : l) v = rnd(0, k == 4 ? 5 : 8);
        ll a = secureMaximumDeliveries(l, k), b = bruteSecure(l, k);
        if (a != b) { printf("R1 FAIL k=%d:", k); for (int v : l) printf(" %d", v); printf(" got %lld want %lld\n", a, b); return 1; } }
    puts("R1 secureMaximumDeliveries OK");
    for (int it = 0; it < 3000; ++it) { int n = rnd(1, 12), k = rnd(1, n); string s(n, '0'); for (char& c : s) c = rnd(0, 1) ? '1' : '0';
        if (maxConsecutiveOnesAfterWindow(s, k) != bruteWindow(s, k)) { puts("R2 FAIL"); return 1; } }
    puts("R2 window OK");
    for (int it = 0; it < 300; ++it) { int n = rnd(1, 8); set<ll> st; while ((int)st.size() < n) st.insert(rnd(1, 30));
        vector<ll> A(st.begin(), st.end()); if (countArrangementsEvenRunAtMost2(A) != bruteArr(A)) { puts("R3 FAIL"); return 1; } }
    puts("R3 even-run arrangements OK");
    for (int it = 0; it < 2000; ++it) { int n = rnd(0, 13); string s; for (int i = 0; i < n; ++i) s += char('a' + rnd(0, 3));
        if (countPalindromicRearrangeableSubseq(s) != brutePal(s)) { puts("R4 FAIL"); return 1; } }
    puts("R4 palindromic subsequences OK");
    for (int it = 0; it < 3000; ++it) { int n = rnd(1, 25); vector<int> v(n); for (int& x : v) x = rnd(1, 4);
        if (minSecurityGroups(v) != bruteGroups(v)) { puts("P3 FAIL"); return 1; } }
    puts("P3 security groups OK");
    for (int it = 0; it < 3000; ++it) { int n = rnd(1, 5); vector<ll> s(n); for (ll& x : s) x = rnd(0, 12); ll m = rnd(0, 70);
        if (*max_element(s.begin(), s.end()) == 0) continue;
        if (maxRentalRevenueFast(s, m) != maxRentalRevenueHeap(s, m)) { puts("P4 FAIL"); return 1; } }
    puts("P4 rental revenue OK");
    for (int it = 0; it < 1500; ++it) { int n = rnd(0, 6), m = rnd(0, 6); string a, b;
        for (int i = 0; i < n; ++i) a += char('a' + rnd(0, 4)); for (int i = 0; i < m; ++i) b += char('a' + rnd(0, 4));
        if (minMergeConflicts(a, b) != bruteMerge(a, b)) { printf("P7 FAIL %s %s\n", a.c_str(), b.c_str()); return 1; } }
    puts("P7 merge conflicts OK");
    for (int it = 0; it < 500; ++it) { int n = rnd(1, 12); vector<int> v(n); for (int& x : v) x = rnd(1, 40);
        if (uniqueXorTriplets(v) != bruteXor(v)) { puts("P8 FAIL"); return 1; } }
    puts("P8 xor triplets OK");
    for (int it = 0; it < 1000; ++it) { int n = rnd(1, 15), q = rnd(1, 15); vector<pair<int,int>> r(n), qs(q);
        for (auto& p : r) p = {rnd(0, 10), rnd(0, 10)}; for (auto& p : qs) p = {rnd(0, 11), rnd(0, 11)};
        if (countRetailers(r, qs) != bruteRet(r, qs)) { puts("P10 FAIL"); return 1; } }
    puts("P10 retailers OK");
    for (int it = 0; it < 2000; ++it) { int n = rnd(1, 9), k = rnd(1, n); vector<ll> v(n); for (ll& x : v) x = rnd(1, 20);
        if (maxMinMedian(v, k) != bruteMed(v, k)) { puts("P11 FAIL"); return 1; } }
    puts("P11 medians OK");
    for (int it = 0; it < 3000; ++it) { int n = rnd(1, 9); vector<int> a(n); for (int& x : a) x = rnd(0, 3);
        if (lexMaxMexArray(a) != bruteMex(a)) { printf("P12 FAIL:"); for (int x : a) printf(" %d", x); puts(""); return 1; } }
    puts("P12 MEX array OK");
    for (int it = 0; it < 800; ++it) { int n = rnd(1, 7), m = rnd(1, n); vector<ll> p(n); for (ll& x : p) x = rnd(1, 20);
        if (maxChannelQuality(p, m) != bruteChannels(p, m)) { puts("P13 FAIL"); return 1; } }
    puts("P13 channels OK");
    for (int it = 0; it < 3000; ++it) { int n = rnd(1, 11); string s; for (int i = 0; i < n; ++i) s += "01!"[rnd(0, 2)]; ll x = rnd(0, 6), y = rnd(0, 6);
        if (getMinErrors(s, x, y) != bruteErrors(s, x, y)) { printf("P16 FAIL %s %lld %lld\n", s.c_str(), x, y); return 1; } }
    puts("P16 getMinErrors OK");
    puts("ALL STRESS TESTS PASSED");
}
