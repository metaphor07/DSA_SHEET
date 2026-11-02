# IBM On-Campus OA — Pattern + Reconstructed Questions (C++)

Prepared 1 Nov 2026 for the IIT Delhi IBM drive. All C++ code is in `IBM_OA_solutions.cpp`. It compiles with `g++ -std=c++17`, and every sample below passes.

---

## 0. What IIT Delhi's JNFs actually say (read this first)

| | **Software Developer** | **Software Engineer — ISDL (Systems Lab)** |
|---|---|---|
| Online test | **120 min** | **90 min** |
| Syllabus | **Coding & Psychometric** | **Code** (Technical: Yes) |
| Then | Technical + HR interview | Technical + HR interview |
| CGPA / backlog | ≥ 7, none | ≥ 7, none |
| M.Tech TTM eligible | Yes | Yes |
| CTC | ₹22 LPA + ₹4L one-time + ₹10L staggered + $20K RSU | same |

> There is **no Data Scientist JNF** in what you sent. The second PDF is **Software Engineer (ISDL)**: C/C++, Linux, OS, firmware, AI-on-Z. Prepare for **SD + ISDL**.

**What to expect tomorrow:**
- **SD (120 min):** a HackerRank coding section (2–3 questions) **plus** a psychometric part. The psychometric part is either IBM's Cognify games or a learning-agility questionnaire.
- **ISDL (90 min):** HackerRank coding (2–4 questions), likely with **MCQs on OS / CN / DBMS / C-output / Linux commands**. Past ISDL campus tests always had these.

> **Real evidence for ISDL (your 2nd and 3rd zips).** Three **"IBM Systems"** HackerRank tests from 2024 are in the screenshots. IBM Systems is the ISDL lab, i.e. your Software Engineer role:
> - **10 Aug, Diversity T2:** 27 items, about 1 h 40 min
> - **24 Aug "P":** 23 items, about 1 h 40 min
> - **8 Sep "P1":** 10 items, about 1 h 30 min
>
> The 23–27-item tests are **mostly MCQs** (Linux commands, OS, C memory/preprocessor, networking, DSA basics, aptitude) **plus about 3 coding questions**. The 10-item test led with **3 coding questions**. See **Parts C and D**.

---

## 1. The pattern — what IBM is testing

Sources: the 8 real screenshots in your zip (4 different 2024 IBM India campus tests), plus 2025–26 candidate reports.

| Observation | Evidence |
|---|---|
| **Platform = HackerRank**, function-only template, `main()` locked | Every screenshot shows `hackerrank.com/test/...` |
| **2–3 questions in ~60 min** (59m timer visible) | BITS: 3 questions. IIIT-B and NIT Patna: 2 questions |
| **LeetCode Easy → Medium**, but **wordy story wrappers** | "video game segments", "encrypted files", "DemoKing multiverse" |
| **Hidden tests up to n = 10⁵** → O(n) or O(n log n) needed | Constraints 1 ≤ n ≤ 10⁵ in Q A1, A5, A6, A8 |
| Questions are **reused from HackerRank's library** | balancedOrNot, areAlmostEquivalent, email regex are known HackerRank problems |

**Topic frequency (zip + 2025-26 reports):**

1. **Arrays + prefix sum / sliding window** ★★★★★ — playSegments, getMaxValueSum, high-load timestamps, max-increase
2. **Strings + frequency counting / hashing** ★★★★ — areAlmostEquivalent, anagram, k-beauty
3. **Greedy counter / stack-like matching** ★★★ — balancedOrNot, non-overlapping intervals
4. **Simulation / math** ★★★ — clock hands, grid directions, logs
5. **Group-by with hashmap** ★★★ — min cost per item, log validity, login replacements
6. **Graph basics** ★★ — union-find connectivity, BFS jumps
7. **Regex** ★ — email validation (C++ `std::regex`)
8. **IBM Systems (ISDL) favourites** ★★★★ — **is_valid_bst without recursion (asked in 2 different tests)**, string/format conversion (IPv4→IPv6, binary addition), parsing "Name,Last,Age" records, Turán/graph math, Roads-and-Libraries union-find. They also ask **C templates in plain C** (`char**`, structs), so know C I/O.

**IBM's trick:** easy logic, long statement. Most marks are lost on **edge cases** (answer 0, n = 1, impossible → −1) and **overflow** (use `long long`).

---

## 2. Part A — actual questions from your zip (fully reconstructed)

### A1. Play Segments *(IBM HackerRank, July 2024)*
A game has `n` segments. `coins[i] = 1` means the segment has a coin (+1 point); `0` means no coin (−1 point). Player 1 plays the first `i` segments and Player 2 plays the rest. Return the **minimum `i`** such that Player 1's score is **strictly greater** than Player 2's.

- Signature: `int playSegments(vector<int> coins)`
- Constraints: `1 ≤ n ≤ 10⁵`, `coins[i] ∈ {0,1}`
- Example: `[1,1,0,1]` → **2**. (i=0: 0 vs 2; i=1: 1 vs 1; i=2: 2 vs 0.)
- Sample 0: `[1,0,0,1,0]` → **0**. (P1 = 0, P2 = 2 − 3 = −1.)
- **Note: `i = 0` is allowed.**

**Approach:** compute `total`, then sweep a prefix `p1`. Check `p1 > total − p1` before adding segment `i`. O(n).
```cpp
int playSegments(vector<int> coins){
    int n=coins.size(); long long total=0;
    for(int c:coins) total+=(c?1:-1);
    long long p1=0;
    for(int i=0;i<=n;i++){
        if(p1>total-p1) return i;
        if(i<n) p1+=(coins[i]?1:-1);
    }
    return n;
}
```

### A2. Minimum Jumps *(BITS Pilani, Aug 2024 — Q1 of 3, 60 min)*
You get a 0-indexed array `nums`. From index `i` you may jump **exactly `nums[i]` positions forward**, or move to **`i+1`**. Return the **minimum number of jumps** to reach the last index.

- Signature: `int minJumps(int nums_count, int* nums)` (the C template; the C++ version takes a vector)
- Constraints: `1 ≤ n ≤ 1000`, `0 ≤ nums[i] ≤ 1000`
- Example: `[3,0,0,1,0]` → **2** (0 → 3 → 4)

**Approach:** every edge goes forward, so a left-to-right DP is a BFS: `d[i+1]` and `d[i+nums[i]]` = `min(…, d[i]+1)`. O(n).
- ⚠️ If a jump overshoots the end, treat it as invalid. If hidden tests fail, try clamping it to `n−1`. A 1-line change is marked in the code.

### A3. Clock Hands — "Multiverse / DemoKing" *(BITS, Aug 2024 — Q2)*
You are stuck in a multiverse. You can leave only when the **minute hand overlaps the hour hand**. Given the current time `hh:mm`, print the **minimum minutes from now** until they overlap. The hour hand moves with every movement of the minute hand. There are **no seconds**.

- Input: one line `hh:mm`. Constraints: `00 ≤ hh ≤ 11`, `00 ≤ mm ≤ 59`.
- Example: `11:59` → **1** (they coincide at 12:00).

**Approach:** work in **half-degrees** so everything stays an integer. Minute hand = `12·m`; hour hand = `60·h + m`. Simulate `t = 0..720` minutes ahead and return the first `t` where both are equal mod 720.
- With whole minutes only, the hands meet only at 12:00. If the setter means continuous motion (overlaps every 720/11 min), use `clockOverlapContinuous` = ⌈next − now⌉. Both give 1 on the sample. **If a hidden test fails**, switch models: from `01:00`, the whole-minute model gives 660 and the continuous model gives 6.
- Parse the input with `scanf("%d:%d",&h,&m)`.

### A4. Number of Subints *(BITS, Aug 2024 — Q3)* = **LeetCode 2269 "K-Beauty"**
A *subint* of `m` is a contiguous substring (as a number) that **divides `m`**. Given `m` and `k`, count the subints of length `k`, **including duplicates**.

- Signature: `int numberOfSubint(int m, int k)`
- Examples: `(500,1)` → **1** ("5" divides; "0" does not). `(224,2)` → **0** ("22" and "24" don't divide).

**Approach:** `to_string(m)`, slide a window of length k, `stoll`, then **skip 0** (division by zero), and check `m % v == 0`. Leading zeros count ("02" = 2).

### A5. Encrypted Files — getMaxValueSum *(IIIT-Bangalore, Sep 2024 — Q1)*
`encrypted_file[n]` holds values, and `binary[n]` has 1 for already-decrypted files. The *value sum* is the sum of values where `binary = 1`. In **one** operation you may decrypt a **contiguous group of up to `k`** files (set their bits to 1). Return the **maximum value sum**.

- Constraints: `1 ≤ k ≤ n ≤ 10⁵`, `1 ≤ value ≤ 10⁴`
- Example: `[7,4,3,5]`, `[1,0,0,0]`, `k=2` → **15** (7 + 3 + 5)
- Sample 0: `[1,3,5,2,5,4]`, `[1,1,0,1,0,0]`, `k=3` → **16**

**Approach:** `base` = Σ values with bit 1. Then slide a **fixed window of size k** tracking Σ values with bit 0 inside it. Answer = `base + maxWindowGain`. Same idea as **LeetCode 1052 Grumpy Bookstore Owner**. Use `long long`.

### A6. Balanced Or Not *(IIIT-Bangalore, Sep 2024 — Q2)*
A string of `<` and `>` is **balanced** if each `<` appears before a matching `>`. Each symbol can be used in only one pair. You may replace any `>` with `<>`, up to `maxReplacements[i]` times. For each expression, return 1 if it can be balanced, else 0.

- Constraints: `1 ≤ n ≤ 10²`, `|expr| ≤ 10⁵`, `0 ≤ maxRep ≤ 10⁵`
- Example: `['<<>>','<>','<><>','>>','<<>','><><']`, `[0,1,2,2,2,2]` → **[1,1,1,1,0,0]**
- Sample 0: `['<>>>','<>>>>']`, `[2,2]` → **[1,0]**. Sample 2: `['<<<><><>']`, `[2]` → **[0]**.

**Approach:** scan with an `open` counter. For `<`, do `open++`. For `>`, do `open--` if `open > 0`, else `need++` (that `>` must become `<>`). Balanced ⇔ `open == 0 && need ≤ max`. A leftover `<` can **never** be fixed.

### A7. Regex — Valid HackerRank Email *(NIT Patna, Sep 2024 — Q1)*
Fill in the blank in `regex regularExpression("____");`. A valid email is `user@hackerrank.com`, where `user` is **1–6 lowercase letters**, then an **optional `_`**, then **0–4 optional digits**.

- Sample: `julia@` ✔, `julia_@` ✔, `julia_0@` ✔, `julia0_@` ✘ (digit before `_`), `julia@gmail.com` ✘
```cpp
regex regularExpression("^[a-z]{1,6}_?[0-9]{0,4}@hackerrank\\.com$");
```
- ⚠️ In a C++ string literal, the dot must be written `\\.`. Keep `^…$` in case the locked code uses `regex_search`.

### A8. Almost Equivalent Strings *(NIT Patna, Sep 2024 — Q2)* ≈ LeetCode 2068
Two strings are *almost equivalent* if they have the **same length** and, for every letter, the counts differ by **≤ 3**. Return "YES" or "NO" for each pair `(s[i], t[i])`.

- Constraints: `1 ≤ n ≤ 5`, `|string| ≤ 10⁵`
- Example: `s=['aabaab','aaaaabb']`, `t=['bbabbc','abb']` → **['YES','NO']** ('a' differs by 4 in pair 2)
- Sample: `'aaa'` vs `'aab'` → **YES**

**Approach:** use an `int f[26]`, `++` for s and `--` for t, then check every `|f| ≤ 3`. O(len).

---

## 3. Part B — reported 2025–26 IBM HackerRank questions

These are rebuilt from candidate summaries. Exact wording and constraints may differ, so read the real statement carefully. All are solved in the `.cpp` file.

| # | Problem (as reported) | Key idea |
|---|---|---|
| B1 | **High-load timestamps:** indices where `load[i] > 2 × average`, ascending (`n ≤ 2·10⁵`, `load ≤ 10⁹`). `[1,2,9]` → `[2]` | Integer compare: `load[i]*n > 2*total` (no floats, `long long`) |
| B2 | **Min total cost:** items `0..numItems−1`, pairs `(itemId, cost)`; pick the cheapest per item; −1 if an item has none. Example → 21 | Per-item min array |
| B3 | **Max non-overlapping intervals** `[start, end)` | Sort by **end**, greedy |
| B4 | **Max water-level increase / best profit:** max `a[j]−a[i]`, `i<j`, `a[i]<a[j]`, else −1 | Prefix minimum, O(n) |
| B5 | **Minimum link reassignments** to connect all repos (move an existing link) | If `edges < n−1` → −1; else `components − 1` (union-find) |
| B6 | **Login replacement counter:** 3 consecutive "error"s for the same id → +1, then reset | Hashmap of streaks; success resets |
| B7 | **Earliest time to reach target:** at second i, move `dir[i]` (E/W/N/S) or stay; −1 if never | Greedy: take a move only if it reduces \|dx\| or \|dy\| |
| B8 | **Invalid service-log groups:** group by sid, sort by time; must start `DOWN` and alternate | Map → sort → check |
| B9 | **Frequent IPs in a window:** IPs seen > k times within any t-second window | Per-IP timestamps + two pointers |
| B10 | **Anagram check + priority-queue question** (India on-campus SD, Sep 2025) | Freq count; `priority_queue` |

**Older IBM systems-lab campus OA** (5 coding + 21 MCQs on OS / CN / OOP / microprocessors / digital design):
- **Bus routes:** `a×b` city; each route covers row r, columns [s, e]; count cells with no bus. Merge intervals per row (in the `.cpp`, `freeCells`).
- GCD of an array (return −1 if it is 1)
- Palindrome by concatenating a substring of `a` and a substring of `b`
- Remove the n-th node from the end of a linked list

---

## 3C. Part C — IBM Systems (ISDL) coding questions *(your 2nd and 3rd zips)*

All are solved and tested in the `.cpp` (sections C1–C9).

### C1. Valid BST — **iterative only** *(IBM Systems 8 Sep **and** 24 Aug: asked twice)*
Given a binary tree, determine whether it is a BST: left subtree < node < right subtree, recursively. **DO NOT USE RECURSION.**
- Signature: `bool is_valid_bst(vector<string> root)` (C: `int root_count, char** root`)
- Input: level order, `"null"` for missing. Sample stdin: `3` / `2` / `1` / `3` → tree [2,1,3] → **true**
- **Approach:** build the tree with a **queue**. Then do an **iterative in-order traversal with a stack**: each value must be **strictly greater** than the previous one (duplicates → false). O(n).

### C2. Sort Triangles by Area *(IBM Systems 8 Sep — written in C)* = HackerRank "Small Triangles, Large Triangles"
Given `n` triangles (a, b, c), print them sorted by area, smallest first. All areas are distinct. Heron's formula: `S = √(p(p−a)(p−b)(p−c))`, `p = (a+b+c)/2`.
- Constraints: `n ≤ 100`, `1 ≤ a,b,c ≤ 70`. Sample: `7 24 25 / 5 12 13 / 3 4 5` → `3 4 5 / 5 12 13 / 7 24 25` (areas 6, 30, 84)
- **Approach:** avoid `sqrt` and floats. Compare `16S² = (a+b+c)(−a+b+c)(a−b+c)(a+b−c)` as integers. In C, use `qsort` with that comparator.

### C3. IPv4 → IPv6 *(IBM Systems 8 Sep)*
Convert each octet to 2-digit **uppercase** hex. Pair octets 1+2 and 3+4 and print `::FFFF:XXXX:XXXX`. Any `127.x.x.x` is loopback → print `::1`.
- Sample: `192.168.10.92` → `::FFFF:C0A8:0A5C`
- **Approach:** `sscanf("%d.%d.%d.%d")`, then `printf("::FFFF:%02X%02X:%02X%02X\n", …)`. ⚠️ Lowercase fails the tests. Keep the zero padding (`0A`, not `A`).

### C4. Binary Addition *(IBM Systems 24 Aug)*
`string binAddition(string str1, string str2)`. Samples: `100 + 010 = 110`, `111 + 11 = 1010`. Length ≤ 1000, so you **can't convert to int**.
- **Approach:** add right-to-left with a carry, reverse, and strip leading zeros (keep `"0"`).

### C5. Youngest Missing Member *(IBM Systems 24 Aug — 2 variants)*
`ages[]` holds the ages present. `members[]` = `"Name,LastName,Age"`. Return the **first name** of the youngest member whose age is **not** in `ages[]`. Return `null` if every age is present. `ages` may be unsorted. On ties, return the first occurrence.
- Sample: ages `{1,2,3,4,5}`, members `Ram,D,1 … Leena,Jack,7, Patric,Queen,8 … Dilip,K,22` → **Leena**
- **Approach:** hash set of ages, then one pass parsing each record (split on `,`, take the last field as age). Strip quotes and spaces.

### C6. minFriends — Turán's theorem *(IBM Systems 24 Aug variant)* = HackerRank "Clique"
Given `n` people and `m` relationships (edges), find the **minimum possible size of the largest fully-connected group** (clique).
- Samples: `(2,1)` → 2, `(3,2)` → 2, `(5,7)` → 3. Constraints: `n ≤ 10⁴`, `m ≤ n(n−1)/2`.
- **Approach:** the most edges a graph can have with no (k+1)-clique is the Turán graph (k nearly-equal parts): `T(n,k) = (n² − Σ partSize²)/2`. Answer = **smallest k with T(n,k) ≥ m**. Binary search on k, using `long long`. I checked this exhaustively against every graph with up to 6 nodes.

### C7. Minimum Size Subarray Sum *(IBM Systems 24 Aug variant)* = LeetCode 209
Smallest-length contiguous subarray with sum ≥ target, or 0. `target=4, [1,4,4]` → 1; `target=11, [1×8]` → 0. **Approach:** two-pointer sliding window, O(n).

### C8. Last Animal Name Length *(IBM Systems 24 Aug variant)* ≈ LeetCode 58
Names are separated by `-`. Return the length of the last name, ignoring leading and trailing `-`. **Approach:** skip trailing `-` from the end, then count characters until the next `-`.

### C9. Enable a New Service in All Clusters *(IBM Systems 10 Aug Diversity, Q24)* = HackerRank "Roads and Libraries"
There are `n` clusters. You can host the service in a cluster (`c_service`) or link two clusters (`c_link`, only between the listed pairs). Every cluster must reach a host. Find the minimum cost.
- Example: n=5, pairs (1,2),(1,3),(3,2),(4,5), host=3, link=1 → **9** = (3+1+1) + (3+1)
- **Approach:** if `c_link ≥ c_service`, answer = `n·c_service`. Otherwise use union-find to count components `k`: answer = `k·c_service + (n−k)·c_link`. Use `long long`.
- ⚠️ The screen's format line says `n m c_link c_service`, but the example input `5 4 3 1` has **service = 3, link = 1**. **Check the order in Custom Input** before trusting the format line.

---

## 3D. Part D — MCQs from the IBM Systems tests (with answers)

I verified the code-based ones by running them (fork, Java recursion, base conversion, sets).

| # | Question (short) | Answer | Why |
|---|---|---|---|
| 1 | Kernel panic is most likely from…? | **Inserting a corrupt kernel module that conflicts with the kernel version** | Faults in kernel space panic. User-space faults just kill the process. |
| 2 | Copy `myapp.log` (root-only) to a remote server via SSH; admin has sudo | **`sudo -u root scp /path/to/myapp.log ubuntu@10.0.1.34:/remote-dir/my-location/`** | scp must run as root to read the file. *(Low confidence: option 1, `sudo scp -i /root/.ssh/id_rsa …`, also runs as root and differs only by naming root's key. Options 3–4 change ownership needlessly or target `remove-dir`.)* |
| 3 | Which TCP statement is FALSE? (A: 3 packets to open, B: receiver's reply has SYN+ACK set, C: 4 packets to close) | **None of these** | All three are true for the standard handshake and teardown |
| 4 | Circular linked list can implement… | **Both** stack and queue | — |
| 5 | Which macro statement is correct? | **"Once preprocessing is over… macros are removed from the expanded source"** | Macros aren't required to be uppercase, have no scope, and involve no control transfer |
| 6 | Data structure for key→value dictionary | **Hash Table** | — |
| 7 | Time complexity of linear search | **O(n)** | — |
| 8 | List the last 3 commands **with history IDs**, excluding itself | **`fc -l -3`** | `-n` would hide the numbers; `history -c` clears history |
| 9 | Java `fun(2,10)` (fast power) | **Strictly "None of these"** | The signature is `fun(int x, int y)` but the body uses `n`, so it doesn't compile (I compiled it). If the parameter were `n`, the answer would be 2¹⁰ = **1024**. Read the signature carefully. |
| 10 | `R(a) = R(a−1) + 1/a`, complexity of R(n) | **O(log n)** | Harmonic series ≈ ln n *(the intended answer; computing it takes O(n) steps)* |
| 11 | `malloc()` allocates memory at… | **Execution time on heap** | — |
| 12 | RAM section shared by a process and its threads | **Heap** | Each thread has its own stack. Code and data are shared too, but Heap is the intended answer. |
| 13 | Default env variables file for bash | **`/etc/profile.d`** (best of the given options) | `/etc/profile` (not listed) sources it; `~/.profile` is per-user *(medium confidence)* |
| 14 | Virtual memory is… | **Secondary storage used as an extension of RAM** | — |
| 15 | Max keys in a B-tree of order 6, height 4 | **7775** | 5 levels (height 0–4) × up to 5 keys per node = 6⁵ − 1 |
| 16 | OS responsibilities (multi-select) | **Process mgmt, Memory mgmt, Security** | Performance is a goal, not a duty *(medium confidence)* |
| 17 | POSIX mutex held by a non-preemptible thread; a real-time thread needs it | **Use the priority-inheritance protocol** | This is the standard fix for priority inversion |
| 18 | Two threads modify a global inside the same function | **Final value is unpredictable** | Race condition: stacks are separate, globals are shared |
| 19 | `static int a; static int b=10; int c;` (local) → where stored? | **BSS, Data, Stack** | Uninitialised static → BSS; initialised → Data; local → stack |
| 20 | HR 26, Tech 32, Mgmt 30; 5 in all three; 37 in exactly one. Exactly two? | **18** | 88 = 37 + 2x + 3·5 → x = 18 |
| 21 | Discount 15%, increased by 15% for > 3 items; buy 12 | **30** | 15 + 15 percentage points (17.25 isn't an option) |
| 22 | Fastest memory-allocation technique | **First Fit** | It stops at the first hole that fits |
| 23 | Infinite recursion causes… (multi) | **Stack overflow + Segmentation fault** | — |
| 24 | Preprocessing stage in C (multi) | **Macros, Conditional compilation, Include guards** | Function calls happen at run time |
| 25 | `printf("Hello"); fork(); printf("Hello");` | **4** | No `\n`, so the unflushed "Hello" buffer is copied into the child (verified by running) |
| 26 | (1101)₂ = (y)₃ | **111** | 13 = 9 + 3 + 1 |

---

## 3E. Part E — MathWorks test that got mixed into the diversity folder (practice only)

Test `b9t79o2rsd1` shows a **"MathWorks | NIT Warangal"** banner (44 questions, 22 Aug 2024). Its JavaScript MCQs and these 4 coding questions are not IBM's, but they are good medium practice. Solved and stress-tested in the `.cpp` (E1–E4).

| # | Problem | Key idea |
|---|---|---|
| E1 | **Ball Collision:** balls on a line move L/R; on a collision the stronger survives (equal → both die). Return the surviving indices. `[1,−1],[2,1]` → `[0]`; `[1,−1,1],[5,3,1]` → `[0,2]` | **LeetCode 735 Asteroid Collision** with a stack of indices |
| E2 | **Dominoes Painting:** 2×N board of dominoes, 3 colours, neighbours must differ, mod 1e9+7. `baa/bcc` → 6, `aacx/ddcx` → 12 | **AtCoder ABC071 D**: first vertical = 3, first horizontal pair = 6; V→V ×2, V→H ×2, H→V ×1, H→H ×3 |
| E3 | **Minimum Complexity Level:** split lectures (in order) into `days` groups; minimise Σ max per day. `[30,10,40,20,50]`, 2 → 80 | **LeetCode 1335** DP, O(n²·d), n ≤ 300 |
| E4 | **Shader Loader:** "a"/"b" string; ≤ k flips; minimise the longest same-char run. `aabbbaaaa`, 2 → 2; `aaaaa`, 1 → 2 | Binary search L: for L ≥ 2, cost = Σ ⌊run/(L+1)⌋; L = 1 → compare with an alternating pattern |

---

## 4. ISDL MCQ quick revision (30 min tonight)

> Do **Part D** first: those are real IBM Systems MCQs, and the same bank tends to repeat.

- **C output traps:** `i++ + ++i` is undefined behaviour. Watch `sizeof` on arrays vs pointers, `static` locals, integer promotion (`char` → `int`), unsigned wrap-around, `printf("%d", 'A')`, operator precedence (`*p++`), and string-literal modification.
- **OS:** process vs thread, paging (page-table size, effective access time), TLB, FCFS/SJF/RR waiting time, deadlock (4 conditions, Banker's), semaphores/mutex, `fork()` count (`2ⁿ`), thrashing, virtual memory, little vs big endian (in the ISDL JD!).
- **Linux commands:** `chmod 755`, `grep -r`, `find -name`, `ps`/`top`/`kill -9`, `ls -l` fields, pipes, `>` vs `>>`, `ln -s`, `df`/`du`.
- **CN:** OSI/TCP-IP layers, TCP vs UDP, subnetting (hosts = 2ʰ−2), ARP/DNS/DHCP, port numbers (22, 53, 80, 443).
- **DBMS:** keys, normal forms, joins, `GROUP BY … HAVING`, ACID.
- **Bit manipulation:** `x & (x−1)`, popcount, check the k-th bit, power of 2. One 2024 ISDL coding question was bit-based.

## 5. Psychometric (SD, 120-min test)

- **IBM Cognify games**, each with a practice round: *Shortcuts* (move the marble to the star in the fewest moves), *Gridlock*, *Resemble* (rotated or mirrored shapes), *Numbubbles* (pop bubbles summing to a target), *Tally Up* (pick the higher-value token group), *Proof It* (find text errors). Speed and accuracy both count. Do 1 practice round of each tonight (PrepInsta has free versions).
- **Learning-agility questionnaire:** answer **honestly and consistently**. The same trait is asked several ways, and inconsistency gets filtered out.

## 6. Exam-day HackerRank checklist

1. Read the whole statement and the **sample explanation** before coding. IBM statements hide the key rule there (e.g., "0 segments allowed").
2. Look at the constraints. If n is 10⁵, use O(n) or O(n log n). Use **`long long`** for any sum.
3. Code only inside the function. Don't edit the locked `main()`.
4. Before submitting, test in **Custom Input**: n = 1, all zeros, the impossible case (−1/0), and the max value.
5. Partial credit counts, so **submit the brute force first**, then optimise.
6. Spend at most 25 min on a question, then move on and come back.

---

### Sources
- Your zip: 36 screenshots from 4 IBM India HackerRank campus tests (Jul–Sep 2024)
- Your "IBM girls" zip: 7 screenshots, IBM Systems 8 Sep 2024 P1 (10 items)
- Your "IBM Diversity Hiring Pool" zip: 98 screenshots. IBM Systems 10 Aug Diversity T2 (27 items) and 24 Aug P (23 items), plus a MathWorks test (b9t79o2rsd1) mixed in
- Bash startup files (for MCQ 13): [Startup scripts](https://bash.cyberciti.biz/guide/Startup_scripts)
- IIT Delhi JNFs: IBM India Software Developer and Software Engineer (ISDL)
- GfG: [IBM India SDE on-campus, Sep 2025](https://www.geeksforgeeks.org/interview-experiences/ibm-india-interview-experience-for-software-developer-on-campus/) · [ISDL on-campus 2022](https://www.geeksforgeeks.org/interview-experiences/ibm-interview-experience-for-isdl-on-campus-2022/) · [ISDL experience](https://www.geeksforgeeks.org/ibm-isdl-interview-experience-2/)
- [IBM ISDL 2023 (Medium)](https://sudarshan-s.medium.com/ibm-isdl-software-engineer-interview-a-tale-of-challenges-resilience-and-learning-9dd22355e7bb) · [IBM ISL on-campus Oct 2023 (LeetCode)](https://leetcode.com/discuss/interview-experience/4213362/)
- [IBM OA on-campus 5 questions (LeetCode)](https://leetcode.com/discuss/interview-question/3741653/IBM-Online-Assessment-Questions-or-On-Campus/)
- [High-load / union-find debrief](https://oavoservice.com/en/articles/ibm-oa-hackerrank-high-load-union-find) · [2026 IBM HackerRank reports](https://www.linkjob.ai/interview-questions/ibm-hackerrank-test/) · [IBM high-frequency questions](https://dev.to/interviewshow-cs/ibm-oa-high-frequency-questions-sharing-how-to-pass-ibm-oa-efficiently-7po) · [2026 NG SDE OA](https://dev.to/net_programhelp_e160eef28/ibm-oa-experience-2026-ng-sde-2-coding-questions-full-ac-1h07)
- [IBM 2025-26 test pattern (FACE Prep)](https://faceprep.in/article/ibm-test-pattern-for-ibm-online-written-test-2018-face-prep/)
