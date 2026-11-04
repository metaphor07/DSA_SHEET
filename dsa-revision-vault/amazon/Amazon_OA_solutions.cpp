// =====================================================================
//  Amazon SDE-1 OA (IIT Delhi, Nov 2026) — reconstructed + predicted bank
//  All solutions C++17, compiled and stress-tested against brute force
//  (see Amazon_OA_stress.cpp). Compile:  g++ -std=c++17 -O2 file.cpp
// =====================================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007LL;

ll power(ll b, ll e, ll m = MOD) { ll r = 1; b %= m; if (b < 0) b += m;
    while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }

// ---------------------------------------------------------------------
// R1. Secure Maximum Deliveries  (your screenshot; also HackOn Aug-2026,
//     IIT BHU intern Jul-2026 "Maximize the Bottom-Half Warehouse Loads")
// k warehouses (k even), a warehouse holds deliveries of ONE log only,
// a log may be split, not everything must be stored. The k/2 largest
// warehouses are compromised. Maximise the sum of the other k/2.
// Idea: fix x = size of the smallest compromised warehouse. Compromised
// ones should be exactly x (bigger only wastes stock). Secure ones are
// <= x. Each log a gives a/x full x-pieces + one remainder a%x.
// Need F = sum(a/x) >= h. Use h full pieces as compromised, the next
// min(F-h, h) full pieces as secure, and fill the rest with the largest
// remainders. Try every x in [1, max a].  O(maxA * n).
// ---------------------------------------------------------------------
ll secureMaximumDeliveries(const vector<int>& logs, int k) {
    int h = k / 2, n = logs.size();
    int mx = logs.empty() ? 0 : *max_element(logs.begin(), logs.end());
    ll best = 0;
    vector<int> rem(n);
    for (int x = 1; x <= mx; ++x) {
        ll F = 0;
        for (int i = 0; i < n; ++i) { F += logs[i] / x; rem[i] = logs[i] % x; }
        if (F < h) continue;                       // cannot make h pieces of size x
        ll fullSecure = min<ll>(F - h, h);
        ll cur = fullSecure * x;
        ll need = h - fullSecure;                  // secure slots left for remainders
        if (need > 0) {
            int take = (int)min<ll>(need, n);
            nth_element(rem.begin(), rem.begin() + take - 1, rem.end(), greater<int>());
            for (int i = 0; i < take; ++i) cur += rem[i];
        }
        best = max(best, cur);
    }
    return best;
}

// ---------------------------------------------------------------------
// R2. Maximum Continuous Uptime / Max consecutive 1s after flipping
//     exactly ONE window of length k (Amazon SDE intern 2026, LNMIIT Oct-26)
// answer = max over windows [i, i+k-1] of  left[i-1] + k + right[i+k]
// ---------------------------------------------------------------------
int maxConsecutiveOnesAfterWindow(const string& s, int k) {
    int n = s.size();
    if (k >= n) return n;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) L[i] = (s[i] == '1') ? (i ? L[i - 1] : 0) + 1 : 0;
    for (int i = n - 1; i >= 0; --i) R[i] = (s[i] == '1') ? (i + 1 < n ? R[i + 1] : 0) + 1 : 0;
    int best = 0;
    for (int i = 0; i + k <= n; ++i) {
        int cur = (i ? L[i - 1] : 0) + k + (i + k < n ? R[i + k] : 0);
        best = max(best, cur);
    }
    return best;
}

// ---------------------------------------------------------------------
// R3. IIITD intern (4 Jul 2026) Q1: arrangements of DISTINCT positive
//     integers with no run of 3+ consecutive evens. mod 1e9+7.
// Distinct => answer = (#parity patterns) * E! * O!.
// Patterns: O odds create O+1 gaps, each gap gets 0..2 evens, total E
// = coeff of t^E in (1+t+t^2)^(O+1). Inclusion–exclusion:
//   sum_j (-1)^j C(O+1, j) C(E - 3j + O, O)
// ---------------------------------------------------------------------
ll countArrangementsEvenRunAtMost2(const vector<ll>& A) {
    int n = A.size(), E = 0;
    for (ll v : A) E += (v % 2 == 0);
    int O = n - E, g = O + 1;
    int N = n + 5;
    vector<ll> f(N + 1), inv(N + 1);
    f[0] = 1; for (int i = 1; i <= N; ++i) f[i] = f[i - 1] * i % MOD;
    inv[N] = power(f[N], MOD - 2); for (int i = N; i > 0; --i) inv[i - 1] = inv[i] * i % MOD;
    auto C = [&](int a, int b) -> ll { if (b < 0 || a < b || a < 0) return 0; return f[a] * inv[b] % MOD * inv[a - b] % MOD; };
    ll pat = 0;
    for (int j = 0; j <= g && 3 * j <= E; ++j) {
        ll term = C(g, j) * C(E - 3 * j + g - 1, g - 1) % MOD;
        pat = (j & 1) ? (pat - term + MOD) % MOD : (pat + term) % MOD;
    }
    return pat * f[E] % MOD * f[O] % MOD;
}

// ---------------------------------------------------------------------
// R4. IIITD intern Q2: number of subsequences (by index set, empty
//     included) that can be rearranged into a palindrome.
// Per letter with frequency f>0: even picks = odd picks = 2^(f-1).
// At most one letter odd  =>  2^(n-d) * (1 + d),  d = #distinct letters.
// (If the problem means DISTINCT strings, this formula does not apply.)
// ---------------------------------------------------------------------
ll countPalindromicRearrangeableSubseq(const string& s) {
    int n = s.size(); array<int, 26> cnt{}; for (char c : s) cnt[c - 'a']++;
    int d = 0; for (int c : cnt) d += (c > 0);
    return power(2, n - d) * ((d + 1) % MOD) % MOD;
}

// =====================================================================
//                    PREDICTED BANK (Tier S/A)
// =====================================================================

// P1. Capacity to Ship Packages Within D Days (NIT Bhopal on-campus, Oct-26)
//     Binary search on the answer.  LC 1011.
ll shipWithinDays(const vector<int>& w, int days) {
    ll lo = *max_element(w.begin(), w.end()), hi = accumulate(w.begin(), w.end(), 0LL);
    auto ok = [&](ll cap) { int d = 1; ll cur = 0;
        for (int x : w) { if (cur + x > cap) { d++; cur = 0; } cur += x; } return d <= days; };
    while (lo < hi) { ll mid = lo + (hi - lo) / 2; if (ok(mid)) hi = mid; else lo = mid + 1; }
    return lo;
}

// P2. Sort Bug Report Frequencies (Feb + May 2026): lower frequency first,
//     ties -> lower code first; output keeps repeats. (Read the statement:
//     some versions want descending frequency — flip one comparison.)
vector<int> sortBugReports(vector<int> bugs) {
    unordered_map<int, int> f; for (int b : bugs) f[b]++;
    sort(bugs.begin(), bugs.end(), [&](int a, int b) {
        if (f[a] != f[b]) return f[a] < f[b];
        return a < b; });
    return bugs;
}

// P3. Server security-level grouping (2026 summer intern) == LC 2910.
//     Same level per group, all group sizes g or g+1, minimise #groups.
//     Larger g is never worse, so try g from minFreq downwards.
ll minSecurityGroups(const vector<int>& levels) {
    unordered_map<int, int> cnt; for (int v : levels) cnt[v]++;
    vector<int> fr; int mn = INT_MAX;
    for (auto& [k, c] : cnt) { fr.push_back(c); mn = min(mn, c); }
    for (int g = mn; g >= 1; --g) {
        ll total = 0; bool ok = true;
        for (int c : fr) {
            int q = c / g, r = c % g;
            if (r > q) { ok = false; break; }       // can't absorb leftover with +1s
            total += (c + g) / (g + 1);             // ceil(c / (g+1))
        }
        if (ok) return total;
    }
    return 0;
}

// P4. Maximize Rental Revenue / Server Allocation Cost (Feb-2026, many repeats)
//     m customers, each rents from the VM/server with the MOST stock and pays
//     price = current stock (then stock--). Heap is fine for m <= 1e5;
//     threshold binary search handles m up to 1e9+.  (LC 1648 pattern)
ll maxRentalRevenueHeap(vector<ll> stock, ll m) {
    priority_queue<ll> pq(stock.begin(), stock.end()); ll rev = 0;
    while (m-- > 0 && !pq.empty() && pq.top() > 0) { ll t = pq.top(); pq.pop(); rev = (rev + t) % MOD; pq.push(t - 1); }
    return rev;
}
ll maxRentalRevenueFast(const vector<ll>& stock, ll m) {
    auto cntAbove = [&](ll T) { ll c = 0; for (ll s : stock) if (s > T) c += s - T; return c; };
    ll lo = 0, hi = *max_element(stock.begin(), stock.end());
    while (lo < hi) { ll mid = (lo + hi) / 2; if (cntAbove(mid) <= m) hi = mid; else lo = mid + 1; }
    ll T = lo; ll rev = 0, used = 0;
    for (ll s : stock) if (s > T) {
        used += s - T;
        __int128 sum = (__int128)(s + T + 1) * (s - T) / 2;  // T+1 .. s
        rev = (rev + (ll)(sum % MOD)) % MOD;
    }
    ll left = m - used;                       // sell 'left' more units at price T
    if (T > 0 && left > 0) rev = (rev + (left % MOD) * (T % MOD)) % MOD;
    return rev;
}

// P5. Minimum Health to Beat Game (Amazon OA Jan-2025 / 2026 CoderPad) LC 2214
ll minimumHealth(const vector<int>& damage, int armor) {
    ll sum = 0; int mx = 0; for (int d : damage) { sum += d; mx = max(mx, d); }
    return sum - min(mx, armor) + 1;
}

// P6. Binary array: fewest adjacent swaps to group all 0s together and all
//     1s together (either order) — 2026 CoderPad "minMoves". Use long long.
ll minAdjacentSwapsGroupBinary(const vector<int>& a) {
    ll zerosFirst = 0, onesFirst = 0, ones = 0, zeros = 0;
    for (int x : a) { if (x == 0) { zerosFirst += ones; zeros++; } else { onesFirst += zeros; ones++; } }
    return min(zerosFirst, onesFirst);
}

// P7. Minimum Merge Conflicts (Jun-2026, Hard). Merge two strings keeping
//     each one's order; conflict = pair i<j with merged[i] > merged[j].
//     Internal inversions are fixed; DP on cross-inversions:
//     place a[i] -> conflicts with remaining b[j..] that are smaller.
ll minMergeConflicts(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    auto inv = [](const string& s) { ll r = 0; array<ll, 26> seen{};
        for (char c : s) { for (int x = c - 'a' + 1; x < 26; ++x) r += seen[x]; seen[c - 'a']++; } return r; };
    // lessA[i][c] = # chars in a[i..] strictly smaller than c
    vector<array<int, 27>> lessA(n + 1), lessB(m + 1);
    auto build = [](const string& s, vector<array<int, 27>>& L) {
        int len = s.size(); L[len].fill(0);
        for (int i = len - 1; i >= 0; --i) { L[i] = L[i + 1]; for (int c = s[i] - 'a' + 1; c <= 26; ++c) L[i][c]++; } };
    build(a, lessA); build(b, lessB);
    const ll INF = LLONG_MAX / 4;
    vector<ll> dp(m + 1, INF), nd(m + 1);
    dp[0] = 0;
    for (int j = 1; j <= m; ++j) dp[j] = dp[j - 1] + lessA[0][b[j - 1] - 'a'];
    for (int i = 1; i <= n; ++i) {
        nd[0] = dp[0] + lessB[0][a[i - 1] - 'a'];
        for (int j = 1; j <= m; ++j) {
            ll takeA = dp[j] + lessB[j][a[i - 1] - 'a'];      // a[i-1] placed after b[0..j)
            ll takeB = nd[j - 1] + lessA[i][b[j - 1] - 'a'];  // b[j-1] placed after a[0..i)
            nd[j] = min(takeA, takeB);
        }
        swap(dp, nd);
    }
    return inv(a) + inv(b) + dp[m];
}

// P8. Number of Unique XOR Triplets (Jul-2026) == LC 3514 (values <= 1500).
//     i <= j <= k, so values may repeat. Pair-XOR set (< 2048) then XOR once more.
int uniqueXorTriplets(const vector<int>& nums) {
    vector<int> v(nums); sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
    const int LIM = 1 << 11;
    vector<char> pairX(LIM, 0), tri(LIM, 0);
    for (size_t i = 0; i < v.size(); ++i) for (size_t j = i; j < v.size(); ++j) pairX[v[i] ^ v[j]] = 1;
    for (int p = 0; p < LIM; ++p) if (pairX[p]) for (int c : v) tri[p ^ c] = 1;
    return count(tri.begin(), tri.end(), 1);
}

// P9. Amazon Throttling Gateway (Feb-2026 "Amazon Throttling Mechanism";
//     classic). Sorted request times. Drop if >3 in the same second,
//     >20 in any 10 s, >60 in any 60 s. Dropped requests still count.
int droppedRequests(const vector<int>& t) {
    int drop = 0;
    for (int i = 0; i < (int)t.size(); ++i) {
        if (i >= 3 && t[i] == t[i - 3]) drop++;
        else if (i >= 20 && t[i] - t[i - 20] < 10) drop++;
        else if (i >= 60 && t[i] - t[i - 60] < 60) drop++;
    }
    return drop;
}

// P10. Number of Retailers (Jan-2026) ~ LC 2250. Retailer (x,y) serves
//      point (a,b) iff a <= x and b <= y. Offline: sweep x descending,
//      Fenwick tree over compressed y.  O((n+q) log n)
vector<int> countRetailers(const vector<pair<int, int>>& ret, const vector<pair<int, int>>& qs) {
    vector<int> ys; for (auto& r : ret) ys.push_back(r.second);
    sort(ys.begin(), ys.end()); ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int Y = ys.size(); vector<int> bit(Y + 1, 0);
    auto add = [&](int i) { for (++i; i <= Y; i += i & -i) bit[i]++; };
    auto pre = [&](int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; };  // first i
    vector<int> ro(ret.size()), qo(qs.size());
    iota(ro.begin(), ro.end(), 0); iota(qo.begin(), qo.end(), 0);
    sort(ro.begin(), ro.end(), [&](int a, int b) { return ret[a].first > ret[b].first; });
    sort(qo.begin(), qo.end(), [&](int a, int b) { return qs[a].first > qs[b].first; });
    vector<int> ans(qs.size()); size_t p = 0; int total = 0;
    for (int qi : qo) {
        while (p < ro.size() && ret[ro[p]].first >= qs[qi].first) {
            add(lower_bound(ys.begin(), ys.end(), ret[ro[p]].second) - ys.begin()); total++; p++; }
        int idx = lower_bound(ys.begin(), ys.end(), qs[qi].second) - ys.begin();  // y >= b
        ans[qi] = total - pre(idx);
    }
    return ans;
}

// P11. Max & Min median of a size-k subsequence (SDE-1 OA 2025-26).
//      Median = element at index (k-1)/2 of the sorted subsequence
//      (CHECK the statement's even-k definition). Returns {max, min}.
pair<ll, ll> maxMinMedian(vector<ll> v, int k) {
    sort(v.begin(), v.end()); int n = v.size(), m = (k - 1) / 2;
    return { v[n - k + m], v[m] };
}

// P12. Lexicographically maximum array using MEX (SDE-1 OA 2025-26, Hard).
//      Repeatedly delete a non-empty prefix and append its MEX; maximise
//      the result lexicographically. Greedy: next value = MEX of whole
//      remaining suffix, achieved by the SHORTEST prefix (keeps more
//      elements for later). If that MEX is 0, take one element at a time.
vector<int> lexMaxMexArray(const vector<int>& a) {
    int n = a.size();
    vector<int> suf(n + 1, 0), cnt(n + 2, 0); int mex = 0;
    for (int i = n - 1; i >= 0; --i) { if (a[i] <= n) cnt[a[i]]++; while (cnt[mex]) mex++; suf[i] = mex; }
    vector<int> res, seen(n + 2, -1); int i = 0, stamp = 0;
    while (i < n) {
        int target = suf[i];
        if (target == 0) { res.push_back(0); i++; continue; }
        int have = 0; stamp++;
        while (have < target) { int x = a[i++]; if (x < target && seen[x] != stamp) { seen[x] = stamp; have++; } }
        res.push_back(target);
    }
    return res;
}

// P13. Data packets -> channels, maximise sum of channel medians (classic
//      2024-25 Amazon OA, still recycled). Every channel non-empty.
//      Top m-1 packets go alone; the rest share one channel. Return ceil.
ll maxChannelQuality(vector<ll> p, int m) {
    sort(p.rbegin(), p.rend()); int n = p.size();
    ll sum2 = 0;                                  // 2 * answer, kept integral
    for (int i = 0; i < m - 1; ++i) sum2 += 2 * p[i];
    int L = n - (m - 1), s = m - 1;               // last channel = p[s .. n-1]
    if (L % 2) sum2 += 2 * p[s + L / 2];
    else sum2 += p[s + L / 2 - 1] + p[s + L / 2];
    return (sum2 + 1) / 2;                        // ceil(sum2 / 2)
}

// P14. Count decreasing-ratings subarrays (each next = previous - 1).
ll countDecreasingRatings(const vector<int>& r) {
    ll ans = 0, run = 0;
    for (size_t i = 0; i < r.size(); ++i) { run = (i && r[i] == r[i - 1] - 1) ? run + 1 : 1; ans += run; }
    return ans;
}

// P15. Password similarity: each char of newPw may be cyclically
//      incremented at most once (z->a). Is oldPw a subsequence?
bool passwordSimilar(const string& nw, const string& old) {
    size_t j = 0;
    for (char c : nw) { if (j == old.size()) break; char nx = c == 'z' ? 'a' : c + 1;
        if (old[j] == c || old[j] == nx) j++; }
    return j == old.size();
}

// P16. getMinErrors: string of '0','1','!'. Replace every '!' to minimise
//      x*#("01" subsequences) + y*#("10" subsequences); answer mod 1e9+7.
//      (SDE-II Sep-2025 variant is x = y = 1.) Optimal '!' fill is
//      monotone: some prefix of '!' one digit, the rest the other.
ll getMinErrors(const string& s, ll x, ll y) {
    int n = s.size();
    auto sweep = [&](char base, char flip) -> ll {
        string t = s; for (char& c : t) if (c == '!') c = base;
        ll z = 0, o = 0, cost = 0;
        for (char c : t) { if (c == '0') { cost += y * o; z++; } else { cost += x * z; o++; } }
        ll best = cost, totZ = z, totO = o, zl = 0, ol = 0;   // counts left of current pos
        for (int i = 0; i < n; ++i) {
            if (s[i] == '!') {
                ll zr = totZ - zl - (t[i] == '0'), orr = totO - ol - (t[i] == '1');
                auto contrib = [&](char c) { return c == '0' ? x * orr + y * ol : x * zl + y * zr; };
                cost += contrib(flip) - contrib(t[i]);
                if (t[i] == '0') { totZ--; totO++; } else { totO--; totZ++; }
                t[i] = flip; best = min(best, cost);
            }
            if (t[i] == '0') zl++; else ol++;
        }
        return best;
    };
    return min(sweep('0', '1'), sweep('1', '0')) % MOD;
}

// P17. Max sum of k consecutive bags (2026 CoderPad
//      calculateMaximumConsecutiveSum) — plain sliding window, 64-bit,
//      apply % only at the very end (never compare modded values).
ll maxConsecutiveSum(const vector<ll>& seg, int k) {
    ll cur = 0, best = LLONG_MIN;
    for (int i = 0; i < (int)seg.size(); ++i) { cur += seg[i]; if (i >= k) cur -= seg[i - k]; if (i >= k - 1) best = max(best, cur); }
    return ((best % MOD) + MOD) % MOD;
}

// P18. Two Sum family (IIT BHU on-campus Oct-26 title "Two Sum"; exact
//      twist unknown). Most common Amazon twist: count UNIQUE value pairs
//      (a,b), a<=b, with a+b == target.
ll countUniquePairs(const vector<int>& v, ll target) {
    unordered_map<ll, int> f; for (int x : v) f[x]++;
    ll c = 0;
    for (auto& [a, cnt] : f) { ll b = target - a;
        if (a < b && f.count(b)) c++;
        else if (a == b && cnt >= 2) c++; }
    return c;
}

#ifndef NO_MAIN
int main() {
    // ---- reconstructed questions: samples from the screenshots ----
    assert(secureMaximumDeliveries({3, 5, 9, 6}, 4) == 9);
    assert(secureMaximumDeliveries({6}, 2) == 3);
    assert(secureMaximumDeliveries({5, 5, 5, 5, 5, 5}, 4) == 10);
    assert(maxConsecutiveOnesAfterWindow("11001", 2) == 5);
    assert(countPalindromicRearrangeableSubseq("aa") == 4);
    assert(countPalindromicRearrangeableSubseq("ab") == 3);
    // ---- bank samples ----
    assert(shipWithinDays({1,2,3,4,5,6,7,8,9,10}, 5) == 15);
    assert((sortBugReports({8,4,6,5,4,8}) == vector<int>{5,6,4,4,8,8}));
    assert(minSecurityGroups({3,2,3,2,3}) == 2);          // LC 2910 ex1
    assert(minSecurityGroups({10,10,10,3,1,1}) == 4);     // LC 2910 ex2
    assert(maxRentalRevenueFast({2,5}, 4) == 14);         // LC 1648 ex1
    assert(maxRentalRevenueFast({3,5}, 6) == 19);         // LC 1648 ex2
    assert(minimumHealth({2,7,4,3}, 4) == 13);
    assert(minMergeConflicts("zc", "d") == 2);
    assert(uniqueXorTriplets({1,2,3}) == 4);               // LC 3513 ex: {0,1,2,3}
    assert(maxMinMedian({1,2,3}, 2) == make_pair(2LL, 1LL));
    assert(countDecreasingRatings({4,3,5,4,3}) == 9);
    assert(passwordSimilar("abdbc", "ace"));
    assert(maxChannelQuality({1,2,3,4,5}, 2) == 8);        // 5 + median(1..4)=2.5 -> ceil 7.5
    assert(getMinErrors("101!1", 2, 3) == 9);
    assert(countUniquePairs({1,1,2,45,46,46}, 47) == 2);   // (1,46),(2,45)
    assert(countUniquePairs({1,5,1,5}, 6) == 1);
    assert(countArrangementsEvenRunAtMost2({2,4,6,1}) == 12);
    assert(countArrangementsEvenRunAtMost2({2,4,6}) == 0);
    assert(countPalindromicRearrangeableSubseq("aab") == 6);
    assert(maxConsecutiveOnesAfterWindow("0110100", 2) == 4);  // flip [3,4] -> 0111100
    puts("All sample asserts passed.");
}
#endif
