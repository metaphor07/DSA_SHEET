// =====================================================================
//  IBM OA Part B — REFERENCE SOLUTIONS  (SPOILERS — open only after trying)
//  The judge (partB_judge.cpp) also uses this file to generate expected answers.
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// B1. High-Load Timestamps — integer compare, no floating point.  O(n)
vector<int> getHighLoadTimestamps(vector<int> load) {
    long long n = load.size(), total = 0;
    for (int x : load) total += x;
    vector<int> res;
    for (int i = 0; i < (int)n; i++)
        if ((long long)load[i] * n > 2 * total) res.push_back(i);
    return res;
}

// B2. Minimum Total Cost of Items — cheapest option per item.  O(n + numItems)
long long getMinimumTotalCost(int numItems, vector<int> itemId, vector<int> cost) {
    vector<long long> best(numItems, LLONG_MAX);
    for (size_t i = 0; i < itemId.size(); i++)
        best[itemId[i]] = min(best[itemId[i]], (long long)cost[i]);
    long long sum = 0;
    for (long long b : best) { if (b == LLONG_MAX) return -1; sum += b; }
    return sum;
}

// B3. Max Non-Overlapping Intervals [s, e) — sort by END, take greedily.  O(n log n)
int maxNonOverlappingIntervals(vector<int> startTime, vector<int> endTime) {
    int n = startTime.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) { return endTime[a] < endTime[b]; });
    long long last = LLONG_MIN; int cnt = 0;
    for (int i : idx) if (startTime[i] >= last) { cnt++; last = endTime[i]; }
    return cnt;
}

// B4. Max Water Level Increase — running minimum.  O(n)
int maxWaterLevelIncrease(vector<int> arr) {
    int mn = arr[0], best = -1;
    for (size_t j = 1; j < arr.size(); j++) {
        if (arr[j] > mn) best = max(best, arr[j] - mn);
        mn = min(mn, arr[j]);
    }
    return best;
}

// B5. Minimum Reassignments for Connectivity — union-find.  O(m α(n))
struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; } return x; }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};
int minReassignments(int link_nodes, vector<int> link_from, vector<int> link_to) {
    if ((long long)link_from.size() < link_nodes - 1) return -1;
    DSU d(link_nodes + 1);
    int comps = link_nodes;
    for (size_t i = 0; i < link_from.size(); i++) if (d.unite(link_from[i], link_to[i])) comps--;
    return comps - 1;
}

// B6. Login Replacement Counter — per-user streak of consecutive errors.  O(n)
int countReplacements(vector<string> login_id, vector<string> login_status) {
    unordered_map<string, int> streak;
    int total = 0;
    for (size_t i = 0; i < login_id.size(); i++) {
        if (login_status[i] == "error") {
            if (++streak[login_id[i]] == 3) { total++; streak[login_id[i]] = 0; }
        } else streak[login_id[i]] = 0;
    }
    return total;
}

// B7. Earliest Arrival — take a move only when it reduces the remaining distance.  O(n)
int earliestArrival(string directions, long long startX, long long startY, long long endX, long long endY) {
    long long dx = endX - startX, dy = endY - startY;
    if (dx == 0 && dy == 0) return 0;
    for (int i = 0; i < (int)directions.size(); i++) {
        char c = directions[i];
        if (c == 'E' && dx > 0) dx--;
        else if (c == 'W' && dx < 0) dx++;
        else if (c == 'N' && dy > 0) dy--;
        else if (c == 'S' && dy < 0) dy++;
        if (dx == 0 && dy == 0) return i + 1;
    }
    return -1;
}

// B8. Invalid Service-Log Groups — group, sort by time, validate.  O(n log n)
int countInvalidGroups(vector<string> sid, vector<long long> timestamp, vector<string> status) {
    unordered_map<string, vector<pair<long long, string>>> g;
    for (size_t i = 0; i < sid.size(); i++) g[sid[i]].push_back({timestamp[i], status[i]});
    int bad = 0;
    for (auto& [id, v] : g) {
        sort(v.begin(), v.end());
        bool ok = (v[0].second == "DOWN");
        for (size_t i = 1; i < v.size() && ok; i++) if (v[i].second == v[i - 1].second) ok = false;
        if (!ok) bad++;
    }
    return bad;
}

// B9. Frequent IPs in a Window — per-IP two pointers on sorted timestamps.  O(n log n)
vector<int> frequentIps(vector<int> ip, vector<int> timestamp, int k, int t) {
    map<int, vector<int>> occ;                       // map => answer comes out sorted
    for (size_t i = 0; i < ip.size(); i++) occ[ip[i]].push_back(timestamp[i]);
    vector<int> res;
    for (auto& [x, v] : occ) {
        int l = 0; bool ok = false;
        for (int r = 0; r < (int)v.size() && !ok; r++) {
            while (v[r] - v[l] >= t) l++;            // keep window [v[l], v[l] + t)
            if (r - l + 1 > k) ok = true;
        }
        if (ok) res.push_back(x);
    }
    return res;
}

// B10. Shortest Subarray with Exactly k Distinct — sliding window.  O(n)
// (The shortest window with >= k distinct always has exactly k distinct.)
int shortestSubarrayKDistinct(vector<int> arr, int k) {
    unordered_map<int, int> cnt;
    int distinct = 0, best = INT_MAX, l = 0;
    for (int r = 0; r < (int)arr.size(); r++) {
        if (cnt[arr[r]]++ == 0) distinct++;
        while (distinct > k || (distinct == k && cnt[arr[l]] > 1)) {
            if (--cnt[arr[l]] == 0) distinct--;
            l++;
        }
        if (distinct == k) best = min(best, r - l + 1);
    }
    return best == INT_MAX ? -1 : best;
}

// B11. Minimum Meeting Rooms [s, e) — sort starts and ends, sweep.  O(n log n)
int minMeetingRooms(vector<int> start, vector<int> end) {
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int rooms = 0, j = 0;
    for (size_t i = 0; i < start.size(); i++) {
        if (start[i] < end[j]) rooms++;    // no room has freed up yet
        else j++;                          // reuse the room that ended earliest
    }
    return rooms;
}

// B12. Minimum Operations per Price Query — sort + prefix sums + binary search.  O((n+q) log n)
vector<long long> getMinimumOperations(vector<int> price, vector<int> query) {
    sort(price.begin(), price.end());
    int n = price.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + price[i];
    vector<long long> res;
    for (int q : query) {
        long long c = lower_bound(price.begin(), price.end(), q) - price.begin();   // prices < q
        long long below = (long long)q * c - pre[c];
        long long above = (pre[n] - pre[c]) - (long long)q * (n - c);
        res.push_back(below + above);
    }
    return res;
}

// B13. Minimize Array Cost (insert exactly one element) — split the largest gap.  O(n)
long long minimizeArrayCost(vector<int> arr) {
    long long total = 0, bestReduction = 0;
    for (size_t i = 1; i < arr.size(); i++) {
        long long a = arr[i - 1], b = arr[i], d = b - a;
        total += d * d;
        long long x = (a + b) / 2;                                   // best integer to insert
        long long reduction = d * d - ((a - x) * (a - x) + (x - b) * (x - b));
        bestReduction = max(bestReduction, reduction);
    }
    return total - bestReduction;
}

// B14. First Greater Index — prefix max is sorted, so binary search.  O((n+m) log m)
vector<int> firstGreaterIndex(vector<int> arr1, vector<int> arr2) {
    vector<int> pm(arr2.size());
    for (size_t j = 0; j < arr2.size(); j++) pm[j] = j ? max(pm[j - 1], arr2[j]) : arr2[j];
    vector<int> res;
    for (int x : arr1) {
        auto it = upper_bound(pm.begin(), pm.end(), x);
        res.push_back(it == pm.end() ? -1 : int(it - pm.begin()));
    }
    return res;
}

// B15. Max Palindromes After Swaps (= LeetCode 3035) — global pair budget, shortest first.
int maxPalindromesAfterSwaps(vector<string> words) {
    int cnt[26] = {0};
    for (auto& w : words) for (char c : w) cnt[c - 'a']++;
    long long pairs = 0;
    for (int c : cnt) pairs += c / 2;
    vector<int> len;
    for (auto& w : words) len.push_back(w.size());
    sort(len.begin(), len.end());
    int ans = 0;
    for (int L : len) {
        if (pairs < L / 2) break;
        pairs -= L / 2; ans++;
    }
    return ans;
}

// B16. Sorted Sums — Fenwick trees over values.  O(n log V)
// Inserting a: it gets weight (#elements <= a) + 1, every element > a gains +1 weight.
int sortedSums(vector<int> a) {
    const long long MOD = 1000000007LL;
    int MAXV = 1;
    for (int x : a) MAXV = max(MAXV, x);
    vector<long long> cntT(MAXV + 1, 0), sumT(MAXV + 1, 0);
    auto add = [&](vector<long long>& T, int i, long long v) { for (; i <= MAXV; i += i & -i) T[i] += v; };
    auto ask = [&](vector<long long>& T, int i) { long long s = 0; for (; i > 0; i -= i & -i) s += T[i]; return s; };
    long long f = 0, total = 0, sumAll = 0;
    for (int x : a) {
        long long le = ask(cntT, x), sumLe = ask(sumT, x);
        f += (long long)x * (le + 1) + (sumAll - sumLe);   // exact; fits in long long
        total = (total + f) % MOD;
        add(cntT, x, 1); add(sumT, x, x); sumAll += x;
    }
    return (int)total;
}

// B17. Largest Area after Each Cut — ordered sets of cut positions + multisets of gaps.  O(n log n)
vector<long long> getMaxArea(int w, int h, vector<int> isVertical, vector<int> distance) {
    set<int> xs = {0, w}, ys = {0, h};
    multiset<int> gx = {w}, gy = {h};
    vector<long long> res;
    for (size_t i = 0; i < isVertical.size(); i++) {
        set<int>& pos = isVertical[i] ? xs : ys;
        multiset<int>& gap = isVertical[i] ? gx : gy;
        int d = distance[i];
        auto it = pos.insert(d).first;
        int lo = *prev(it), hi = *next(it);
        gap.erase(gap.find(hi - lo));
        gap.insert(d - lo); gap.insert(hi - d);
        res.push_back((long long)*gx.rbegin() * *gy.rbegin());
    }
    return res;
}
