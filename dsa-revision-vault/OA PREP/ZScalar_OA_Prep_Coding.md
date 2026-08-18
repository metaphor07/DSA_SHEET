# ZScalar — Online Assessment Prep
*Coding / DSA Section — Reconstructed from your OA screenshots*

> **Note:** This folder had 3 distinct coding questions. Two are fully reconstructed and verified against known sample outputs. The third ("Drop-off Centers") is missing key data in your screenshot (edge weights and the expected output for the example) — I've given you the correct general algorithm, but flagged clearly where I couldn't verify a worked example. If you can get a cleaner/complete screenshot of that one, send it and I'll finish it properly.

---

## Question 1: Balancing Elements

### Problem Statement
*(From screenshot)*

When an element is deleted from an array, the higher-indexed elements shift down one index to fill the gap. A **"balancing element"** is defined as an element that, when deleted from the array, results in the sum of the even-indexed elements being equal to the sum of the odd-indexed elements. Determine how many balancing elements a given array contains.

### Function Description
Complete the function `countBalancingElements`.
- `arr[n]` — an integer array of size `n`
- Returns: `int` — the number of balancing elements

### Sample Case (from screenshot)
```
n = 5
arr = [5, 5, 2, 5, 8]
```
When the first or second `5` is deleted, the array becomes `[5, 2, 5, 8]`. `sum[even] = 5+5 = 10` and `sum[odd] = 2+8 = 10`. No other elements have this property.

**Output: `2`** (`arr[0]` and `arr[1]` are balancing elements)

### Approach (Mentor Notes)
The key trick: when you delete index `i`, everything **after** `i` shifts left by one, which **flips the parity** of every index after `i` (even becomes odd, odd becomes even). Everything **before** `i` keeps its original parity.

So if you split the array into "before `i`" and "after `i`":
- New even-sum = (sum of even-indexed elements before `i`) + (sum of **odd**-indexed elements after `i`)
- New odd-sum = (sum of odd-indexed elements before `i`) + (sum of **even**-indexed elements after `i`)

`i` is a balancing element exactly when these two are equal.

- Precompute prefix sums `preEven[i]`, `preOdd[i]` (sums up to but not including `i`) and suffix sums `sufEven[i]`, `sufOdd[i]` (sums after `i`) in two linear passes.
- Then for each `i`, check the condition in `O(1)`.
- **Complexity:** `O(n)` time, `O(n)` space (can be reduced to `O(1)` extra space by only tracking suffix sums and updating a running prefix, but the two-array version is clearer to write under time pressure).

### Reference Solution (C++)
```cpp
int countBalancingElements(vector<int>& arr) {
    int n = arr.size();
    vector<long long> preE(n+1, 0), preO(n+1, 0);
    for (int i = 0; i < n; i++) {
        preE[i+1] = preE[i] + (i % 2 == 0 ? arr[i] : 0);
        preO[i+1] = preO[i] + (i % 2 == 1 ? arr[i] : 0);
    }
    vector<long long> sufE(n+1, 0), sufO(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        sufE[i] = sufE[i+1] + (i % 2 == 0 ? arr[i] : 0);
        sufO[i] = sufO[i+1] + (i % 2 == 1 ? arr[i] : 0);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        long long newEven = preE[i] + sufO[i+1];
        long long newOdd  = preO[i] + sufE[i+1];
        if (newEven == newOdd) count++;
    }
    return count;
}
```
*Verified: `countBalancingElements([5,5,2,5,8])` → `2`, matching your OA's sample exactly.*

### Test Cases to Practice With

| Input | Expected Output | Source |
|---|---|---|
| `arr=[5,5,2,5,8]` | `2` | From screenshot |
| `arr=[1,1,1,1]` | `0` | Added — odd-length remainders (3 elements) can never split evenly unless values are 0 |
| `arr=[1,2,3]` | `0` | Added — small array, no removal balances |
| `arr=[0,0,0,0,0]` | `5` | Added — degenerate case, every removal trivially balances (all sums are 0) |

*All outputs above were computed and verified using the prefix/suffix approach — not guesses.*

### Equivalent Question (for cross-reference)
Exact match: **[GeeksforGeeks — Count Indices to Balance Even and Odd Sums](https://www.geeksforgeeks.org/problems/count-indices-to-balance-even-and-odd-sums/1)** (also indexed under the title "Equal Odd-Even Sum After Removal"). Same problem, same prefix/suffix technique — solve it there for judged practice. This one isn't on LeetCode under an identical name.

---

## Question 2: Encircular (doesCircleExist)

### Problem Statement
*(From screenshot)*

Build a computer simulation of a mobile robot. The robot moves on an infinite plane, starting from position `(0, 0)`. Its movements are described by a command string consisting of one or more of the following three letters:
- `G` instructs the robot to move forward one step.
- `L` instructs the robot to turn left in place.
- `R` instructs the robot to turn right in place.

The robot performs the instructions in a command sequence in an infinite loop. Determine whether there exists some circle such that the robot always moves within the circle.

### Function Description
Complete the function `doesCircleExist`. It returns an array of `n` strings, either `YES` or `NO`, based on whether the robot is bound within a circle or not, in order of test results.
- `commands[commands[0],...,commands[n-1]]` — an array of `n` command strings to test

### Constraints
*(From screenshot)*
- `1 ≤ |commands[i]| ≤ 2500`
- `1 ≤ n ≤ 10`
- Each command consists of `G`, `L`, and `R` only

### Sample Case (from screenshot)
```
commands = ["G", "L", "RGRG"]
```
- `"G"`: robot moves forward forever without turning → not bounded → `NO`
- `"L"`: robot just turns in place forever, trapped at one spot → bounded → `YES`
- `"RGRG"`: repeating this traces a closed circular path → bounded → `YES`

**Output: `["NO", "YES", "YES"]`**

### Approach (Mentor Notes)
This is a direct match for a well-known problem (see cross-reference below) — the reasoning generalizes cleanly:

- Simulate **one pass** of the command string, tracking position `(x, y)` and facing direction (as a unit vector, starting north = `(0, 1)`).
  - `G`: move `(x, y) += (dx, dy)`
  - `L`: rotate direction 90° counter-clockwise: `(dx, dy) → (-dy, dx)`
  - `R`: rotate direction 90° clockwise: `(dx, dy) → (dy, -dx)`
- After one pass, the robot is bounded in a circle if **either**:
  1. It's back at the origin `(0, 0)` — repeating the same instructions just retraces the same closed loop forever, **or**
  2. It's **not** facing north anymore — because the displacement vector will then rotate on each repeated cycle, and after at most 4 cycles (for 90° turns) the movements cancel out and the robot returns near the origin, tracing a bounded rosette pattern.
- If it's still facing north **and** hasn't returned to origin, it's walking in a straight line forever → unbounded.
- **Complexity:** `O(total length of all command strings)` — one linear pass per test case.

### Reference Solution (C++)
```cpp
vector<string> doesCircleExist(vector<string>& commands) {
    vector<string> results;
    for (auto& cmd : commands) {
        int x = 0, y = 0, dx = 0, dy = 1; // facing north
        for (char ch : cmd) {
            if (ch == 'G') { x += dx; y += dy; }
            else if (ch == 'L') { int ndx = -dy, ndy = dx; dx = ndx; dy = ndy; }
            else if (ch == 'R') { int ndx = dy, ndy = -dx; dx = ndx; dy = ndy; }
        }
        bool bounded = (x == 0 && y == 0) || !(dx == 0 && dy == 1);
        results.push_back(bounded ? "YES" : "NO");
    }
    return results;
}
```
*Verified against your OA's sample: `["G","L","RGRG"]` → `["NO","YES","YES"]`. Also verified against 3 official LeetCode examples (`"GGLLGG"→YES`, `"GG"→NO`, `"GL"→YES`).*

### Test Cases to Practice With

| Input | Expected Output | Source |
|---|---|---|
| `["G", "L", "RGRG"]` | `["NO", "YES", "YES"]` | From screenshot |
| `["GGLLGG"]` | `["YES"]` | Added — from LeetCode's official examples |
| `["GG"]` | `["NO"]` | Added — from LeetCode's official examples |
| `["GL"]` | `["YES"]` | Added — from LeetCode's official examples |

### Equivalent Question (for cross-reference)
Exact match: **[LeetCode 1041: Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/)** (Difficulty: Medium). Same core logic, single test case there instead of a batch — solve it directly for judged practice.

---

## Question 3: Drop-off Centers ⚠️ *Incomplete — needs a better screenshot*

### Problem Statement
*(From screenshot)*

An e-commerce company wants to contract with local businesses to use their stores as pick-up and drop-off centers for their packages. To reduce expenses, they want to ensure that their drop-off centers are a minimum distance apart from each other.

A city has many potential drop-off centers, represented as nodes on a weighted, undirected graph. The edges denote roads connecting these centers, with weights representing road lengths. Determine how many unique subsets of companies can be contracted that satisfy this requirement. Locations owned by the same local business must also meet the minimum-distance requirement. If they contract with a company, they get a drop-off center at every location that company owns.

**What's missing from the screenshot:** the example shows `graph nodes=3`, `graph from=[1,2,3]`, `graph to=[2,3,1]`, `minDistance=4`, `companies=[1,2,3]` — but the **edge weights array** and the **expected output value** for this example are cut off. Without those, I can't verify a solution against a real answer, so I'm not going to fabricate a "verified" test case here.

### General Approach (unverified — logic only)
This is a graph + subset-counting problem. The standard technique for this shape of problem:
1. Run **Floyd-Warshall** (or run Dijkstra from every node) to get all-pairs shortest path distances between every drop-off location — fine since these problems are always small-scale (`n` likely ≤ ~15–20 given it needs subset enumeration).
2. Build a **conflict graph over companies** (not locations): two companies conflict if *any* location owned by one is closer than `minDistance` to *any* location owned by the other. A company also "self-conflicts" (can never be validly included) if two of its own locations are closer than `minDistance` apart.
3. The answer is the number of subsets of companies where **no two companies in the subset conflict** — i.e., counting independent sets in the conflict graph.
4. With a small number of companies, this is a straightforward `O(2^m · m)` bitmask enumeration: for every subset, check pairwise non-conflict using the precomputed conflict graph.

**I'd recommend getting a full, clean screenshot of this question (the edge weights and expected output specifically) before you rely on this one for prep** — I don't want you memorizing an approach I couldn't actually confirm against a real answer.

---

## What Else Was in This Folder

- `zscaler.docx` — 18MB file, likely contains more content but too large to process reliably in this pass. Let me know if you want me to dig into it separately.
- `IMG_20241116_203746_459.jpg`, `IMG-20241116-WA0017.jpg`, `IMG-20241116-WA0032.jpg` — some of these were duplicates/partial views of the questions above; no additional distinct questions found beyond the 3 covered.
