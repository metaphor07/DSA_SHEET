# Amazon SDE-1 On-Campus OA: Crash Guide (IIT Delhi, 4 Nov 2026)

Code for every problem below is in `Amazon_OA_solutions.cpp` (C++17). Every non-trivial function was stress-tested against a brute force (`Amazon_OA_stress.cpp`, 13 suites, all passing) and timed at the worst-case constraints (all run in under 0.02 s).

---

## 1. Your test, from the IIT Delhi JNF

| Item | Detail |
|---|---|
| Role | Software Development Engineer-1, 2027 graduates (Bengaluru, Hyderabad, Gurugram, Chennai, Pune), ~10 hires |
| Screening | Resume shortlist **before** the test |
| Online test | **120 minutes, technical only.** Aptitude/psychometric: No. Syllabus: "NA" |
| After the test | Technical round(s) + personal interview, no HR round |
| Pay | CTC ₹48.38 L (base ₹20.3 L), min CGPA 6.5 |

## 2. What the 120 minutes will most likely contain

Two formats are live this season. **Prepare for format A, but be ready for B.**

| | Format A: the new 2026 campus pattern (most likely) | Format B: the classic pattern |
|---|---|---|
| DSA | **1 question, ~40 min** | 2 questions, ~70 min |
| Second section | **AI-assisted repo debugging, ~60 min:** a real multi-file project (MERN, Spring Boot, Python…), failing unit tests, a built-in AI assistant | Work simulation / 7 short debug snippets |
| Last section | Work style / situational judgement (Leadership Principles) | Work style survey |

**Evidence for A at campuses this season:**
- **Your screenshots:** Section 1 had one DSA question (`secureMaximumDeliveries`, C++20 editor); Section 2 was the MovieDB MERN watchlist repo with a ~60-minute timer, an "Ask the AI Assistant" panel and 6 unit tests.
- **The SDE-intern 2026 PDF:** 1 coding question, 1 repo-debugging task (7+ files, 6 tests), situational judgement.
- **codinzhub on-campus tags, Oct 2026:** IIT Patna (7 Oct) "1 DSA, 1 AI-debugging"; IIT BHU (15 Oct) "1 coding, 1 debug, behavioural"; LNMIIT (12 Oct, off-campus) "1 DSA + 1 bug-fixing".
- **Evidence for B:** the IIITD intern OA (4 Jul 2026) still had 2 DSA questions.

> **What this means for you:** with only **one** DSA question, a partial solution is not good enough. Aim to pass *every* hidden test, and budget time for edge cases. The debugging section is ~half the test; you chose to focus on DSA, so Appendix A gives you the 15-minute version of it.

---

## 3. Reconstructed questions from your files

### R1. Secure Maximum Deliveries (your gallery; also HackOn Aug 2026, IIT BHU intern Jul 2026, Feb 2026 batch) ★★★
You have `deliveryLogs[n]` and an **even** `k` = number of warehouses.
- A warehouse may hold deliveries from **one log only**; a log may be **split** across warehouses.
- After storing, the **k/2 warehouses with the most deliveries are compromised**; only the other k/2 count as secure.
- Return the **maximum number of secure deliveries**.

Constraints: `1 ≤ n ≤ 1000`, `2 ≤ k ≤ 1000` (even), `0 ≤ deliveryLogs[i] ≤ 1000`.

| Input | Output | Why |
|---|---|---|
| `[3,5,9,6]`, k=4 | **9** | warehouses `[5,4,5,6]` (log 1 is **not stored at all**); 6 and 5 are compromised; 4+5=9 |
| `[6]`, k=2 | **3** | split 3 + 3 |
| `[5,5,5,5,5,5]`, k=4 | **10** | four warehouses of 5 |

**Hidden rule in example 1: you don't have to store everything.** Many people miss this.

**Approach (O(maxA · n)):** fix `x` = the size of the *smallest compromised* warehouse.
- Compromised warehouses should hold **exactly x** (more is wasted stock). Secure ones hold **≤ x**.
- Each log `a` yields `a/x` full pieces of size x plus one remainder `a%x`.
- Need `F = Σ a/x ≥ h` (h = k/2). Use h full pieces as compromised, the next `min(F−h, h)` full pieces as secure, and fill the remaining secure slots with the **largest remainders**.
- Try every `x` from 1 to max(a). Values ≤ 1000, so this is ~10⁶ operations.

### R2. Maximum Consecutive 1s / "Maximum Continuous Uptime" (SDE-intern 2026 PDF; LNMIIT Oct 2026) ★★★
Binary string `log` and integer `k`. Choose **exactly one** substring of length `k` and turn its 0s into 1s. Return the maximum number of consecutive 1s.
- `"11001"`, k=2 → **5**; `"0110100"`, k=2 → **4** (flip positions 3–4)

**Approach O(n):** `left[i]` = 1s ending at i, `right[i]` = 1s starting at i. For window `[i, i+k−1]`: `left[i−1] + k + right[i+k]`. Take the max. Guard `k ≥ n` (answer n).

### R3. IIITD intern (4 Jul 2026) Q1: arrangements with no 3 consecutive evens ★★
Array of **distinct** positive integers. Count rearrangements where every contiguous all-even block has length ≤ 2. Mod 10⁹+7.
- `[2,4,6,1]` → **12**; `[2,4,6]` → **0**

**Approach:** elements are distinct, so answer = (number of parity patterns) × E! × O!.
- O odd numbers create **O+1 gaps**; each gap holds 0, 1 or 2 evens; total E.
- Patterns = coefficient of tᴱ in (1+t+t²)^(O+1) = Σⱼ (−1)ʲ · C(O+1, j) · C(E−3j+O, O) (inclusion–exclusion). O(n) with factorials + inverse factorials.

### R4. IIITD intern Q2: subsequences that can be rearranged into a palindrome ★★
String `s`; count subsequences (by index set, **empty included**) where at most one letter has odd count.
- `"aa"` → 4, `"ab"` → 3, `"aab"` → 6

**Approach:** for a letter with frequency f > 0, "pick an even number" and "pick an odd number" both have **2^(f−1)** ways. So:
**answer = 2^(n−d) · (d+1)**, where d = number of distinct letters. O(n).
> If the statement says *distinct* subsequences (strings), this formula doesn't apply; re-read it.

### R5. Repo task 1: MovieDB (MERN) user watchlist (your gallery) and R6. Return/Risk evaluation system (intern PDF)
These are the debugging section. What the bugs were, and the one mistake that cost a test: **Appendix A**.

---

## 4. What recent Amazon OAs asked (2023 → Oct 2026)

| Source | DSA questions |
|---|---|
| **Your gallery** (Sep 2026) | Secure Maximum Deliveries + MovieDB watchlist repo |
| **SDE-intern 2026 PDF** | Max consecutive 1s after flipping a k-window + Return/Risk repo + SJT |
| **IIITD intern, 4 Jul 2026** | Even-run arrangements (combinatorics) + palindromic subsequences (counting) |
| **On-campus, Oct 2026** (codinzhub titles; statements paywalled) | IIT BHU: "Two Sum"; IIT Patna: "Maximize Zero-Sum Factor"; NIT Bhopal: **Min capacity to ship packages in D days** (LC 1011); LNMIIT: **Maximum continuous uptime** (= R2) |
| **Sep 2026** (codinzhub) | IIT Roorkee, NIT Jamshedpur, BITS Pilani OAs; "Minimum Cost for Amazon Fulfillment Stations" |
| **HackOn, Aug 2026** | Secure Maximum Deliveries; Find Minimum Sum |
| **Jun–Jul 2026** | Number of Unique XOR Triplets; Minimum Merge Conflicts; Maximum Consecutive Sum (ISM Dhanbad) |
| **Feb 2026 batch** | Sort Bug Report Frequencies; Minimum Security Groups; Throttling Mechanism; Maximize Rental Revenue; Can All Packages Be Delivered; Find Minimum Sum; Secure Maximum Deliveries; Number of Retailers |
| **2026 summer intern** | Server security-level grouping (= LC 2910); server allocation cost (heap) |
| **2026 CoderPad OA** | Min adjacent swaps to group a binary array; max sum of k consecutive bags; Minimum Health to Beat Game; LC 3 |
| **SDE-1, recent (TowardsAI write-up)** | Min & max median of a size-k subsequence; lexicographically maximum array using MEX |
| **SDE-II, Sep 2025** | Lexicographically smallest signed permutation with given sum; '!'-string minimising "01"+"10" counts |

### The pattern: what Amazon is testing
1. **Story-wrapped greedy + "fix the answer and check".** Warehouses, servers, parcels, VMs. The core is almost always: sort, then either **binary search on the answer** or **enumerate a threshold** (R1, ship-in-D-days, rental revenue, security groups, channel medians).
2. **Counting mod 10⁹+7** with nCr / powers of 2 (both IIITD questions). Know factorial + inverse-factorial cold.
3. **Prefix/suffix arrays and sliding windows** (R2, k-bags, decreasing ratings).
4. **Heap simulation that needs a closed form** when m is huge (rental revenue).
5. **String parity / subsequence greedy** (palindromes, password similarity, '!' strings).
6. Occasionally one **DP** (merge conflicts) or **Fenwick tree** (retailers). Trees, linked lists and graphs are **rare in the OA** (they show up in interviews).
7. **2026 trend:** more "observe the trick" problems written to defeat LLMs, and samples that hide a rule (R1's "you may leave a log unstored").

---

## 5. Predicted question bank

**Why these:** Amazon recycles OA questions across campuses within a season, and re-skins older ones. Tier S has been seen at campuses in the last 4 months; Tier A are 2025–26 titles that keep coming back.

### Tier S: highest probability (do all of these)
| # | Problem | Pattern | In .cpp |
|---|---|---|---|
| R1 | Secure Maximum Deliveries | enumerate threshold + greedy | `secureMaximumDeliveries` |
| R2 | Max continuous uptime (flip one k-window) | prefix/suffix runs | `maxConsecutiveOnesAfterWindow` |
| R3 | No 3 consecutive evens: count arrangements | combinatorics, inclusion–exclusion | `countArrangementsEvenRunAtMost2` |
| R4 | Palindrome-rearrangeable subsequences | counting, 2^(n−d)(d+1) | `countPalindromicRearrangeableSubseq` |
| P1 | Ship packages within D days (LC 1011) | binary search on answer | `shipWithinDays` |
| P18 | Two Sum family: count **unique** pairs with sum = target | hashing, duplicates | `countUniquePairs` |
| P3 | Security-level grouping, sizes g or g+1 (LC 2910) | try g from min-freq down | `minSecurityGroups` |
| P4 | Maximize rental revenue / server allocation cost (LC 1648) | heap → threshold binary search | `maxRentalRevenueFast` |

### Tier A: likely re-skins
| # | Problem | Key idea | In .cpp |
|---|---|---|---|
| P2 | Sort bug reports by frequency, then code | custom comparator (check asc/desc!) | `sortBugReports` |
| P5 | Minimum health to beat game (LC 2214) | sum − min(max, armor) + 1 | `minimumHealth` |
| P6 | Min adjacent swaps to group 0s/1s | count crossings both ways, `long long` | `minAdjacentSwapsGroupBinary` |
| P7 | Minimum merge conflicts (merge 2 strings, min inversions) | fixed internal inversions + O(nm) DP | `minMergeConflicts` |
| P8 | Unique XOR triplets (LC 3514) | pair-XOR set (< 2048) then XOR again | `uniqueXorTriplets` |
| P9 | Throttling gateway (3/1 s, 20/10 s, 60/60 s) | compare with t[i−3], t[i−20], t[i−60] | `droppedRequests` |
| P10 | Number of retailers covering a point (LC 2250-like) | offline sweep + Fenwick | `countRetailers` |
| P11 | Max & min median of a size-k subsequence | sort; `v[n−k+m]`, `v[m]` | `maxMinMedian` |
| P12 | Lexicographically max array via MEX | suffix MEX + shortest prefix | `lexMaxMexArray` |
| P13 | Packets → channels, max sum of medians | top m−1 alone, rest share; ceil | `maxChannelQuality` |
| P14 | Count decreasing-ratings subarrays | run length L adds L(L+1)/2 | `countDecreasingRatings` |
| P15 | Password similarity (cyclic +1 once) | two pointers | `passwordSimilar` |
| P16 | getMinErrors ('!' → 0/1, min x·#01 + y·#10) | monotone fill, O(n) sweep | `getMinErrors` |
| P17 | Max sum of k consecutive bags | sliding window, mod only at the end | `maxConsecutiveSum` |

**Titles seen in 2026 whose statements aren't public** (don't burn time guessing): *Find Minimum Sum (non-decreasing servers)*, *Maximize Zero-Sum Factor*, *Can All Packages Be Delivered*, *Top Bundles*, *Minimum Cost for Amazon Fulfillment Stations*. If one of these appears, it will almost surely fall into pattern 1 or 2 above.

### Tier B: pattern drills on LeetCode (only if time remains, timed at 30–40 min each)
- **Binary search on answer:** 875, 410, 2064
- **Window / runs:** 1004, 424, 2024
- **Contribution counting (high on LeetCode's Amazon tag):** 907, 2104, 828, 2262, 2281
- **Greedy + heap:** 1167, 621, 767
- **String trick:** 2272 (substring with largest variance, at the top of LeetCode's Amazon tag)

---

## 6. Your next ~20 hours (OA ≈ 8–9 pm tonight)

| Block | Do this |
|---|---|
| **Now → 2:30 am** | Read sections 2–3. Re-solve **R1 and R2 from memory** (20 min each, then compare with the .cpp). Then **sleep**. |
| **2:30 → 8:30** | Sleep (6 h). With one question deciding the section, a clear head is worth more than 3 extra problems. |
| **9:00 → 11:30** | Tier S: R3 and R4 (memorise the nCr template), P1, P18, P3, P4. Read the approach → close the file → code it → run the samples. |
| 11:30 → 12:00 | Break |
| **12:00 → 14:30** | Tier A, harder ones first: P12 (MEX), P16 ('!' string), P11, P13, P7. Read all; code P12 and P16 yourself. |
| 14:30 → 15:15 | Lunch |
| **15:15 → 17:00** | **Mock: 2 unseen Tier-B problems, 40 min each, one at a time.** Before submitting, write 5 edge cases and run them. |
| **17:00 → 17:30** | Appendix A (debugging section). 20 minutes of reading saves you a lot of panic in a 60-minute section. |
| 17:30 → 19:00 | Light revision only: templates in section 7. No new problems. |
| **19:00 →** | Eat. Charger, webcam, stable internet, close other apps. Re-read section 8. |

## 7. Templates to have in your fingers
```cpp
// binary search on answer: smallest x with ok(x) true
while (lo < hi) { ll mid = lo + (hi - lo) / 2; if (ok(mid)) hi = mid; else lo = mid + 1; }

// nCr mod p (n up to 1e6)
fact[0]=1; for i: fact[i]=fact[i-1]*i%MOD;  inv[N]=power(fact[N],MOD-2); for i=N..1: inv[i-1]=inv[i]*i%MOD;
C(a,b) = fact[a]*inv[b]%MOD*inv[a-b]%MOD;

// prefix/suffix run lengths, frequency map + custom sort, priority_queue<ll>, Fenwick add/prefix
```

## 8. Exam tactics for the single DSA question
1. **Read the constraints first** and pick the complexity (n ≤ 1000 → O(n²) or O(maxA·n) is fine; n ≤ 10⁵ → O(n log n)).
2. **Re-derive every sample by hand** before coding. R1's sample hides the "leave a log unstored" rule; samples are where hidden rules live.
3. `long long` everywhere; `1LL *` before multiplying; take `% MOD` after **every** multiply; never compare values after taking mod.
4. If you're unsure, write a brute force first. Submitting a correct brute force beats submitting a wrong optimised solution, and it lets you check the fast one on the samples.
5. Edge cases to run before the final submit: n = 1, k = n, k > n, all zeros, all equal, all max values, empty string.
6. The platform is HackerRank-style: complete the given function; don't print debug output. C++20 is available.
7. If Section 1 has its own timer (your screenshot showed ~4 min left on S1), keep the last 5 minutes for re-running the samples.

---

## Appendix A: the debugging section in 15 minutes (optional)

**What the MovieDB watchlist repo's bugs actually were** (Amazon reuses these repos):
1. **Rate limiter not attached, or attached uncalled.** `rateLimiter` is a *factory* (`() => (req,res,next) => …`). Passing it uncalled means `next()` is never called, so **every test times out at 20 s**. Fix: `router.post('/add', watchlistRateLimiter(), addToWatchlist)` and the same for `/remove`.
2. **Limiter logic:** the filter kept *old* timestamps (`now - t >= windowMs`; it should be `< windowMs`); `if (requests)` is always truthy (it should be `if (valid.length >= 10)`); `windowMs` was undefined; the key was per-path, but add and remove share **one** limit (`${userId}-watchlist-operations`).
3. **`addToWatchlist` never wrote to the DB.** Add a `findOne` duplicate check, then `Watchlist.create({ user, movie })`.
   **The candidate's last failing test:** a duplicate must return **400** "Movie already in watchlist". They returned **404 without `return`**. Match the README's status codes and messages *exactly*, and always `return res.status(...)`.
4. **`removeFromWatchlist` never deleted.** Use `findOneAndDelete`; if it returns null, send 404 "Movie not found in watchlist".
5. **`checkWatchlistStatus` used `find`** (returns an array, always truthy). Use `findOne` and `!!`.
6. **`getWatchlist` used `Watchlist.findByUser(userId)`**; the version that passed uses `find({ user: userId }).populate('movie')` and drops null movies.

**Generic 60-minute loop:** run the tests first → read the README contract (routes, status codes, exact messages) → take **one** failing test → trace route → middleware → controller → model → make the smallest fix → re-run. Ask the AI assistant narrow questions ("trace POST /api/watchlist/add", "where is rateLimiter used?"). Don't paste its whole-file rewrites; reports say blind copying hurts. The README warns that unrelated bugs are planted; ignore them.

**Work style / SJT:** answer consistently. Customer impact first, take ownership, use data before deciding, disagree respectfully and then commit, escalate early when blocked. Avoid options that blame others or ignore the customer.

---

## Sources
- Your files: Amazon JNF (IIT Delhi), `Amazon_SDE_2026_OA.pdf`, two gallery PDFs (Sep 2026), IIITD intern notes (4 Jul 2026)
- codinzhub Amazon question list (on-campus tags and dates): https://www.codinzhub.com/company/amazon?tab=questions
- LeetCode Discuss, "Amazon has changed its OA pattern" (1 DSA + 1 development): https://leetcode.com/discuss/post/8345743/amazon-has-changed-its-online-assessment-mrht/
- LeetCode Discuss, Secure Maximum Deliveries (SDE-I intern OA): https://leetcode.com/discuss/post/8448738/amazon-sde-i-intern-oa-experience-questi-c3ww/
- aonecode, 2026 OA format (coding ~40 min, debugging ~60 min): https://aonecode.com/amazon-online-assessment-questions
- PracHub, Amazon AI-assisted coding OA guide 2026: https://prachub.com/resources/amazon-ai-assisted-coding-oa-guide-2026-repository-bugs-ai-prompts-and-hidden-tests
- techprep, Amazon SDE-1 2026 experience (AI task, 3/6 tests passed): https://www.techprep.app/community/interview-experiences/amazon-junior-software-engineer-interview-2026
- interviewfox, 2026 CoderPad questions: https://interviewfox.ai/interview-questions/amazon-coderpad/
- programhelp, 2026 summer SDE intern OA (security-level grouping): https://programhelp.net/en/oa/amazon-2026-summer-sde-oa/
- oavoservice, bug sorting + warehouse storage: https://oavoservice.com/en/articles/amazon-oa-bug-sorting-warehouse-storage
- TowardsAI, Amazon SDE-1 OA breakdown (median + MEX questions): https://pub.towardsai.net/amazon-sde-1-online-assessment-honest-breakdown-what-to-expect-e7abed75c122
- LeetCode Discuss, SDE-II OA Sep 2025: https://leetcode.com/discuss/post/7166079/amazon-sde-ii-oa-experience-sept-2025-2-8gxk4/
- LeetCode Discuss, SDE-1 OA Jan 2025 (Minimum Health): https://leetcode.com/discuss/interview-question/6273626/
- FastPrep, Minimum Merge Conflicts: https://www.fastprep.io/problems/amazon-minimum-merge-conflicts
- cswork.org Amazon OA index: https://cswork.org/oa/amazon
