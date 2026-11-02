# IBM OA — Part B Practice Set (17 problems) + Predicted Topics + DSA Plan

Prepared 2 Nov 2026. This replaces the short Part B table in `IBM_OA_Pattern_and_Questions.md`. Every problem is now a complete HackerRank-style statement with a function signature, constraints and samples. A local judge checks your code against hidden tests.

---

## How to practise

**Files (all in the project's `IBM/` folder; download them into one folder):**

| File | What it is |
|---|---|
| `partB_my_code.cpp` | Empty functions with the exact signatures. **You write your code here.** |
| `partB_judge.cpp` | The judge: samples + about 300 random hidden tests + 1 large test per problem, 2-second limit |
| `partB_solutions.cpp` | Reference solutions. **Spoilers:** the judge needs this file, but don't open it until you've tried |

```bash
g++ -std=c++17 -O2 partB_judge.cpp -o judge
./judge          # judge all 17
./judge B12      # judge one problem
```

- **On Windows** (MinGW/MSYS2), use the same command and run `judge.exe B12`. If your compiler complains about `std::thread`, add `-DNO_THREADS`.
- **What you'll see:** `B12 ... 303/303 PASS`, or the first failing input with the expected output and your output. An O(n²) solution shows `TIME LIMIT EXCEEDED` on the large test, just like HackerRank's hidden cases.

**Practice loop for each problem (like the real OA):**
1. Set a **25-minute timer**. Read the statement and **both samples**.
2. Write the brute force first if you're unsure, judge it, then optimise until the large test passes.
3. Stuck for 10 minutes? Read the one-line hint in the **Hints** section at the bottom.
4. After it passes, compare with `partB_solutions.cpp` for a cleaner approach.

**Legend:** ✅ = the statement's core text and sample come from a candidate report. 🟡 = rebuilt from a short summary: I filled the missing details (constraints, tie rules) so it's consistent, but the real wording may differ. **Read every IBM statement for its tie and boundary rules.**

**Also on an online judge** (instant practice without the local judge): B3 → LC 435 · B4 → **LC 2016 (exact)** · B5 → **LC 1319 (exact)** · B9 → LC 1604 (similar) · B11 → LC 253 / LC 2406 · B12 → **LC 2602 (exact)** · B14 → LC 2070 (same trick) · B15 → **LC 3035 (exact)** · B16 → LC 315 (same BIT trick) · B17 → LC 1465 (static version).

---

## B1. High-Load Timestamps ✅ *(IBM HackerRank 2025-26 — the most reported question)*
A monitoring service records the server load at `n` timestamps in the array `load`. A timestamp is *high-load* if its load is **strictly greater than twice the average load** of all `n` timestamps. Return the 0-based indices of all high-load timestamps in increasing order, or an empty array if there are none.

- **Function:** `vector<int> getHighLoadTimestamps(vector<int> load)`
- **Constraints:** `1 ≤ n ≤ 2·10⁵`, `1 ≤ load[i] ≤ 10⁹`
- **Sample 1:** `load = [1, 2, 9]` → **`[2]`**. The average is 4, so twice the average is 8; only 9 > 8.
- **Sample 2:** `load = [5, 5, 5]` → **`[]`**

## B2. Minimum Total Cost of Items ✅
A store has `numItems` items, numbered `0 … numItems−1`. There are `n` price offers: offer `i` sells item `itemId[i]` at `cost[i]`. You must buy **exactly one unit of every item** using any offer for it. Return the minimum total cost, or **−1** if some item has no offer.

- **Function:** `long long getMinimumTotalCost(int numItems, vector<int> itemId, vector<int> cost)`
- **Constraints:** `1 ≤ numItems ≤ 10⁵`, `1 ≤ n ≤ 2·10⁵`, `0 ≤ itemId[i] < numItems`, `1 ≤ cost[i] ≤ 10⁹`
- **Sample 1:** `numItems = 3, itemId = [2, 0, 1, 2], cost = [8, 7, 6, 9]` → **21** (item 0: 7, item 1: 6, item 2: min(8, 9) = 8)
- **Sample 2:** `numItems = 3, itemId = [0, 2], cost = [5, 4]` → **−1** (item 1 has no offer)

## B3. Maximum Non-Overlapping Intervals ✅
A server can run one job at a time. Job `i` occupies the half-open interval `[startTime[i], endTime[i])`. Two jobs conflict if their intervals overlap; a job ending at `t` and a job starting at `t` **do not** conflict. Return the maximum number of jobs that can run without conflicts.

- **Function:** `int maxNonOverlappingIntervals(vector<int> startTime, vector<int> endTime)`
- **Constraints:** `1 ≤ n ≤ 10⁵`, `0 ≤ startTime[i] < endTime[i] ≤ 10⁹`
- **Sample 1:** `start = [1, 2, 3, 1], end = [3, 4, 5, 2]` → **2** (for example, [1,2) and [2,4))
- **Sample 2:** `start = [1, 2, 3], end = [2, 3, 4]` → **3** (they only touch)

## B4. Maximum Water Level Increase ✅
`arr[i]` is the water level recorded on day `i`. Find the maximum value of `arr[j] − arr[i]` with `i < j` **and** `arr[i] < arr[j]`. Return −1 if the level never rises.

- **Function:** `int maxWaterLevelIncrease(vector<int> arr)`
- **Constraints:** `1 ≤ n ≤ 2·10⁶` (the judge uses 10⁶), `0 ≤ arr[i] ≤ 10⁹`
- **Sample 1:** `[7, 1, 5, 3, 6, 4]` → **5** (1 → 6)
- **Sample 2:** `[9, 4, 3, 2]` → **−1**
- **Sample 3:** `[1, 5, 2, 10]` → **9**

## B5. Minimum Reassignments for Connectivity ✅ *(= LeetCode 1319)*
There are `link_nodes` code repositories, numbered `1 … link_nodes`. Link `i` directly connects `link_from[i]` and `link_to[i]`. Repositories are *synced* if they are connected directly or through other repositories. In one **reassignment** you remove an existing link and use it to connect any two repositories. Return the minimum number of reassignments to sync **all** repositories, or **−1** if it's impossible.

- **Function:** `int minReassignments(int link_nodes, vector<int> link_from, vector<int> link_to)`
- **Constraints:** `1 ≤ link_nodes ≤ 10⁵`, `0 ≤ m ≤ 10⁵`, `link_from[i] ≠ link_to[i]` (duplicate links possible)
- **Sample 1:** `4, from = [1, 1, 3], to = [2, 3, 4]` → **0** (already one system)
- **Sample 2:** `4, from = [1, 1, 2], to = [2, 3, 3]` → **1** (the 1–2–3 triangle has a spare link; move it to node 4)
- **Sample 3:** `5, from = [1, 2], to = [2, 3]` → **−1** (5 nodes need at least 4 links)

## B6. Login Replacement Counter ✅ *(IBM AI Engineer Intern OA)*
A log has `n` login attempts in time order. Attempt `i` is by user `login_id[i]` with status `"success"` or `"error"`. If a user's **own** attempts contain 3 consecutive errors, that user's account is *replaced* and their error streak resets to 0. A success also resets that user's streak. Other users' attempts in between do **not** break a streak. Return the total number of replacements.

- **Function:** `int countReplacements(vector<string> login_id, vector<string> login_status)`
- **Constraints:** `1 ≤ n ≤ 10⁵`, ids are alphanumeric
- **Sample 1:** `u1 error, u1 error, u1 error, u2 error, u2 success, u2 error, u2 error` → **1**
- **Sample 2:** six `a error` → **2** (replaced after the 3rd and the 6th)
- **Sample 3:** `x error, y error, x error, y error, x error` → **1** (x has 3 in a row; y has only 2)

## B7. Earliest Arrival with Optional Moves 🟡 *(reported twice: 2026 NG intern + AI intern)*
A robot starts at `(startX, startY)` and must reach `(endX, endY)`. You get a command string `directions` of length `n`. At second `i` (1-based) the robot may **either** move one unit in direction `directions[i−1]` (`E`: x+1, `W`: x−1, `N`: y+1, `S`: y−1) **or stay still**. Return the earliest second at which it can stand on the target: **0** if it starts there, **−1** if it can't arrive within `n` seconds.

- **Function:** `int earliestArrival(string directions, long long startX, long long startY, long long endX, long long endY)`
- **Constraints:** `1 ≤ n ≤ 10⁵`, coordinates within `±10⁹`
- **Sample 1:** `"ENWNNE", (0,0) → (2,2)` → **6** (move at seconds 1, 2, 4, 6; stay at 3 and 5)
- **Sample 2:** `"SSS", (0,0) → (0,1)` → **−1**
- **Sample 3:** `"NE", (5,5) → (5,5)` → **0**
- *The published example (`"WWNNSSE"`, 1 −1 −1 −1 → 6) doesn't match its own rules, which would give 2. On the real test, check the coordinate order in the input format.*

## B8. Invalid Service-Log Groups ✅ *(2026 NG SDE)*
Log entry `i` says service `sid[i]` reported `status[i]` (`"UP"` or `"DOWN"`) at `timestamp[i]`. The entries are **not in time order**. Group the entries by service and sort each group by timestamp (timestamps are distinct within a group). A group is **valid** if its first status is `"DOWN"` and the statuses strictly alternate DOWN, UP, DOWN, UP… Return the number of **invalid groups** (not invalid entries).

- **Function:** `int countInvalidGroups(vector<string> sid, vector<long long> timestamp, vector<string> status)`
- **Constraints:** `1 ≤ n ≤ 10⁵`
- **Sample 1:** `sid = [a, a, b, c, c, c], ts = [1, 2, 5, 3, 1, 2], status = [DOWN, UP, UP, UP, DOWN, DOWN]` → **2** (b starts with UP; c sorted is DOWN, DOWN, UP)
- **Sample 2:** `sid = [web×3], ts = [30, 10, 20], status = [DOWN, DOWN, UP]` → **0** (sorted: 10 DOWN, 20 UP, 30 DOWN, which is valid. **Sort first!**)

## B9. Frequent IPs in a Time Window 🟡 *(2026 NG intern)*
Request `i` came from IP `ip[i]` at second `timestamp[i]`, and timestamps are in non-decreasing order. An IP is *suspicious* if it made **more than `k`** requests within some window `[x, x + t)` of length `t`. Equivalently, it has `k+1` requests whose first and last timestamps differ by **less than `t`**. Return all suspicious IPs in **increasing order**, or an empty array.

- **Function:** `vector<int> frequentIps(vector<int> ip, vector<int> timestamp, int k, int t)`
- **Constraints:** `1 ≤ n ≤ 10⁵`, `1 ≤ k, t ≤ 10⁹`
- **Sample 1:** `ip = [1, 2, 1], ts = [6, 10, 15], k = 1, t = 10` → **`[1]`** (15 − 6 = 9 < 10)
- **Sample 2:** `ip = [5, 7, 5, 7, 5], ts = [1, 2, 3, 4, 20], k = 1, t = 3` → **`[5, 7]`**
- **Sample 3:** same as sample 2 with `t = 2` → **`[]`** (a difference of 2 is **not** < 2)

## B10. Shortest Subarray with Exactly k Distinct Values 🟡 *(2026 NG SDE + IBM question bank)*
Return the minimum length of a contiguous subarray of `arr` that contains **exactly `k` distinct values**, or −1 if none exists.

- **Function:** `int shortestSubarrayKDistinct(vector<int> arr, int k)`
- **Constraints:** `1 ≤ n ≤ 10⁵`, `1 ≤ k ≤ n`, `−10⁹ ≤ arr[i] ≤ 10⁹`
- **Sample 1:** `[1, 2, 1, 3, 4], k = 3` → **3** (`[2,1,3]` or `[1,3,4]`)
- **Sample 2:** `[1, 1, 1], k = 2` → **−1**
- **Sample 3:** `[4, 4, 2, 2, 4, 5], k = 2` → **2**

## B11. Minimum Meeting Rooms ✅ *(IBM question bank; = LeetCode 253)*
Meeting `i` uses the half-open interval `[start[i], end[i])`. A meeting ending at `t` frees its room for one starting at `t`. Return the minimum number of rooms needed for all meetings.

- **Function:** `int minMeetingRooms(vector<int> start, vector<int> end)`
- **Constraints:** `1 ≤ n ≤ 10⁵`, `0 ≤ start[i] < end[i] ≤ 10⁹`
- **Sample 1:** `start = [0, 5, 15], end = [30, 10, 20]` → **2**
- **Sample 2:** `start = [1, 2], end = [2, 3]` → **1**
- **Sample 3:** `start = [1, 2, 3], end = [4, 5, 6]` → **3**

## B12. Minimum Operations for Each Price Query ✅ *(IBM NG/intern, "a shop in HackerLand"; = LeetCode 2602)*
A shop has `n` items with prices `price[i]`. In one operation you can increase or decrease one item's price by 1. For each `query[j]`, independently and starting from the original prices, return the minimum number of operations to make **every** price equal to `query[j]`.

- **Function:** `vector<long long> getMinimumOperations(vector<int> price, vector<int> query)`
- **Constraints:** `1 ≤ n, q ≤ 10⁵`, `1 ≤ price[i], query[j] ≤ 10⁹` (answers need 64-bit)
- **Sample 1:** `price = [1, 2, 3], query = [3, 2, 1, 5]` → **`[3, 2, 3, 9]`**
- **Sample 2:** `price = [10], query = [10, 1]` → **`[0, 9]`**

## B13. Minimize Array Cost by Inserting One Element ✅ *(IBM Software Developer full-time OA)*
The cost of an array is `Σ (arr[i] − arr[i−1])²` over adjacent pairs. You must insert **exactly one integer** anywhere in the array, including either end. Return the minimum possible cost after the insertion.

- **Function:** `long long minimizeArrayCost(vector<int> arr)`
- **Constraints:** `2 ≤ n ≤ 2·10⁵`, `1 ≤ arr[i] ≤ 10⁵`
- **Sample 1:** `[1, 3, 5, 2, 10]` → **49** (the cost is 81 before; inserting 6 between 2 and 10 gives 4 + 4 + 9 + 16 + 16 = 49)
- **Sample 2:** `[4, 4]` → **0**
- **Sample 3:** `[1, 4]` → **5** (insert 2 or 3)

## B14. First Greater Index ✅ *(IBM HackerRank, LeetCode Discuss report)*
For every element `x` of `arr1`, find the **smallest index `j`** such that `arr2[j] > x`. Return the results as an array, using −1 where no such index exists.

- **Function:** `vector<int> firstGreaterIndex(vector<int> arr1, vector<int> arr2)`
- **Constraints:** `1 ≤ n, m ≤ 10⁵`, values `≤ 10⁹`
- **Sample 1:** `arr1 = [3, 1, 5, 6], arr2 = [4, 1, 5, 6]` → **`[0, 0, 3, −1]`**
- **Sample 2:** `arr1 = [0, 9], arr2 = [2, 2, 9]` → **`[0, −1]`**

## B15. Maximum Palindromes After Swaps 🟡 *(IBM question bank; = LeetCode 3035)*
You have `n` lowercase words. Any number of times, you may swap **any two characters**, in the same word or in different words. Word lengths never change. Return the maximum number of words that can be palindromes at the same time.

- **Function:** `int maxPalindromesAfterSwaps(vector<string> words)`
- **Constraints:** `1 ≤ n ≤ 1000`, `1 ≤ |word| ≤ 100`
- **Sample 1:** `["abbb", "ba", "aa"]` → **3**
- **Sample 2:** `["abc", "ab"]` → **2**
- **Sample 3:** `["cd", "ef", "a"]` → **1**

## B16. Sorted Sums ✅ *(confirmed IBM HackerRank question)*
For an array `a`, define `f(i)` as follows: sort the first `i` elements ascending into `b₁ ≤ b₂ ≤ … ≤ bᵢ`, then `f(i) = 1·b₁ + 2·b₂ + … + i·bᵢ`. Return `(f(1) + f(2) + … + f(n)) mod (10⁹ + 7)`.

- **Function:** `int sortedSums(vector<int> a)`
- **Constraints:** `1 ≤ n ≤ 10⁵`, `1 ≤ a[i] ≤ 10⁶`. Re-sorting each prefix is too slow (O(n² log n)).
- **Sample 1:** `[9, 5, 8]` → **80**. f(1) = 9; f(2) = 1·5 + 2·9 = 23; f(3) = 1·5 + 2·8 + 3·9 = 48.
- **Sample 2:** `[1, 1]` → **4**

## B17. Largest Area After Each Cut ✅ *(confirmed IBM HackerRank question, "Largest Area")*
A `w × h` sheet is cut by `n` full-length cuts, one at a time. Cut `i` is vertical at `x = distance[i]` if `isVertical[i] = 1`, otherwise horizontal at `y = distance[i]`. After **each** cut, report the area of the largest piece. Cut positions are distinct for each orientation and strictly inside the sheet.

- **Function:** `vector<long long> getMaxArea(int w, int h, vector<int> isVertical, vector<int> distance)`
- **Constraints:** `2 ≤ w, h ≤ 10⁹`, `1 ≤ n ≤ 10⁵`
- **Sample 1:** `w = 4, h = 4, isVertical = [0, 1], distance = [3, 1]` → **`[12, 9]`** (after y=3: 4×3; after x=1: 3×3)
- **Sample 2:** `w = 2, h = 3, isVertical = [1], distance = [1]` → **`[3]`**

---

# Part 2 — What IBM is most likely to ask (my prediction)

I counted every question we have: your 3 zips (about 25 coding questions from 7 IBM tests in 2024), the 2025–26 reports above, and the IIT Delhi JNFs.

| Rank | Pattern | Seen in | Likelihood | Typical disguise |
|---|---|---|---|---|
| 1 | **Single pass / prefix sum / sliding window** | 9 (playSegments, encrypted files, high-load, water level, min-subarray, exactly-k-distinct, price queries…) | **Very high** | Server load, coins, files, water levels |
| 2 | **Hashmap grouping and frequency counting** | 8 (almost-equivalent, min cost per item, logins, log groups, youngest member, IPs, anagram…) | **Very high** | Logs, users, items, members |
| 3 | **String parsing and formatting** | 7 (IPv6, binary add, regex, k-beauty, last word, animal names, records) | **High (very high for ISDL)** | IP addresses, CSV-like records, emails |
| 4 | **Sort + greedy** | 5 (intervals, meeting rooms, insert-one cost, triangles, almost-sorted choices) | **High** | Jobs, meetings, schedules |
| 5 | **Graph connectivity: union-find / BFS** | 5 (reassignment, roads & libraries, jumps, Turán, ISP hosts) | **Medium-high** | Repositories, clusters, networks |
| 6 | **Binary search** (sorted array / prefix max / on the answer) | 3 | Medium | Price queries, first greater, minimise the maximum |
| 7 | **Stack / bracket matching** | 2 (balancedOrNot, ball collision) | Medium | Brackets, collisions |
| 8 | **Iterative tree traversal** | 2 (valid BST ×2, ISDL) | Medium (ISDL) | "DO NOT USE RECURSION" |
| 9 | **DP** | 2–3 (min jumps; a 2026 report says "DP with a twist") | Low-medium | Scheduling, jumps |
| 10 | **Fenwick tree / ordered multiset** | 2 (Sorted Sums, Largest Area) | Low (harder variants) | Running weighted sums, cuts |

**My bet for the coding part:** one **array/hashmap** question (ranks 1–2) plus one **sort-greedy, graph or string-parsing** question (ranks 3–5), each LeetCode Easy–Medium with n up to 10⁵. For ISDL, add C-flavoured string/number questions and the MCQ bank in Part D of the main doc.

---

# Part 3 — Recommended DSA practice

## Today's must-do 15 (about 4–5 hours; in this order)
| # | Problem | Why |
|---|---|---|
| 1 | [LC 2016 Max Difference Between Increasing Elements](https://leetcode.com/problems/maximum-difference-between-increasing-elements/) | = B4, running min |
| 2 | [LC 1052 Grumpy Bookstore Owner](https://leetcode.com/problems/grumpy-bookstore-owner/) | = the encrypted-files question, fixed window |
| 3 | [LC 209 Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | Asked by IBM Systems; variable window |
| 4 | [LC 2068 Two Strings Almost Equivalent](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/) | Asked by IBM (NIT Patna) |
| 5 | [LC 49 Group Anagrams](https://leetcode.com/problems/group-anagrams/) | Hashmap grouping (Sep 2025 anagram question) |
| 6 | [LC 435 Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) | = B3 |
| 7 | [LC 2406 Divide Intervals Into Min Groups](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/) | Free version of B11 (inclusive ends: careful) |
| 8 | [LC 1319 Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) | = B5, union-find |
| 9 | [HackerRank Roads and Libraries](https://www.hackerrank.com/challenges/torque-and-development/problem) | Asked by IBM Systems (cluster hosting) |
| 10 | [LC 2602 Min Operations to Make All Elements Equal](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/) | = B12, sort + prefix + binary search |
| 11 | [LC 921 Min Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) | Same counter idea as balancedOrNot |
| 12 | [LC 98 Validate BST](https://leetcode.com/problems/validate-binary-search-tree/) | Asked twice by IBM Systems; **solve iteratively** |
| 13 | [LC 67 Add Binary](https://leetcode.com/problems/add-binary/) | Asked by IBM Systems |
| 14 | [LC 45 Jump Game II](https://leetcode.com/problems/jump-game-ii/) | Close to minJumps |
| 15 | [LC 992 Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) | Exactly-k-distinct technique (B10) |

## Full list by pattern (after the 15 above)
- **Sliding window and prefix sums:** [LC 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) · [LC 438](https://leetcode.com/problems/find-all-anagrams-in-a-string/) · [LC 560](https://leetcode.com/problems/subarray-sum-equals-k/) · [LC 974](https://leetcode.com/problems/subarray-sums-divisible-by-k/) · [LC 1004](https://leetcode.com/problems/max-consecutive-ones-iii/) · [LC 121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- **Hashing and strings:** [LC 242](https://leetcode.com/problems/valid-anagram/) · [LC 2269 K-Beauty](https://leetcode.com/problems/find-the-k-beauty-of-a-number/) (asked by IBM) · [LC 1604 Key-card alerts](https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/) (≈ B9) · [LC 3035](https://leetcode.com/problems/maximum-palindromes-after-operations/) (= B15) · [LC 58](https://leetcode.com/problems/length-of-last-word/) · [LC 442 Find All Duplicates](https://leetcode.com/problems/find-all-duplicates-in-an-array/) (reported IBM)
- **Sort, greedy and intervals:** [LC 56](https://leetcode.com/problems/merge-intervals/) · [LC 452](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) · [LC 1465 Cake cuts](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/) (static B17)
- **Binary search:** [LC 2070 Most Beautiful Item](https://leetcode.com/problems/most-beautiful-item-for-each-query/) (= B14 trick) · [LC 875 Koko](https://leetcode.com/problems/koko-eating-bananas/) (binary search on the answer, same idea as Shader Loader)
- **Stack:** [LC 735 Asteroid Collision](https://leetcode.com/problems/asteroid-collision/) · [LC 20](https://leetcode.com/problems/valid-parentheses/) · [LC 739](https://leetcode.com/problems/daily-temperatures/)
- **Graphs:** [LC 547](https://leetcode.com/problems/number-of-provinces/) · [LC 200](https://leetcode.com/problems/number-of-islands/) · [LC 207](https://leetcode.com/problems/course-schedule/) · [HackerRank Clique](https://www.hackerrank.com/challenges/clique/problem) (Turán, asked by IBM Systems)
- **DP:** [LC 1335 Min Difficulty Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/) · [LC 322](https://leetcode.com/problems/coin-change/) · [LC 300](https://leetcode.com/problems/longest-increasing-subsequence/) · [LC 198](https://leetcode.com/problems/house-robber/)
- **Trees (ISDL):** [LC 94 Inorder, iterative](https://leetcode.com/problems/binary-tree-inorder-traversal/) · [LC 102 Level order](https://leetcode.com/problems/binary-tree-level-order-traversal/) · [LC 230](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
- **Heap:** [LC 215](https://leetcode.com/problems/kth-largest-element-in-an-array/) · [LC 347](https://leetcode.com/problems/top-k-frequent-elements/) · [LC 1383](https://leetcode.com/problems/maximum-performance-of-a-team/)
- **Fenwick tree (harder):** [LC 315 Count Smaller After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) (B16 technique)
- **Recent IBM US reports (easy warm-ups):** [LC 334 Increasing Triplet](https://leetcode.com/problems/increasing-triplet-subsequence/) (June 2026) · [LC 48 Rotate Image](https://leetcode.com/problems/rotate-image/)
- **ISDL C/bit basics:** [LC 191](https://leetcode.com/problems/number-of-1-bits/) · [LC 231](https://leetcode.com/problems/power-of-two/) · [HackerRank Small Triangles, Large Triangles](https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem) (asked by IBM Systems, written in C)

## If the OA is today: a 3-hour version
1. **(60 min)** Local judge: B1, B2, B4, B6, B8 (the very-high-likelihood patterns; each should take 10–15 min).
2. **(60 min)** B3, B5, B12, B10.
3. **(30 min)** LC 98 iteratively + LC 67 + the IPv6 question from Part C. **ISDL only.**
4. **(30 min)** Re-read Part D MCQs in the main doc + the exam-day checklist.

---

## Hints (one line each; read only when stuck)
- **B1:** Compare `load[i] * n > 2 * sum` in `long long`; no division.
- **B2:** Keep `best[item]` initialised to a huge value; any untouched entry means −1.
- **B3:** Sort by **end** time; take an interval if its start ≥ the last taken end.
- **B4:** Track the minimum so far; only count strictly bigger later values.
- **B5:** Fewer than n−1 links → −1. Otherwise answer = (connected components − 1).
- **B6:** `unordered_map<string,int>` streak per user: increment on error, reset on success or at 3.
- **B7:** Each command only ever helps one axis, so take it exactly when it reduces the remaining |dx| or |dy|.
- **B8:** Map sid → list of (time, status), sort each list, check the first status and adjacent statuses.
- **B9:** For each IP, its timestamps are already sorted. Use a two-pointer window where `ts[r] − ts[l] < t` and check the size > k.
- **B10:** The shortest window with **at least** k distinct has exactly k. Shrink from the left while the left value is duplicated or there are too many distinct values.
- **B11:** Sort starts and ends separately and sweep. Or sort by start with a min-heap of end times.
- **B12:** Sort prices with prefix sums. For query q, find the split with `lower_bound`; answer = q·cntLeft − sumLeft + sumRight − q·cntRight.
- **B13:** Inserting at an end can only add cost. Insert the midpoint of the **largest gap**, then cost = total − (d² − best split cost).
- **B14:** The prefix maximum of arr2 is non-decreasing, so `upper_bound(x)` gives the first index whose value > x.
- **B15:** Pool all characters: pairs = Σ cnt/2. Fill the shortest words first; each needs len/2 pairs (centres are always available).
- **B16:** Inserting x gives it weight (count of elements ≤ x) + 1, and every element > x gains +1. Two Fenwick trees (count, sum) over values.
- **B17:** Keep a `set` of cut positions and a `multiset` of gaps per direction. Answer = maxGapX × maxGapY.

### Sources
- High-load timestamps and union-find reassignments: [ProgramHelp IBM OA](https://programhelp.net/en/oa/ibm-oa-hackerrank/), [OAVO debrief](https://oavoservice.com/en/articles/ibm-oa-hackerrank-high-load-union-find)
- Min cost items, intervals, water level: [dev.to high-frequency IBM questions](https://dev.to/interviewshow-cs/ibm-oa-high-frequency-questions-sharing-how-to-pass-ibm-oa-efficiently-7po)
- IPs, grid arrival, login counter: [linkjob IBM HackerRank reports](https://www.linkjob.ai/interview-questions/ibm-hackerrank-test/)
- Log groups and exactly-k window: [2026 NG SDE OA](https://dev.to/net_programhelp_e160eef28/ibm-oa-experience-2026-ng-sde-2-coding-questions-full-ac-1h07), [PracHub IBM guide](https://prachub.com/resources/ibm-coding-assessment-guide-2026-questions-timing-and-preparation)
- Price queries: [1point3acres IBM 2025 intern](https://www.1point3acres.com/interview/problems/ibm-minimum-operations-required). Insert-one cost: [Glassdoor IBM review](https://www.glassdoor.it/Colloquio/IBM-Colloquio-E354-RVW80725726.htm), [LeetCode Discuss IBM SD 2023-24](https://leetcode.com/discuss/post/4024498)
- First greater index: [LeetCode Discuss IBM OA](https://leetcode.com/discuss/post/7286758/ibm-oa-questions-by-anonymous_user-snhg/)
- Largest Area, Sorted Sums, increasing triplet: [interviewfox IBM HackerRank 2026](https://interviewfox.ai/interview-questions/ibm-hackerrank-test/)
