// IBM OA (on-campus, HackerRank) — C++ solutions for every question
// reconstructed from the zip screenshots (2024 IBM India campus drives)
// plus the most-reported 2025-26 IBM HackerRank questions.
// Compile & self-test:  g++ -std=c++17 -O2 IBM_OA_solutions.cpp -o t && ./t
#include <bits/stdc++.h>
using namespace std;

// ======================= PART A: ZIP (actual screenshots) =======================

// A1. playSegments — coins game (July 2024).  O(n) prefix sum.
int playSegments(vector<int> coins) {
    int n = coins.size();
    long long total = 0;
    for (int c : coins) total += (c == 1 ? 1 : -1);
    long long p1 = 0;                       // Player 1 score after i segments
    for (int i = 0; i <= n; i++) {          // i = segments Player 1 plays (0 allowed)
        if (p1 > total - p1) return i;      // Player 2 gets the rest
        if (i < n) p1 += (coins[i] == 1 ? 1 : -1);
    }
    return n;
}

// A2. minJumps — from i jump to i+nums[i] OR to i+1 (BITS Aug 2024, Q1).
// Edges only go forward, so a single left-to-right DP is a BFS. O(n).
int minJumps(int n, vector<int> nums) {
    const int INF = INT_MAX / 2;
    vector<int> d(n, INF);
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == INF) continue;
        if (i + 1 < n) d[i + 1] = min(d[i + 1], d[i] + 1);
        long long j = (long long)i + nums[i];
        if (nums[i] > 0 && j < n) d[j] = min(d[j], d[i] + 1);
        // If hidden tests fail, the setter may allow overshooting:
        // replace the line above with  j = min<long long>(j, n-1);
    }
    return d[n - 1];
}

// A3. Clock hands overlap — "Multiverse / DemoKing" (BITS Aug 2024, Q2).
// Work in half-degrees so everything is an integer:
//   minute hand = 12*m, hour hand = 60*h + m   (hour hand moves with every minute)
// Simulate up to 720 minutes ahead (the dial repeats every 12 h).
int clockOverlap(int hh, int mm) {
    int T = (hh % 12) * 60 + mm;
    for (int t = 0; t <= 720; t++) {
        int cur = (T + t) % 720, h = cur / 60, m = cur % 60;
        if ((12 * m) % 720 == (60 * h + m) % 720) return t;
    }
    return -1;
}
// If the setter means continuous movement (overlaps every 720/11 min),
// answer = ceil(next overlap - T):
int clockOverlapContinuous(int hh, int mm) {
    int T = (hh % 12) * 60 + mm;
    for (int k = 0; k <= 11; k++) {              // overlap times = 720k/11
        if (720 * k >= 11 * T) return (720 * k - 11 * T + 10) / 11;
    }
    return -1;
}

// A4. numberOfSubint — count length-k substrings of m that divide m
// (BITS Aug 2024, Q3).  Same as LeetCode 2269 "K-Beauty of a Number".
int numberOfSubint(int m, int k) {
    string s = to_string(m);
    int cnt = 0;
    for (int i = 0; i + k <= (int)s.size(); i++) {
        long long v = stoll(s.substr(i, k));    // leading zeros allowed ("02" = 2)
        if (v != 0 && m % v == 0) cnt++;        // 0 never divides
    }
    return cnt;
}

// A5. getMaxValueSum — decrypt ONE contiguous group of size <= k (IIIT-B Sep 2024, Q1).
// base = sum where binary==1; best extra = max over windows of size k of
// sum(values where binary==0).  Fixed-size sliding window, O(n).
long long getMaxValueSum(vector<int> encrypted_file, vector<int> binary, int k) {
    int n = encrypted_file.size();
    long long base = 0, gain = 0, best = 0;
    for (int i = 0; i < n; i++) {
        if (binary[i]) base += encrypted_file[i];
        else gain += encrypted_file[i];
        if (i >= k && !binary[i - k]) gain -= encrypted_file[i - k];
        best = max(best, gain);
    }
    return base + best;
}

// A6. balancedOrNot — '<' must precede a matching '>' ; any '>' may become "<>"
// (IIIT-B Sep 2024, Q2).  Greedy counter, O(total length).
vector<int> balancedOrNot(vector<string> expressions, vector<int> maxReplacements) {
    vector<int> res;
    for (size_t q = 0; q < expressions.size(); q++) {
        long long open = 0, need = 0;
        for (char c : expressions[q]) {
            if (c == '<') open++;
            else if (open > 0) open--;      // '>' matches an earlier '<'
            else need++;                     // unmatched '>' -> replace with "<>"
        }
        res.push_back(open == 0 && need <= maxReplacements[q] ? 1 : 0);
    }
    return res;
}

// A7. Regex — valid HackerRank email (NIT Patna Sep 2024, Q1).
// Only the blank is editable:  regex regularExpression("<this>");
const char* EMAIL_REGEX = "^[a-z]{1,6}_?[0-9]{0,4}@hackerrank\\.com$";

// A8. areAlmostEquivalent — same length and every letter's count differs by <= 3
// (NIT Patna Sep 2024, Q2).  O(total length).
vector<string> areAlmostEquivalent(vector<string> s, vector<string> t) {
    vector<string> res;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i].size() != t[i].size()) { res.push_back("NO"); continue; }
        int f[26] = {0};
        for (char c : s[i]) f[c - 'a']++;
        for (char c : t[i]) f[c - 'a']--;
        bool ok = true;
        for (int x : f) if (abs(x) > 3) ok = false;
        res.push_back(ok ? "YES" : "NO");
    }
    return res;
}

// ================== PART B: reported 2025-26 IBM HackerRank questions ==================

// B1. High-load timestamps: indices with load[i] > 2*average. Integer compare.
vector<int> highLoadIndices(vector<long long> load) {
    long long n = load.size(), total = 0;
    for (long long x : load) total += x;
    vector<int> r;
    for (int i = 0; i < n; i++) if (load[i] * n > 2 * total) r.push_back(i);
    return r;
}

// B2. Minimum total cost: pick the cheapest option per item; -1 if an item has none.
long long minTotalCost(int numItems, vector<int> itemId, vector<long long> cost) {
    vector<long long> best(numItems, LLONG_MAX);
    for (size_t i = 0; i < itemId.size(); i++)
        best[itemId[i]] = min(best[itemId[i]], cost[i]);
    long long sum = 0;
    for (long long b : best) { if (b == LLONG_MAX) return -1; sum += b; }
    return sum;
}

// B3. Max non-overlapping intervals [start, end): sort by END, greedy.
int maxNonOverlapping(vector<int> st, vector<int> en) {
    vector<pair<int,int>> v;
    for (size_t i = 0; i < st.size(); i++) v.push_back({en[i], st[i]});
    sort(v.begin(), v.end());
    int cnt = 0; long long last = LLONG_MIN;
    for (auto [e, s] : v) if (s >= last) { cnt++; last = e; }
    return cnt;
}

// B4. Max increase arr[j]-arr[i], i<j, arr[i]<arr[j]; -1 if none. Prefix minimum.
int maxIncrease(vector<int> a) {
    int mn = a[0], best = -1;
    for (size_t j = 1; j < a.size(); j++) {
        if (a[j] > mn) best = max(best, a[j] - mn);
        mn = min(mn, a[j]);
    }
    return best;
}

// B5. Minimum link reassignments to connect all n nodes (1-based). Union-Find.
struct DSU {
    vector<int> p;
    DSU(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }
    bool u(int a, int b) { a = f(a); b = f(b); if (a == b) return false; p[a] = b; return true; }
};
int minReassignments(int n, vector<int> from, vector<int> to) {
    if ((long long)from.size() < n - 1) return -1;   // not enough links at all
    DSU d(n + 1);
    int comps = n;
    for (size_t i = 0; i < from.size(); i++) if (d.u(from[i], to[i])) comps--;
    return comps - 1;
}

// B6. Login replacement counter: 3 consecutive "error"s for the same id -> +1, reset.
int loginReplacements(vector<pair<string,string>> logs) {
    unordered_map<string,int> streak;
    int total = 0;
    for (auto& [id, st] : logs) {
        if (st == "error") { if (++streak[id] == 3) { total++; streak[id] = 0; } }
        else streak[id] = 0;
    }
    return total;
}

// B7. Earliest time to reach target: at second i you may take directions[i] or stay.
// Greedy: take a move only if it brings you closer on that axis. O(n).
int earliestTime(string dir, long long sx, long long sy, long long ex, long long ey) {
    long long dx = ex - sx, dy = ey - sy;
    if (dx == 0 && dy == 0) return 0;
    for (int i = 0; i < (int)dir.size(); i++) {
        char c = dir[i];
        if (c == 'E' && dx > 0) dx--;
        else if (c == 'W' && dx < 0) dx++;
        else if (c == 'N' && dy > 0) dy--;
        else if (c == 'S' && dy < 0) dy++;
        if (dx == 0 && dy == 0) return i + 1;
    }
    return -1;
}

// B8. Invalid service-log groups: group by sid, sort by time, must start "DOWN"
// and strictly alternate DOWN/UP. Return number of invalid groups.
int invalidGroups(vector<tuple<string,long long,string>> logs) {
    map<string, vector<pair<long long,string>>> g;
    for (auto& [sid, ts, st] : logs) g[sid].push_back({ts, st});
    int bad = 0;
    for (auto& [sid, v] : g) {
        sort(v.begin(), v.end());
        bool ok = v[0].second == "DOWN";
        for (size_t i = 1; i < v.size() && ok; i++) if (v[i].second == v[i-1].second) ok = false;
        if (!ok) bad++;
    }
    return bad;
}

// B9. Bus routes (older IBM systems-lab campus OA): a x b city, each route covers
// row r, columns [s, e] (inclusive). Count cells with no bus. Merge per row.
long long freeCells(long long a, long long b, vector<array<long long,3>> routes) {
    map<long long, vector<pair<long long,long long>>> rows;
    for (auto& r : routes) rows[r[0]].push_back({r[1], r[2]});
    long long covered = 0;
    for (auto& [row, v] : rows) {
        sort(v.begin(), v.end());
        long long cs = v[0].first, ce = v[0].second;
        for (size_t i = 1; i < v.size(); i++) {
            if (v[i].first <= ce + 1) ce = max(ce, v[i].second);
            else { covered += ce - cs + 1; cs = v[i].first; ce = v[i].second; }
        }
        covered += ce - cs + 1;
    }
    return a * b - covered;
}

// ========== PART C: IBM SYSTEMS (ISDL) tests 2024 — from your 2nd and 3rd zips ==========

// C1. is_valid_bst — level-order STRING_ARRAY with "null"; DO NOT USE RECURSION.
// (IBM Systems 8 Sep AND 24 Aug — asked twice.)  Build with a queue, then
// iterative in-order traversal: values must be strictly increasing.
struct TreeNode { int val; TreeNode *left = nullptr, *right = nullptr; TreeNode(int v) : val(v) {} };
TreeNode* deserialize(const vector<string>& a) {
    if (a.empty() || a[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(a[0]));
    queue<TreeNode*> q; q.push(root);
    size_t i = 1;
    while (!q.empty() && i < a.size()) {
        TreeNode* cur = q.front(); q.pop();
        if (i < a.size() && a[i] != "null") { cur->left = new TreeNode(stoi(a[i])); q.push(cur->left); }
        i++;
        if (i < a.size() && a[i] != "null") { cur->right = new TreeNode(stoi(a[i])); q.push(cur->right); }
        i++;
    }
    return root;
}
bool is_valid_bst(vector<string> root) {
    TreeNode* cur = deserialize(root);
    stack<TreeNode*> st;
    bool hasPrev = false; long long prev = 0;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        if (hasPrev && cur->val <= prev) return false;   // duplicates -> not a BST
        prev = cur->val; hasPrev = true;
        cur = cur->right;
    }
    return true;
}

// C2. sort_by_area — HackerRank "Small Triangles, Large Triangles" (IBM Systems 8 Sep, C).
// Compare 16*S^2 = (a+b+c)(-a+b+c)(a-b+c)(a+b-c) as integers: no floating error.
struct triangle { int a, b, c; };
long long area16(const triangle& t) {
    long long a = t.a, b = t.b, c = t.c;
    return (a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c);
}
void sort_by_area(triangle* tr, int n) {
    sort(tr, tr + n, [](const triangle& x, const triangle& y) { return area16(x) < area16(y); });
}

// C3. convertToIpv6 (IBM Systems 8 Sep).  "192.168.10.92" -> "::FFFF:C0A8:0A5C",
// any 127.x.x.x -> "::1".  Uppercase hex, 2 digits per octet.
string convertToIpv6(const string& ip) {
    int o[4];
    sscanf(ip.c_str(), "%d.%d.%d.%d", &o[0], &o[1], &o[2], &o[3]);
    if (o[0] == 127) return "::1";
    char buf[32];
    snprintf(buf, sizeof buf, "::FFFF:%02X%02X:%02X%02X", o[0], o[1], o[2], o[3]);
    return buf;   // in the real template: printf("%s\n", buf);
}

// C4. binAddition — add two binary strings (IBM Systems 24 Aug). |s| <= 1000.
// Keep the result's natural length ("100"+"010" -> "110", "111"+"11" -> "1010").
string binAddition(string a, string b) {
    string r; int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int s = carry + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
        r.push_back('0' + s % 2); carry = s / 2;
    }
    reverse(r.begin(), r.end());
    size_t k = r.find_first_not_of('0');         // strip leading zeros, keep "0"
    return k == string::npos ? "0" : r.substr(k);
}

// C5. findYoungestMember (IBM Systems 24 Aug, asked in 2 variants).
// members[i] = "Name,LastName,Age". Among members whose age is NOT in ages[],
// return the first name of the youngest (first occurrence on ties); "null" if none.
string findYoungestMember(vector<int> ages, vector<string> members) {
    unordered_set<int> present(ages.begin(), ages.end());
    string best = "null"; int bestAge = INT_MAX;
    for (string m : members) {
        m.erase(remove_if(m.begin(), m.end(), [](char ch){ return ch=='\'' || ch=='"' || ch==' '; }), m.end());
        size_t p1 = m.find(','), p2 = m.rfind(',');
        if (p1 == string::npos) continue;
        string name = m.substr(0, p1);
        int age = stoi(m.substr(p2 + 1));
        if (!present.count(age) && age < bestAge) { bestAge = age; best = name; }
    }
    return best;
}

// C6. minFriends — min possible size of the LARGEST clique in any graph with
// n nodes and m edges (IBM Systems 24 Aug).  Turán's theorem (= HackerRank "Clique"):
// a k-partite Turán graph has the most edges with no (k+1)-clique.
// Answer = smallest k with turanEdges(n, k) >= m.  Binary search, long long.
long long turanEdges(long long n, long long k) {
    long long q = n / k, r = n % k;
    long long sumSq = r * (q + 1) * (q + 1) + (k - r) * q * q;
    return (n * n - sumSq) / 2;
}
long long minFriends(long long n, long long m) {
    long long lo = 1, hi = n;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (turanEdges(n, mid) >= m) hi = mid; else lo = mid + 1;
    }
    return lo;
}

// C7. minSubArrayLen = LeetCode 209 (IBM Systems 24 Aug variant). Positive ints.
int minSubArrayLen(vector<int> nums, int target) {
    int best = INT_MAX, l = 0; long long s = 0;
    for (int r = 0; r < (int)nums.size(); r++) {
        s += nums[r];
        while (s >= target) { best = min(best, r - l + 1); s -= nums[l++]; }
    }
    return best == INT_MAX ? 0 : best;
}

// C8. last_animal_name_length — names separated by '-', ignore leading/trailing '-'
// (IBM Systems 24 Aug variant; like LeetCode 58).
int last_animal_name_length(string s) {
    int i = (int)s.size() - 1, len = 0;
    while (i >= 0 && s[i] == '-') i--;
    while (i >= 0 && s[i] != '-') { len++; i--; }
    return len;
}

// C9. Host a new service in all clusters (IBM Systems 10 Aug Diversity, Q24)
// = HackerRank "Roads and Libraries".  If linking is not cheaper, host everywhere;
// else per connected component: one host + (size-1) links.
long long minServiceCost(int n, long long cLink, long long cService, vector<pair<int,int>> pairs) {
    if (cLink >= cService) return (long long)n * cService;
    DSU d(n + 1);
    int comps = n;
    for (auto [a, b] : pairs) if (d.u(a, b)) comps--;
    return (long long)comps * cService + (long long)(n - comps) * cLink;
}

// ======== PART E: MathWorks test that was mixed into the diversity folder ========
// (banner "MathWorks | NIT Warangal" on test b9t79o2rsd1) — good practice, not IBM.

// E1. Ball Collision = LeetCode 735 Asteroid Collision, returning indices.
vector<int> findRemainingBalls(vector<int> direction, vector<int> strength) {
    vector<int> st;                                   // indices of surviving balls
    for (int i = 0; i < (int)direction.size(); i++) {
        bool alive = true;
        if (direction[i] == -1) {
            while (!st.empty() && direction[st.back()] == 1) {
                int j = st.back();
                if (strength[j] < strength[i]) { st.pop_back(); continue; }
                if (strength[j] == strength[i]) st.pop_back();
                alive = false; break;
            }
        }
        if (alive) st.push_back(i);
    }
    return st;                                        // already in ascending order
}

// E2. Dominoes Painting = AtCoder ABC071 D. 2xN board; same char in a column = vertical
// domino, else a horizontal pair stacked. 3 colours, neighbours differ, mod 1e9+7.
long long countDistinctColorings(vector<string> domino) {
    const long long MOD = 1e9 + 7;
    const string& t = domino[0]; const string& b = domino[1];
    int n = t.size(), i = 0; long long ways = 0; int prev = -1;   // 0 = vertical, 1 = horizontal
    while (i < n) {
        int cur = (t[i] == b[i]) ? 0 : 1;
        if (prev == -1) ways = (cur == 0 ? 3 : 6);
        else if (prev == 0) ways = ways * 2 % MOD;               // V->V 2, V->H 2
        else ways = ways * (cur == 0 ? 1 : 3) % MOD;             // H->V 1, H->H 3
        prev = cur; i += (cur == 0 ? 1 : 2);
    }
    return ways;
}

// E3. Minimum Complexity Level = LeetCode 1335 Minimum Difficulty of a Job Schedule.
// dp[d][i] = min cost to split first i lectures into d days. O(n^2 * days).
long long findMinComplexity(vector<int> c, int days) {
    int n = c.size();
    if (days > n) return -1;
    const long long INF = LLONG_MAX / 4;
    vector<vector<long long>> dp(days + 1, vector<long long>(n + 1, INF));
    dp[0][0] = 0;
    for (int d = 1; d <= days; d++)
        for (int i = d; i <= n; i++) {
            int mx = 0;
            for (int j = i; j >= d; j--) {          // last day = lectures j..i (1-based)
                mx = max(mx, c[j - 1]);
                if (dp[d - 1][j - 1] < INF) dp[d][i] = min(dp[d][i], dp[d - 1][j - 1] + mx);
            }
        }
    return dp[days][n];
}

// E4. Shader Loader — minimise the longest run of equal chars with <= k flips.
// Binary search L. For L >= 2: a run of length r needs r/(L+1) flips.
// L = 1 means a fully alternating string: cost = min mismatches vs "abab.." / "baba..".
int findMinimumIdleness(string s, int k) {
    int n = s.size();
    auto feasible = [&](int L) {
        if (L == 1) {
            int c1 = 0;
            for (int i = 0; i < n; i++) if (s[i] != (i % 2 ? 'b' : 'a')) c1++;
            return min(c1, n - c1) <= k;
        }
        long long need = 0;
        for (int i = 0; i < n;) {
            int j = i; while (j < n && s[j] == s[i]) j++;
            need += (j - i) / (L + 1); i = j;
        }
        return need <= k;
    };
    int lo = 1, hi = n;
    while (lo < hi) { int mid = (lo + hi) / 2; if (feasible(mid)) hi = mid; else lo = mid + 1; }
    return lo;
}

// =============================== self-tests ===============================
int fails = 0;
#define CHECK(expr, want) do { auto _g = (expr); auto _w = (want); \
    if (_g == _w) cout << "PASS  " << #expr << "\n"; \
    else { cout << "FAIL  " << #expr << "\n"; fails++; } } while (0)

int main() {
    // A1
    CHECK(playSegments({1, 1, 0, 1}), 2);
    CHECK(playSegments({1, 0, 0, 1, 0}), 0);
    // A2
    CHECK(minJumps(5, {3, 0, 0, 1, 0}), 2);
    CHECK(minJumps(1, {0}), 0);
    CHECK(minJumps(4, {0, 0, 0, 0}), 3);
    // A3
    CHECK(clockOverlap(11, 59), 1);
    CHECK(clockOverlapContinuous(11, 59), 1);
    CHECK(clockOverlapContinuous(1, 0), 6);      // overlap at 1:05:27
    // A4
    CHECK(numberOfSubint(500, 1), 1);
    CHECK(numberOfSubint(224, 2), 0);
    CHECK(numberOfSubint(240, 2), 2);            // LeetCode 2269 sample
    CHECK(numberOfSubint(430043, 2), 2);         // LeetCode 2269 sample
    // A5
    CHECK(getMaxValueSum({7, 4, 3, 5}, {1, 0, 0, 0}, 2), 15LL);
    CHECK(getMaxValueSum({1, 3, 5, 2, 5, 4}, {1, 1, 0, 1, 0, 0}, 3), 16LL);
    // A6
    CHECK(balancedOrNot({"<<>>", "<>", "<><>", ">>", "<<>", "><><"}, {0, 1, 2, 2, 2, 2}),
          vector<int>({1, 1, 1, 1, 0, 0}));
    CHECK(balancedOrNot({"<>>>", "<>>>>"}, {2, 2}), vector<int>({1, 0}));
    CHECK(balancedOrNot({"<>", "<>><"}, {1, 0}), vector<int>({1, 0}));
    CHECK(balancedOrNot({"<<<><><>"}, {2}), vector<int>({0}));
    // A7
    {
        regex re(EMAIL_REGEX);
        vector<string> q = {"julia@hackerrank.com", "julia_@hackerrank.com",
                            "julia_0@hackerrank.com", "julia0_@hackerrank.com",
                            "julia@gmail.com", "abcdef_1234@hackerrank.com",
                            "a1_1@baddomain.com", "abcdefg@hackerrank.com"};
        vector<bool> got;
        for (auto& s : q) got.push_back(regex_match(s, re));
        CHECK(got, vector<bool>({true, true, true, false, false, true, false, false}));
    }
    // A8
    CHECK(areAlmostEquivalent({"aabaab", "aaaaabb"}, {"bbabbc", "abb"}),
          vector<string>({"YES", "NO"}));
    CHECK(areAlmostEquivalent({"aaa"}, {"aab"}), vector<string>({"YES"}));
    // B1-B9
    CHECK(highLoadIndices({1, 2, 9}), vector<int>({2}));
    CHECK(minTotalCost(3, {2, 0, 1, 2}, {8, 7, 6, 9}), 21LL);
    CHECK(maxNonOverlapping({1, 2, 3, 1}, {3, 4, 5, 2}), 2);
    CHECK(maxNonOverlapping({1, 2, 3, 1}, {2, 3, 4, 3}), 3);
    CHECK(maxIncrease({7, 1, 5, 3, 6, 4}), 5);
    CHECK(maxIncrease({5, 4, 3}), -1);
    CHECK(minReassignments(4, {1, 1, 3}, {2, 3, 4}), 0);
    CHECK(minReassignments(4, {1, 2, 1}, {2, 3, 3}), 1);
    CHECK(minReassignments(4, {1}, {2}), -1);
    CHECK(loginReplacements({{"u1","error"},{"u1","error"},{"u1","error"},
                             {"u2","error"},{"u2","success"},{"u2","error"},{"u2","error"}}), 1);
    CHECK(earliestTime("WWNNSSE", 1, 1, -1, -1), 6);
    CHECK(earliestTime("NNN", 0, 0, 1, 0), -1);
    CHECK(invalidGroups({{"a",1,"DOWN"},{"a",2,"UP"},{"b",5,"UP"},{"c",3,"UP"},{"c",1,"DOWN"},{"c",2,"DOWN"}}), 2);
    CHECK(freeCells(3, 3, {{1,2,3},{2,1,2},{3,1,3}}), 2LL);
    // C1-C9 (samples from the screenshots)
    CHECK(is_valid_bst({"2", "1", "3"}), true);                       // stdin sample: 3 / 2 1 3
    CHECK(is_valid_bst({"5", "1", "4", "null", "null", "3", "6"}), false);
    CHECK(is_valid_bst({"2", "2", "2"}), false);
    CHECK(is_valid_bst({}), true);
    {
        triangle tr[3] = {{7, 24, 25}, {5, 12, 13}, {3, 4, 5}};
        sort_by_area(tr, 3);
        CHECK(vector<int>({tr[0].a, tr[1].a, tr[2].a}), vector<int>({3, 5, 7}));
    }
    CHECK(convertToIpv6("192.168.10.92"), string("::FFFF:C0A8:0A5C"));
    CHECK(convertToIpv6("127.0.0.1"), string("::1"));
    CHECK(convertToIpv6("0.0.0.0"), string("::FFFF:0000:0000"));
    CHECK(binAddition("100", "010"), string("110"));
    CHECK(binAddition("111", "11"), string("1010"));
    CHECK(binAddition("0", "0"), string("0"));
    CHECK(findYoungestMember({1, 2, 3, 4, 5}, {"Ram,D,1", "Dev,B,2", "Adam,Jobs,3", "Adam,Jobs,4", "Ema,K,5",
                              "Leena,Jack,7", "Patric,Queen,8", "Liam,Jones,9", "Riya,N,10", "Dilip,K,22"}),
          string("Leena"));
    CHECK(findYoungestMember({1, 2}, {"'A,B,1'", "'C,D,2'"}), string("null"));
    CHECK(minFriends(2, 1), 2LL);
    CHECK(minFriends(3, 2), 2LL);
    CHECK(minFriends(5, 7), 3LL);
    CHECK(minFriends(4, 6), 4LL);
    CHECK(minSubArrayLen({1, 4, 4}, 4), 1);
    CHECK(minSubArrayLen({1, 1, 1, 1, 1, 1, 1, 1}, 11), 0);
    CHECK(minSubArrayLen({2, 3, 1, 2, 4, 3}, 7), 2);
    CHECK(last_animal_name_length("cat-dog-lion"), 4);
    CHECK(last_animal_name_length("--cat-dog--"), 3);
    CHECK(last_animal_name_length("---"), 0);
    CHECK(minServiceCost(5, 1, 3, {{1, 2}, {1, 3}, {3, 2}, {4, 5}}), 9LL);
    CHECK(minServiceCost(5, 3, 1, {{1, 2}, {1, 3}, {3, 2}, {4, 5}}), 5LL);
    // E1-E4
    CHECK(findRemainingBalls({1, -1}, {2, 1}), vector<int>({0}));
    CHECK(findRemainingBalls({1, -1, 1}, {5, 3, 1}), vector<int>({0, 2}));
    CHECK(findRemainingBalls({1, 1}, {3, 4}), vector<int>({0, 1}));
    CHECK(findRemainingBalls({1, -1}, {2, 2}), vector<int>({}));
    CHECK(countDistinctColorings({"baa", "bcc"}), 6LL);
    CHECK(countDistinctColorings({"xy", "xy"}), 6LL);
    CHECK(countDistinctColorings({"aacx", "ddcx"}), 12LL);
    CHECK(findMinComplexity({1, 5, 3, 2, 4}, 2), 6LL);
    CHECK(findMinComplexity({30, 10, 40, 20, 50}, 2), 80LL);
    CHECK(findMinimumIdleness("aabbbaaaa", 2), 2);
    CHECK(findMinimumIdleness("aaaaa", 1), 2);
    CHECK(findMinimumIdleness("aabbba", 6), 1);
    cout << (fails ? "\nSOME TESTS FAILED\n" : "\nALL TESTS PASSED\n");
    return fails != 0;
}
