# Amazon SDE-1 OA: Practice Sheet (questions only)

**How to use this**
1. Read a question, set a timer (the target time is next to each title), and solve it in `Amazon_OA_practice_starter.cpp`. Each function stub there has the same name as in this sheet.
2. Run the starter. It checks your function against every sample below and prints PASS/FAIL:
   `g++ -std=c++17 -O2 Amazon_OA_practice_starter.cpp -o p && ./p R1` (pass an ID to test one question, or nothing to test all).
3. Only after you've passed the samples, or given it a real try, open `Amazon_OA_solutions.cpp` (same function names) or the approach in the Crash Guide.
4. Stuck for 20+ minutes? There is **one hint per question at the very bottom** of this sheet. Read only the hint for your question.

Use `long long` for anything that can grow. "mod" always means 10⁹+7.

| Tier | Questions | Why |
|---|---|---|
| **S** (do all) | R1 R2 R3 R4 P1 P18 P3 P4 | Asked at Amazon campus OAs Jul–Oct 2026, or in your own files |
| **A** | P2 P5 P6 P7 P8 P9 P10 P11 P12 P13 P14 P15 P16 P17 | 2025–26 Amazon OA questions that keep getting re-asked |

---

# Tier S

## R1. Secure Maximum Deliveries · Medium · 35 min
*Seen: your screenshot (Sep 2026), HackOn Aug 2026, IIT BHU intern Jul 2026*

As a logistics manager at an automobile company, you store parts deliveries in secure warehouses.

You are given an array `deliveryLogs` of size `n`, where `deliveryLogs[i]` is the number of parts delivered in the i-th log, and an **even** integer `k`, the number of warehouses.
- Each warehouse can store deliveries from a **single log only**. Deliveries from different logs can't be mixed in one warehouse, but one log's deliveries **may be split** across several warehouses.
- After storing, exactly **k/2 warehouses with the largest number of deliveries become compromised**.
- The remaining k/2 warehouses are safe, and only the deliveries in them count as secure.

Return the **maximum number of secure deliveries** you can store.

**Function:** `long long secureMaximumDeliveries(vector<int> deliveryLogs, int k)`

**Constraints:** `1 ≤ n ≤ 1000`, `2 ≤ k ≤ 1000` (k is even), `0 ≤ deliveryLogs[i] ≤ 1000`

| # | deliveryLogs | k | Output |
|---|---|---|---|
| 1 | `[3, 5, 9, 6]` | 4 | **9** |
| 2 | `[6]` | 2 | **3** |
| 3 | `[5, 5, 5, 5, 5, 5]` | 4 | **10** |
| 4 | `[10]` | 4 | **4** |
| 5 | `[0, 0, 7]` | 2 | **3** |
| 6 | `[1, 1, 1, 1]` | 4 | **2** |

**Example 1 explained:** storing each log in its own warehouse gives `[3,5,9,6]`. The two largest (9 and 6) are compromised, so only 3 + 5 = 8 is secure. Better: put all 5 of log 2 in warehouse 1, 4 of log 3 in warehouse 2, the other 5 of log 3 in warehouse 3, and all 6 of log 4 in warehouse 4. That gives `[5,4,5,6]`; 6 and 5 are compromised, so 4 + 5 = **9** is secure.
**Example 2 explained:** split 6 into 3 + 3. One warehouse is compromised (the two are equal), and **3** stay secure.

---

## R2. Maximum Continuous Uptime · Easy–Medium · 20 min
*Seen: Amazon SDE-intern OA 2026 (your PDF), LNMIIT Oct 2026*

A server's uptime is logged as a binary string `log`: `'1'` means up and `'0'` means down. You must choose **exactly one** substring of length `k` and change every `'0'` inside it to `'1'`.

Return the **maximum number of consecutive `'1'`s** possible after this operation.

**Function:** `int maxConsecutiveOnesAfterWindow(string log, int k)`

**Constraints:** `1 ≤ |log| ≤ 2·10⁵`, `1 ≤ k ≤ |log|`

| # | log | k | Output |
|---|---|---|---|
| 1 | `"11001"` | 2 | **5** |
| 2 | `"0110100"` | 2 | **4** |
| 3 | `"000"` | 3 | **3** |
| 4 | `"10101"` | 1 | **3** |
| 5 | `"1111"` | 2 | **4** |

**Example 1 explained:** choose `11[00]1` → `11111`, which gives **5**.

---

## R3. Even-Run Arrangements · Medium–Hard · 35 min
*Seen: Amazon intern OA, IIITD, 4 Jul 2026*

You are given an array `A` of `n` **distinct** positive integers. Count the number of ways to **rearrange** the elements of `A` so that every contiguous subarray consisting entirely of **even** numbers has length **at most 2**. (In other words, no three even numbers stand next to each other.)

The answer can be large, so return it **mod 10⁹+7**.

**Function:** `long long countArrangementsEvenRunAtMost2(vector<long long> A)`

**Constraints:** `1 ≤ n ≤ 10⁵`, `1 ≤ A[i] ≤ 10⁹`, all `A[i]` distinct

| # | A | Output |
|---|---|---|
| 1 | `[2, 4, 6, 1]` | **12** |
| 2 | `[2, 4, 6]` | **0** |
| 3 | `[1, 3, 5]` | **6** |
| 4 | `[2, 4, 1, 3]` | **24** |
| 5 | `[2, 4, 6, 8, 1, 3]` | **288** |
| 6 | `[8]` | **1** |

**Example 2 explained:** every arrangement puts all three evens next to each other, so the answer is **0**.

---

## R4. Palindromic Rearrangeable Subsequences · Medium · 25 min
*Seen: Amazon intern OA, IIITD, 4 Jul 2026*

You are given a string `s` of length `n` made of lowercase English letters. Count the number of **subsequences** of `s` whose letters can be **rearranged to form a palindrome**. The empty subsequence counts as palindromic. Two subsequences are different if they use different sets of **positions**, even if they spell the same string.

Return the count **mod 10⁹+7**.

**Function:** `long long countPalindromicRearrangeableSubseq(string s)`

**Constraints:** `1 ≤ n ≤ 10⁵`

| # | s | Output |
|---|---|---|
| 1 | `"aa"` | **4** |
| 2 | `"ab"` | **3** |
| 3 | `"aab"` | **6** |
| 4 | `"abc"` | **4** |
| 5 | `"aaaa"` | **16** |
| 6 | `"abab"` | **12** |

**Example 2 explained:** the subsequences are `""`, `"a"`, `"b"` and `"ab"`. `"ab"` can't be rearranged into a palindrome, so the answer is **3**.

---

## P1. Minimum Truck Capacity · Medium · 20 min
*Seen: NIT Bhopal on-campus, Oct 2026*

Packages on a conveyor must be shipped **in the given order** within `days` days. Each day the truck is loaded with consecutive packages, as long as the total weight doesn't exceed its capacity.

Return the **minimum truck capacity** that ships every package within `days` days.

**Function:** `long long shipWithinDays(vector<int> weights, int days)`

**Constraints:** `1 ≤ days ≤ n ≤ 5·10⁴`, `1 ≤ weights[i] ≤ 500`

| # | weights | days | Output |
|---|---|---|---|
| 1 | `[1,2,3,4,5,6,7,8,9,10]` | 5 | **15** |
| 2 | `[3,2,2,4,1,4]` | 3 | **6** |
| 3 | `[1,2,3,1,1]` | 4 | **3** |
| 4 | `[7]` | 1 | **7** |

**Example 1 explained:** with capacity 15 the days are [1,2,3,4,5], [6,7], [8], [9], [10]. Capacity 14 needs 6 days.

---

## P18. Unique Pair Sums · Easy · 15 min
*Seen: title "Two Sum", IIT BHU on-campus, Oct 2026 (the exact twist isn't public; this is Amazon's most common one)*

Given an integer array `nums` and a `target`, return the number of **unique value pairs** `(a, b)` with `a ≤ b` such that `a + b = target`. The two values must come from different indices. A pair counts once, however many times it occurs.

**Function:** `long long countUniquePairs(vector<int> nums, long long target)`

**Constraints:** `1 ≤ n ≤ 10⁵`, `−10⁹ ≤ nums[i] ≤ 10⁹`

| # | nums | target | Output |
|---|---|---|---|
| 1 | `[1, 1, 2, 45, 46, 46]` | 47 | **2** |
| 2 | `[1, 5, 1, 5]` | 6 | **1** |
| 3 | `[6, 6, 3, 9, 3, 5, 1]` | 12 | **2** |
| 4 | `[4]` | 8 | **0** |

**Example 1 explained:** the pairs are (1, 46) and (2, 45).
**Example 4 explained:** (4, 4) would need two different indices, so the answer is **0**.

---

## P3. Server Security Groups · Medium · 25 min
*Seen: Amazon 2026 summer SDE-intern OA; "Minimum Security Groups", Feb 2026*

Each server has a security level, given in `levels`. Divide **all** servers into groups so that:
- every server in a group has the **same** security level, and
- for any two groups, the sizes **differ by at most 1**.

Return the **minimum number of groups**.

**Function:** `long long minSecurityGroups(vector<int> levels)`

**Constraints:** `1 ≤ n ≤ 10⁵`, `1 ≤ levels[i] ≤ 10⁹`

| # | levels | Output |
|---|---|---|
| 1 | `[3, 2, 3, 2, 3]` | **2** |
| 2 | `[10, 10, 10, 3, 1, 1]` | **4** |
| 3 | `[1, 1, 1, 1, 1, 2, 2, 3]` | **5** |
| 4 | `[7, 7, 7, 7]` | **1** |

**Example 1 explained:** the groups {3,3,3} (size 3) and {2,2} (size 2) differ by 1, so the answer is **2**.
**Example 2 explained:** {10,10}, {10}, {3}, {1,1}, so the answer is **4**.

---

## P4. Maximize Rental Revenue · Medium · 30 min
*Seen: "Maximize Rental Revenue", Feb 2026 (twice); "server allocation cost", 2026*

A cloud provider has `n` virtual-machine types; `stock[i]` is the number of idle instances of type `i`. Then `m` customers arrive one at a time. Each customer rents **one** instance of the type that currently has the **most** idle instances, and pays a price **equal to that type's idle count just before renting**. That count then drops by 1. If every type has 0 idle instances, the remaining customers pay nothing.

Return the total revenue **mod 10⁹+7**.

**Function:** `long long maxRentalRevenueFast(vector<long long> stock, long long m)`

**Constraints:** `1 ≤ n ≤ 10⁵`, `1 ≤ stock[i] ≤ 10⁹`, `1 ≤ m ≤ 10⁹` (**m is too large to simulate customer by customer**)

| # | stock | m | Output |
|---|---|---|---|
| 1 | `[2, 5]` | 4 | **14** |
| 2 | `[3, 5]` | 6 | **19** |
| 3 | `[1, 1, 1]` | 5 | **3** |
| 4 | `[1000000000]` | 1000000000 | **21** |

**Example 1 explained:** the customers pay 5, 4, 3, then 2 (both types have 2 left; either one): 5 + 4 + 3 + 2 = **14**.

---

# Tier A

## P2. Sort Bug Reports · Easy · 10 min
*Seen: Feb 2026, May 2026*

QA collects bug codes from automated test logs; a code may repeat. Sort the **whole array** (repeats included) so that:
- codes that occur **fewer** times come first;
- codes with the same frequency are in **ascending** code order.

**Function:** `vector<int> sortBugReports(vector<int> bugs)`

**Constraints:** `1 ≤ n ≤ 2·10⁵`, `1 ≤ bugs[i] ≤ 10⁹`

| # | bugs | Output |
|---|---|---|
| 1 | `[8, 4, 6, 5, 4, 8]` | **[5, 6, 4, 4, 8, 8]** |
| 2 | `[3, 1, 2, 2, 3, 3]` | **[1, 2, 2, 3, 3, 3]** |
| 3 | `[7]` | **[7]** |
| 4 | `[9, 9, 1, 1, 5]` | **[5, 1, 1, 9, 9]** |

---

## P5. Minimum Health to Beat the Game · Easy · 10 min
*Seen: Amazon SDE-1 OA, Jan 2025; 2026 CoderPad OA*

A game has `n` levels played in order; level `i` costs `damage[i]` health. You may use **armor once**, on any one level, to block up to `armor` damage on that level. Your health must stay **greater than 0** at all times.

Return the **minimum starting health** needed to beat the game.

**Function:** `long long minimumHealth(vector<int> damage, int armor)`

**Constraints:** `1 ≤ n ≤ 10⁵`, `0 ≤ damage[i] ≤ 10⁵`, `0 ≤ armor ≤ 10⁵`

| # | damage | armor | Output |
|---|---|---|---|
| 1 | `[2, 7, 4, 3]` | 4 | **13** |
| 2 | `[2, 5, 3, 4]` | 7 | **10** |
| 3 | `[3, 3, 3]` | 0 | **10** |

---

## P6. Group the Binary Array · Easy–Medium · 15 min
*Seen: 2026 CoderPad OA ("minMoves")*

An array contains only 0s and 1s. In one move you swap two **adjacent** elements. Return the **minimum number of moves** to make all 0s contiguous and all 1s contiguous. Either order is allowed: `000111` or `111000`.

**Function:** `long long minAdjacentSwapsGroupBinary(vector<int> arr)`

**Constraints:** `1 ≤ n ≤ 10⁵` (the answer can exceed 2³¹)

| # | arr | Output |
|---|---|---|
| 1 | `[0, 1, 0, 1]` | **1** |
| 2 | `[1, 1, 1, 1, 0, 0, 0, 0]` | **0** |
| 3 | `[1, 0, 1, 0, 1]` | **3** |
| 4 | `[0, 0, 1, 1, 0]` | **2** |

---

## P7. Minimum Merge Conflicts · Hard · 40 min
*Seen: Amazon OA, Jun 2026*

Two source-control branches are lowercase strings `primary` and `secondary`; each character is a commit priority (`'a'` is the highest). Merge them into one string that **keeps the relative order** of each branch's commits.

A **conflict** is any pair of positions `i < j` in the merged string with `merged[i] > merged[j]`. Return the **minimum number of conflicts** over all valid merges.

**Function:** `long long minMergeConflicts(string primary, string secondary)`

**Constraints:** `0 ≤ |primary|, |secondary| ≤ 3000`

| # | primary | secondary | Output |
|---|---|---|---|
| 1 | `"zc"` | `"d"` | **2** |
| 2 | `"abc"` | `""` | **0** |
| 3 | `"ba"` | `"ab"` | **1** |
| 4 | `"ca"` | `"b"` | **2** |

**Example 1 explained:** `zcd` has 2 conflicts (z>c, z>d), `zdc` has 3, and `dzc` has 2. The minimum is **2**.

---

## P8. Unique XOR Triplets · Medium · 25 min
*Seen: Amazon OA, Jul 2026*

Given an array `nums`, consider every triplet of indices `i ≤ j ≤ k` (indices **may be equal**). Return the number of **distinct values** of `nums[i] XOR nums[j] XOR nums[k]`.

**Function:** `int uniqueXorTriplets(vector<int> nums)`

**Constraints:** `1 ≤ n ≤ 1500`, `1 ≤ nums[i] ≤ 1500`

| # | nums | Output |
|---|---|---|
| 1 | `[1, 2]` | **2** |
| 2 | `[3, 1, 2]` | **4** |
| 3 | `[6, 7, 8, 9]` | **4** |
| 4 | `[5]` | **1** |

**Example 2 explained:** the reachable values are {0, 1, 2, 3}.

---

## P9. Throttling Gateway · Easy–Medium · 20 min
*Seen: "Amazon Throttling Mechanism", Feb 2026 (a classic)*

`requestTime` holds request arrival times in seconds, **sorted ascending**. The gateway drops a request if, counting the request itself:
- more than **3** requests arrive in the same second, or
- more than **20** requests arrive in any 10-second window, or
- more than **60** requests arrive in any 60-second window.

Dropped requests **still count** towards the limits. Return the **number of dropped requests**.

(Equivalently: request `i` is dropped if `requestTime[i−3] == requestTime[i]`, or `requestTime[i] − requestTime[i−20] < 10`, or `requestTime[i] − requestTime[i−60] < 60`.)

**Function:** `int droppedRequests(vector<int> requestTime)`

**Constraints:** `1 ≤ n ≤ 10⁶`, `1 ≤ requestTime[i] ≤ 10⁹`

| # | requestTime | Output |
|---|---|---|
| 1 | `[1, 1, 1, 1, 2]` | **1** |
| 2 | `[1,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,11,11,11,11]` | **7** |
| 3 | `[1, 2, 3, 4, 5]` | **0** |

---

## P10. Number of Retailers · Medium–Hard · 35 min
*Seen: "Number of Retailers", Jan 2026*

Retailer `i` is at `(x_i, y_i)` and can deliver to any point `(a, b)` with `0 ≤ a ≤ x_i` and `0 ≤ b ≤ y_i`. For each query point, return how many retailers can deliver to it.

**Function:** `vector<int> countRetailers(vector<pair<int,int>> retailers, vector<pair<int,int>> requests)`

**Constraints:** `1 ≤ n, q ≤ 10⁵`, `0 ≤ coordinates ≤ 10⁹` (**O(n·q) is too slow**)

| # | retailers | requests | Output |
|---|---|---|---|
| 1 | `[(1,2), (2,3), (2,5)]` | `[(2,1), (1,4)]` | **[2, 1]** |
| 2 | `[(1,1), (2,2), (3,3)]` | `[(1,3), (1,1), (4,4)]` | **[1, 3, 0]** |

---

## P11. Max and Min Median · Easy–Medium · 15 min
*Seen: Amazon SDE-1 OA (recent report)*

Given `values` and an integer `k`, consider every **subsequence** of length exactly `k`. The median of a subsequence is the element at index `(k−1)/2` (0-based, integer division) after sorting it. Return `{maximum possible median, minimum possible median}`.

**Function:** `pair<long long,long long> maxMinMedian(vector<long long> values, int k)`

**Constraints:** `1 ≤ k ≤ n ≤ 10⁵`, `1 ≤ values[i] ≤ 10⁹`

| # | values | k | Output |
|---|---|---|---|
| 1 | `[1, 2, 3]` | 2 | **{2, 1}** |
| 2 | `[1, 2, 3, 4, 5]` | 3 | **{4, 2}** |
| 3 | `[5, 5, 5]` | 1 | **{5, 5}** |
| 4 | `[4, 1, 7, 3]` | 4 | **{3, 3}** |

**Example 1 explained:** the subsequences are [1,2], [1,3] and [2,3]; their medians are 1, 1 and 2.

---

## P12. Lexicographically Largest MEX Array · Hard · 40 min
*Seen: Amazon SDE-1 OA (recent report)*

You have an array `arr` of non-negative integers and an empty array `res`. Repeat until `arr` is empty: choose any `x ≥ 1`, remove the **first `x` elements** of `arr`, and append their **MEX** (the smallest non-negative integer **not** among them) to `res`.

Return the **lexicographically largest** `res` possible. Compare arrays element by element; if one array is a prefix of the other, the longer one is larger.

**Function:** `vector<int> lexMaxMexArray(vector<int> arr)`

**Constraints:** `1 ≤ n ≤ 10⁵`, `0 ≤ arr[i] ≤ 10⁹`

| # | arr | Output |
|---|---|---|
| 1 | `[0, 1, 2, 0]` | **[3, 1]** |
| 2 | `[2, 2, 3]` | **[0, 0, 0]** |
| 3 | `[0, 1, 1, 0]` | **[2, 2]** |
| 4 | `[1, 0, 2, 1, 0]` | **[3, 2]** |

**Example 3 explained:** take `[0,1]` (MEX 2), then `[1,0]` (MEX 2). Taking all four at once gives only `[2]`, which is smaller.

---

## P13. Channel Quality · Medium · 25 min
*Seen: a classic Amazon OA from 2024–25, still re-asked*

Send `n` data packets with sizes `packets[i]` through `m` channels. Every packet goes to exactly one channel, and **every channel gets at least one packet**. A channel's quality is the **median** of its packet sizes; for an even count, it's the average of the two middle values. Return the **maximum total quality**, rounded **up** to an integer.

**Function:** `long long maxChannelQuality(vector<long long> packets, int m)`

**Constraints:** `1 ≤ m ≤ n ≤ 5·10⁵`, `1 ≤ packets[i] ≤ 10⁹`

| # | packets | m | Output |
|---|---|---|---|
| 1 | `[1, 2, 3, 4, 5]` | 2 | **8** |
| 2 | `[1, 2, 3, 2, 1, 5]` | 3 | **10** |
| 3 | `[5, 5, 5]` | 3 | **15** |
| 4 | `[2, 9, 4]` | 1 | **4** |

**Example 1 explained:** channel A = {5} (median 5) and channel B = {1,2,3,4} (median 2.5). The total is 7.5, rounded up to **8**.

---

## P14. Decreasing Ratings · Easy · 10 min
*Seen: a classic Amazon OA*

Count the contiguous subarrays of `ratings` in which **each element is exactly 1 less than the previous one**. Every single element counts as such a subarray.

**Function:** `long long countDecreasingRatings(vector<int> ratings)`

**Constraints:** `1 ≤ n ≤ 10⁵`

| # | ratings | Output |
|---|---|---|
| 1 | `[4, 3, 5, 4, 3]` | **9** |
| 2 | `[2, 1, 3]` | **4** |
| 3 | `[4, 2, 3, 1]` | **4** |
| 4 | `[5]` | **1** |

**Example 1 explained:** the five singles, plus [4,3], [5,4], [4,3] and [5,4,3], make 9.

---

## P15. Password Similarity · Easy · 15 min
*Seen: a classic Amazon OA*

You may **cyclically increment** any chosen characters of `newPassword` at most once each (`a→b`, …, `z→a`). The passwords are "similar" if, after this, `oldPassword` is a **subsequence** of `newPassword`. Return whether they're similar.

**Function:** `bool passwordSimilar(string newPassword, string oldPassword)`

**Constraints:** `1 ≤ lengths ≤ 2·10⁵`

| # | newPassword | oldPassword | Output |
|---|---|---|---|
| 1 | `"aaccbbee"` | `"bdbf"` | **YES** |
| 2 | `"abdbc"` | `"ace"` | **YES** |
| 3 | `"aaa"` | `"bbbb"` | **NO** |
| 4 | `"zza"` | `"ab"` | **YES** |
| 5 | `"baacbab"` | `"abcd"` | **NO** |

---

## P16. Minimum Errors ('!' String) · Medium–Hard · 35 min
*Seen: getMinErrors (classic); SDE-II OA Sep 2025 (the x = y = 1 version)*

`s` contains `'0'`, `'1'` and `'!'`. Replace **every** `'!'` with `'0'` or `'1'`. The error count is `x · (number of "01" subsequences) + y · (number of "10" subsequences)`; a subsequence here is any pair of positions i < j. Return the **minimum** error count **mod 10⁹+7**.

**Function:** `long long getMinErrors(string s, long long x, long long y)`

**Constraints:** `1 ≤ |s| ≤ 10⁵`, `0 ≤ x, y ≤ 10⁵`

| # | s | x | y | Output |
|---|---|---|---|---|
| 1 | `"101!1"` | 2 | 3 | **9** |
| 2 | `"!!!!!!!"` | 23 | 47 | **0** |
| 3 | `"0!1!"` | 1 | 1 | **3** |
| 4 | `"!0!"` | 5 | 1 | **0** |

**Example 1 explained:** `10101` has 3 "01" and 3 "10", so 2·3 + 3·3 = 15. `10111` has 3 "01" and 1 "10", so 2·3 + 3·1 = **9**.

---

## P17. Max Money from k Consecutive Bags · Easy · 10 min
*Seen: 2026 CoderPad OA (calculateMaximumConsecutiveSum)*

Return the largest sum of any `k` **consecutive** bags, **mod 10⁹+7**. Take the mod only on the final answer.

**Function:** `long long maxConsecutiveSum(vector<long long> bags, int k)`

**Constraints:** `1 ≤ k ≤ n ≤ 10⁵`, `1 ≤ bags[i] ≤ 10⁹`

| # | bags | k | Output |
|---|---|---|---|
| 1 | `[1, 2, 3, 4, 5]` | 2 | **9** |
| 2 | `[7, 1, 9, 2, 8]` | 3 | **19** |
| 3 | `[1000000000, 1000000000]` | 2 | **999999993** |

---
---
---

# Hints (spoilers: one line each, read only the one you need)

<details><summary>R1</summary>Fix one number: the size of the <b>smallest compromised</b> warehouse. Given that number, what's the best way to fill the secure ones? (Values are ≤ 1000, so you can try every possibility.)</details>

<details><summary>R2</summary>For each window, the answer is (1s just before it) + k + (1s just after it). Precompute both sides.</details>

<details><summary>R3</summary>The elements are distinct, so first count the even/odd <b>patterns</b>, then multiply by E!·O!. The odd numbers create gaps; each gap can hold 0, 1 or 2 evens.</details>

<details><summary>R4</summary>For one letter with frequency f, how many ways are there to pick an even number of its copies? An odd number? Compare the two.</details>

<details><summary>P1</summary>If capacity C works, every capacity larger than C works too.</details>

<details><summary>P18</summary>Use a frequency map; handle a == b separately.</details>

<details><summary>P3</summary>The group size (or size + 1) must be ≤ the smallest frequency. Try sizes from large to small.</details>

<details><summary>P4</summary>Find the price level T where everything above T gets sold. Units above T form arithmetic series.</details>

<details><summary>P2</summary>Count frequencies, then sort with a comparator.</details>

<details><summary>P5</summary>Where is the armor most useful?</details>

<details><summary>P6</summary>Count, for each 0, how many 1s are before it. Then do the same the other way round.</details>

<details><summary>P7</summary>Inversions inside each string are fixed. Only the order between the two strings matters, so DP over (i, j).</details>

<details><summary>P8</summary>XOR values here are < 2048. Build the set of pair-XORs first.</details>

<details><summary>P9</summary>Compare each request with the one 3, 20 and 60 positions earlier.</details>

<details><summary>P10</summary>Process retailers and queries together, sorted by x descending; count y values with a Fenwick tree.</details>

<details><summary>P11</summary>Sort. Which index can the median occupy at best, and at worst?</details>

<details><summary>P12</summary>The best first value is the MEX of the <b>whole</b> array. Take the <b>shortest</b> prefix that achieves it.</details>

<details><summary>P13</summary>A channel with one packet has median = that packet.</details>

<details><summary>P14</summary>A decreasing run of length L contains L(L+1)/2 such subarrays.</details>

<details><summary>P15</summary>Greedy two pointers.</details>

<details><summary>P16</summary>In an optimal answer the '!' values look like 000…111 or 111…000. Sweep and update the cost incrementally.</details>

<details><summary>P17</summary>Sliding window; never compare values after taking mod.</details>
